#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utils.h"
#include "estado_compilador.h"
#include "general.h"
#include "pila.h"
#include "cola.h"

#define MAX_BUFFER 1024

void sent_agregar(estado_compilador_t* estado, char* tipo, int linea, int columna) {
    if (!estado) {
        fprintf(stderr, "ERROR INTERNO: estado es NULL en sent_agregar\n");
        exit(EXIT_FAILURE);
    }
    
    int indice_nuevo = estado->indice_sentencias + 1;
    
    estado->lista_sentencias = reallocSeguro(
        estado->lista_sentencias,
        sizeof(TipoSentencias) * indice_nuevo,
        "sentencias"
    );
    
    int idx = estado->indice_sentencias;
    estado->lista_sentencias[idx].tipo = duplicarCadena(tipo);
    estado->lista_sentencias[idx].linea = linea;
    estado->lista_sentencias[idx].columna = columna;
    
    estado->indice_sentencias++;

}

void func_agregar(char* nombreFuncion, char* tipoQueRetorna, Clase clase, int linea, int columna) {
    
    if (!nombreFuncion || ! tipoQueRetorna) {
        printf("ERROR: Fallo de parametros en func_agregar\n");
        exit(EXIT_FAILURE);
    }

    // Se encarga de insertar la función en la tabla, si corresponde
    if (ts_validarInsercionSimbolo(nombreFuncion, tipoQueRetorna, clase, linea, columna) == 0)
        return;

    Simbolo* simbolo = ts_buscarSimbolo(nombreFuncion);

    // Cargar función en el estado global (para imprimir en el reporte)
    int indice_nuevo = estado_global->indice_funciones + 1;
    
    estado_global->lista_funciones = reallocSeguro(
        estado_global->lista_funciones,
        sizeof(TipoFuncionesDeclaradasODefinidas) * indice_nuevo,
        "funciones"
    );

    int idx = estado_global->indice_funciones;
    estado_global->lista_funciones[idx].nombreFuncion = duplicarCadena(nombreFuncion);
    estado_global->lista_funciones[idx].tipoQueRetorna = duplicarCadena(tipoQueRetorna);
    estado_global->lista_funciones[idx].linea = linea;
    
    if (clase == FUNCION_DEC)
        estado_global->lista_funciones[idx].tipoInicializacion = duplicarCadena("declaracion");
    else
        estado_global->lista_funciones[idx].tipoInicializacion = duplicarCadena("definicion");
    
    char* listaParametros = armarListaParametros(&simbolo->parametros);
    estado_global->lista_funciones[idx].parametrosRecibidos = listaParametros;
    estado_global->indice_funciones++;
}

// Construye un string con los parámetros completos (ej. "int x, double num")
char* armarListaParametros(const Cola* cola) {
    if (!cola) {
        printf("ERROR: Fallo de parametros en armarListaParametros\n");
        exit(EXIT_FAILURE);
    }

    char* resultado = malloc(MAX_BUFFER);
    if (!resultado) {
        printf("ERROR: Fallo al reservar memoria para el resultado en armarTipoParametros\n");
        exit(EXIT_FAILURE);
    }
    strcpy(resultado, "");

    for (NodoCola* aux = cola->inicio; aux; aux = aux->siguiente) {
        if (aux->tipo)
            strcat(resultado, aux->tipo);
        else
            printf("Tipo NULL en armarListaParametros, por TIPO nulo\n"); //Protección contra segmentation fault (SACAR)

        if (aux->nombre) {
            strcat(resultado, " ");
            strcat(resultado, aux->nombre);
        }
        
        if(aux->siguiente)
            strcat(resultado, ", ");
    }

    if (strlen(resultado) == 0)
        strcpy(resultado, "void");

    return resultado;   //Luego se debe liberar memoria
}

