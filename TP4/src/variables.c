#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "variables.h"
#include "estado_compilador.h"
#include "general.h"
#include "utils.h"
#include "pila.h"

#define MAX_BUFFER 512

static int compararPorLinea(const void *a, const void *b) {
    TipoVariablesDeclaradas* v1 = (TipoVariablesDeclaradas*)a;
    TipoVariablesDeclaradas* v2 = (TipoVariablesDeclaradas*)b;
    
    if (v1->linea != v2->linea) {
        return v1->linea - v2->linea;
    }
    return v1->ordenDeclaracion - v2->ordenDeclaracion;
}

// Retorna 1 si la variable se agregó al reporte (listado final), 0 en caso contrario
int var_agregar(char* identificador, char* tipoDato, int linea, int columna) {

    if (!identificador || !tipoDato) {
        printf("ERROR: Fallo de parametros en var_agregar()\n");
        exit(EXIT_FAILURE);
    }

    // Determinar si tipoDato tiene el modificador CONST
    Clase clase = (strstr(tipoDato, "const") != NULL) ? CONST_VAR : VARIABLE;

    if (ts_validarInsercionSimbolo(identificador, tipoDato, clase, linea, columna) == 0)
        return 0;

    // Agregar a la lista de variables
    int indice_nuevo = estado_global->indice_variables + 1;
        
    estado_global->lista_variables = reallocSeguro(
        estado_global->lista_variables,
        sizeof(TipoVariablesDeclaradas) * indice_nuevo,
        "variables"
    );
        
    int idx = estado_global->indice_variables;
    estado_global->lista_variables[idx].texto = duplicarCadena(identificador);
    estado_global->lista_variables[idx].tipoDato = duplicarCadena(tipoDato);
    estado_global->lista_variables[idx].linea = linea;
    estado_global->lista_variables[idx].columna = columna;
    estado_global->lista_variables[idx].ordenDeclaracion = estado_global->contador_orden_declaracion++;
        
    estado_global->indice_variables++;

    return 1;
}

// Verifica que el tipo de la variable y el inicializador sean compatibles
void validarInicializacion(char* tipoVariable, char* tipoOperandoDerecho, int lineaInicializador, int columnaInicializador) {

    if (!tipoVariable || !tipoOperandoDerecho) {
        printf("ERROR: Fallo de parametros en validarInicializacion()\n");
        exit(EXIT_FAILURE);
    }

    if (tiposCompatibles(tipoVariable, tipoOperandoDerecho) == 0) {
        char* mensaje = malloc(MAX_BUFFER);
        if (!mensaje) {
            printf("ERROR: No se pudo alojar mensaje\n");
            exit(EXIT_FAILURE);
        }
    
        // Esto se hace únicamente por una inconsistencia del enunciado
        char* tipoSinConst = quitarConst(tipoVariable);

        snprintf(mensaje, MAX_BUFFER, "%d:%d: Incompatibilidad de tipos al inicializar el tipo '%s' usando el tipo '%s'",
            lineaInicializador, columnaInicializador, tipoSinConst, tipoOperandoDerecho);
        err_agregarSemantico(estado_global, mensaje, lineaInicializador, columnaInicializador, NULL);
        free(mensaje);
        free(tipoSinConst);
    }
}

void var_imprimir(estado_compilador_t* estado) {
    printf("* Listado de variables declaradas (tipo de dato y numero de linea):\n");
    
    if (estado->lista_variables == NULL || estado->indice_variables == 0) {
        printf("-\n\n");
        return;
    }
    
    qsort(estado->lista_variables, estado->indice_variables, 
          sizeof(TipoVariablesDeclaradas), compararPorLinea);
    
    for (int i = 0; i < estado->indice_variables; i++) {
        printf("%s: %s, linea %d, columna %d\n",
               estado->lista_variables[i].texto,
               estado->lista_variables[i].tipoDato,
               estado->lista_variables[i].linea,
               estado->lista_variables[i].columna);
    }
    printf("\n");
}

char* quitarConst(const char* cadena) {
    if (!cadena) {
        printf("ERROR: Fallo de parametros en quitarConst()");
        exit(EXIT_FAILURE);
    }

    const char* palabra = "const";
    size_t len_palabra = strlen(palabra);

    const char* pos = strstr(cadena, palabra);
    if (!pos) {
        // No contiene "const": devolvemos una copia literal
        char* copia = malloc(strlen(cadena) + 1);
        if (!copia) {
            fprintf(stderr, "Error al reservar memoria en quitarConst()\n");
            exit(EXIT_FAILURE);
        }
        strcpy(copia, cadena);
        return copia;
    }

    // Calculamos el tamaño de la nueva cadena (restamos la longitud de "const")
    size_t nueva_longitud = strlen(cadena) - len_palabra;
    char* nueva = malloc(nueva_longitud + 1);
    if (!nueva) {
        fprintf(stderr, "Error al reservar memoria en quitarConst()\n");
        exit(EXIT_FAILURE);
    }

    // Copiamos la parte antes de "const"
    size_t antes = pos - cadena;
    strncpy(nueva, cadena, antes);
    nueva[antes] = '\0';

    // Saltamos "const" y los espacios que le sigan
    const char* despues = pos + len_palabra;
    while (isspace((unsigned char)*despues)) {
        despues++;
    }

    // Concatenamos el resto
    strcat(nueva, despues);

    return nueva;
}