void func_imprimir(estado_compilador_t* estado) {
    printf("* Listado de funciones declaradas y definidas:\n");
    
    if (estado->lista_funciones == NULL || estado->indice_funciones == 0) {
        printf("-\n\n");
        return;
    }
    
    for (int i = 0; i < estado->indice_funciones; i++) {
        printf("%s: %s, input: %s, retorna: %s, linea %d\n",
               estado->lista_funciones[i].nombreFuncion,
               estado->lista_funciones[i].tipoInicializacion,
               estado->lista_funciones[i].parametrosRecibidos,
               estado->lista_funciones[i].tipoQueRetorna,
               estado->lista_funciones[i].linea);
    }
    printf("\n");
}

// Si la invocación de la función es válida devuelve su tipo de retorno, caso contrario devuelve "unknown"
char* func_verificarInvocacion(char* nombreFuncion, int linea, int columna) {
    
    if (!nombreFuncion) {
        printf("ERROR: Fallo de parametros en func_verificarInvocacion\n");
        exit(EXIT_FAILURE);
    }

    Simbolo* aux = ts_buscarSimbolo(nombreFuncion);
    int flag = 1;   // Comenzamos suponiendo que no hay error (puede variar más adelante)

    char* mensaje = malloc(MAX_BUFFER);
    char* nota = malloc(MAX_BUFFER); 
    if (!mensaje || !nota) {
        printf("ERROR: No se pudo alojar mensaje o nota\n");
        exit(EXIT_FAILURE);
    }

    if (aux->clase == NO_ENCONTRADO) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: Funcion '%s' sin declarar", linea, columna, nombreFuncion);
        err_agregarSemantico(estado_global, mensaje, linea, columna, NULL);
        liberarSimboloEspecial(aux);
        flag = 0;
        goto clean;
    }

    // Verificar si es una función
    if (aux->clase != FUNCION_DEC && aux->clase != FUNCION_DEF) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: El objeto invocado '%s' no es una funcion o un puntero a una funcion", linea, columna, nombreFuncion);
        snprintf(nota, MAX_BUFFER, "Nota: declarado aqui: %d:%d", aux->linea, aux->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        flag = 0;
        goto clean;
    }

    NodoCola parametroDesencolado;
    int contador = 0;
    NodoCola* parametroActualTS = aux->parametros.inicio;

    while (parametroActualTS && colaParametrosInvocacion.inicio) {
        parametroDesencolado = desencolar(&colaParametrosInvocacion);
        contador++;

        if (tiposCompatibles(parametroActualTS->tipo, parametroDesencolado.tipo) == 0) {
            snprintf(mensaje, MAX_BUFFER, "%d:%d: Incompatibilidad de tipos para el argumento %d de '%s'", linea, parametroDesencolado.columna, 
                contador, nombreFuncion);
            snprintf(nota, MAX_BUFFER, "Nota: se esperaba '%s' pero el argumento es de tipo '%s': %d:%d", 
                     parametroActualTS->tipo, parametroDesencolado.tipo, aux->linea, parametroActualTS->columna);
            err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
            flag = 0;
        }

        if (parametroDesencolado.tipo) free(parametroDesencolado.tipo);
        if (parametroDesencolado.nombre) free(parametroDesencolado.nombre);
        parametroActualTS = parametroActualTS->siguiente;
    }

    if (colaParametrosInvocacion.inicio) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: Demasiados argumentos para la funcion '%s'", linea, columna, nombreFuncion);
        snprintf(nota, MAX_BUFFER, "Nota: declarado aqui: %d:%d", aux->linea, aux->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        flag = 0;
        goto clean;
    }

    if (parametroActualTS) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: Insuficientes argumentos para la funcion '%s'", linea, columna, nombreFuncion);
        snprintf(nota, MAX_BUFFER, "Nota: declarado aqui: %d:%d", aux->linea, aux->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        flag = 0;
        goto clean;
    }

    clean:
    free(mensaje);
    free(nota);
    // Se vacía para prevenir que los parámetros actuales se mezclen con futuras invocaciones
    vaciarCola(&colaParametrosInvocacion);

    if (aux && flag) {
        char* copia = guardarCadena(aux->tipo);
        return copia;
    }
    else
        return guardarCadena("unknown");
}