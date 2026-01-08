#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h" 
#include "pila.h"

// Inicialización de punteros globales
TipoVariablesDeclaradas* lista_variables_declaradas = NULL;
TipoFuncionesDeclaradasODefinidas* lista_funciones_declaradas_o_definidas = NULL;
TipoSentencias* lista_sentencias = NULL;
TipoEstructurasSintacticasNoReconocidas* lista_estructuras_sintacticas_no_reconocidas = NULL;
TipoCadenasNoReconocida* lista_cadenas_no_reconocidas = NULL;

// Inicialización de variables globales
int indice_variables_declaradas = 0;
int contador_orden_declaracion = 0;
int indice_funciones_declaradas_o_definidas = 0;
int indice_sentencias = 0;
int indice_estructuras_sintacticas_no_reconocidas = 0;
int indice_cadenas_no_reconocidas = 0;

void inicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line = INICIO_CONTEO_LINEA;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

char* guardarCadena(char* yytext) {
    char* cadena = malloc(strlen(yytext) + 1);
    if (cadena == NULL) {
        fprintf(stderr, "Error al reservar memoria para el lexema\n");
        liberarMemoria(); // Libero recursos
        exit(EXIT_FAILURE);
    }
    strcpy(cadena, yytext);
    return cadena;
}

int compararSentenciasPorLinea(const void *a, const void *b) {
    TipoSentencias* sentencia1 = (TipoSentencias *)a;
    TipoSentencias* sentencia2 = (TipoSentencias *)b;
    return sentencia1->linea - sentencia2->linea;
}

int compararVariablesPorLinea(const void *a, const void *b) {
    TipoVariablesDeclaradas* variable1 = (TipoVariablesDeclaradas *)a;
    TipoVariablesDeclaradas* variable2 = (TipoVariablesDeclaradas *)b;
    
    // Primero las ordenamos por línea
    if (variable1->linea != variable2->linea) {
        return variable1->linea - variable2->linea;
    }
    
    // Si están en la misma línea, las ordenamos por orden de declaración
    return variable1->ordenDeclaracion - variable2->ordenDeclaracion;
}

//----------------------------------------------------------------------------------------

/* - VARIABLES - */

void agregarVariablesDeclaradas(char *identificador, char *tipoDato, int linea) {
    struct Pila pilaAuxiliar;
    agregarPila(&pilaAuxiliar);
    char* nombreDesapilado;
    // Todas las variables se almacen en una pila auxiliar para invertir el orden e imprimirlas en el orden correcto
    while ((nombreDesapilado = desapilar(&pilaVariables)) != NULL) {
        apilar(&pilaAuxiliar, nombreDesapilado);
        free(nombreDesapilado);  // Liberar la memoria original
    }
    // Se procesan las variables desde la pila auxiliar pero ahora en el orden correcto
    while ((nombreDesapilado = desapilar(&pilaAuxiliar)) != NULL) {
        int indice_nuevo = indice_variables_declaradas + 1;
        TipoVariablesDeclaradas* temp = realloc(lista_variables_declaradas, sizeof(TipoVariablesDeclaradas) * indice_nuevo);
        if (temp == NULL) {
            // Error de memoria
            fprintf(stderr, "Error al asignar memoria para variables\n");
            // Antes de salir, limpiamos primero la pila auxiliar
            char* elemento;
            while ((elemento = desapilar(&pilaAuxiliar)) != NULL) {
                free(elemento);
            }
            free(nombreDesapilado);
            exit(EXIT_FAILURE);
        }
        lista_variables_declaradas = temp;
        lista_variables_declaradas[indice_variables_declaradas].texto = guardarCadena(nombreDesapilado);
        lista_variables_declaradas[indice_variables_declaradas].tipoDato = guardarCadena(tipoDato);
        lista_variables_declaradas[indice_variables_declaradas].linea = linea;
        lista_variables_declaradas[indice_variables_declaradas].ordenDeclaracion = contador_orden_declaracion++;
        indice_variables_declaradas++;    
        free(nombreDesapilado);  // Liberamos la memoria reservada    
    }
}

void imprimirVariablesDeclaradas() {
    printf( "* Listado de variables declaradas (tipo de dato y numero de linea):\n");
    if (lista_variables_declaradas == NULL) {
        printf("-\n");
    }
    else {
        // Antes de imprimir las variables, primero hay que ordenarlas por linea
        qsort(lista_variables_declaradas, indice_variables_declaradas, sizeof(TipoVariablesDeclaradas), compararVariablesPorLinea);
        for (int i = 0; i < indice_variables_declaradas; i++) {
            char* texto = lista_variables_declaradas[i].texto;
            char* tipoDato = lista_variables_declaradas[i].tipoDato;
            int linea = lista_variables_declaradas[i].linea;
            printf( "%s: %s, linea %d\n", texto, tipoDato, linea);
        }
        printf( "\n");
    }
}

/* - FUNCIONES - */

void agregarFuncionesDeclaradasODefinidas(char *nombreFuncion,char* parametrosRecibidos, char* tipoQueRetorna, int linea, char* tipoInicializacion) {
    int indice_nuevo = indice_funciones_declaradas_o_definidas + 1;
    TipoFuncionesDeclaradasODefinidas* temp = realloc(lista_funciones_declaradas_o_definidas, sizeof(TipoFuncionesDeclaradasODefinidas) * indice_nuevo);
    if (temp == NULL) {
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para funciones\n");
        exit(EXIT_FAILURE);
    }
    lista_funciones_declaradas_o_definidas = temp;  // Actualizamos solo si realloc tuvo éxito
    lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].nombreFuncion = guardarCadena(nombreFuncion);
    lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].tipoQueRetorna = guardarCadena(tipoQueRetorna);
    lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].linea = linea;  
    lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].tipoInicializacion = guardarCadena(tipoInicializacion);
    
    // Nuevo manejo de parámetros
        if (parametrosRecibidos != NULL && strlen(parametrosRecibidos) > 0) {
        lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].parametrosRecibidos = guardarCadena(parametrosRecibidos);
    } else {
        lista_funciones_declaradas_o_definidas[indice_funciones_declaradas_o_definidas].parametrosRecibidos = guardarCadena("void");
    }
    
    indice_funciones_declaradas_o_definidas++;
}

void imprimirFuncionesDeclaradasODefinidas() {
    printf( "* Listado de funciones declaradas o definidas:\n");

        // Verifico si la lista está vacía
        if (lista_funciones_declaradas_o_definidas == NULL) {
            printf("-\n");
        }
        else {
        
        // Recorro la lista e imprimo cada función
        for (int i = 0; i < indice_funciones_declaradas_o_definidas ; i++) {
            char *nombreFuncion = lista_funciones_declaradas_o_definidas[i].nombreFuncion;
            char *paramtrosRecibidos = lista_funciones_declaradas_o_definidas[i].parametrosRecibidos;
            char *tipoQueRetorna = lista_funciones_declaradas_o_definidas[i].tipoQueRetorna;
            int linea = lista_funciones_declaradas_o_definidas[i].linea;
            char *tipoInicializacion = lista_funciones_declaradas_o_definidas[i].tipoInicializacion;

            printf( "%s: %s, input: %s, retorna: %s, linea %d\n", nombreFuncion, tipoInicializacion, paramtrosRecibidos, tipoQueRetorna, linea);
        }
        printf( "\n");
    }
}

/* - SENTENCIAS - */

void agregarSentencias(char* tipo, int linea, int columna) {
    int indice_nuevo = indice_sentencias + 1;
    TipoSentencias* temp = realloc(lista_sentencias, sizeof(TipoSentencias) * indice_nuevo);
    if (temp == NULL) {
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para sentencias\n");
        exit(EXIT_FAILURE);
    }
    lista_sentencias = temp;  // Actualizamos solo si realloc tuvo éxito
    lista_sentencias[indice_sentencias].tipo = guardarCadena(tipo);
    lista_sentencias[indice_sentencias].linea = linea;
    lista_sentencias[indice_sentencias].columna = columna;   
    indice_sentencias++;
}

void imprimirSentencias() {
    printf( "* Listado de sentencias indicando tipo, numero de linea y de columna:\n");
    if (lista_sentencias == NULL) {
        printf("-\n");
    }
    else {
        qsort(lista_sentencias, indice_sentencias, sizeof(TipoSentencias), compararSentenciasPorLinea);
        for (int i = 0; i < indice_sentencias; i++) {
            char* tipo = lista_sentencias[i].tipo;
            int linea = lista_sentencias[i].linea;
            int columna = lista_sentencias[i].columna;
            printf("%s: linea %d, columna %d\n", tipo, linea, columna);
        }
        printf( "\n");
    }
}

/* - ESTRUCTURAS - */

void agregarEstructurasSintacticasNoReconocidas(char* estructura, int linea) {
    int indice_nuevo = indice_estructuras_sintacticas_no_reconocidas + 1;
    TipoEstructurasSintacticasNoReconocidas* temp = realloc(lista_estructuras_sintacticas_no_reconocidas, sizeof(TipoEstructurasSintacticasNoReconocidas) * indice_nuevo);
    if (temp == NULL) {
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para estructuras no reconocidas\n");
        exit(EXIT_FAILURE);
    }
    lista_estructuras_sintacticas_no_reconocidas = temp;
    lista_estructuras_sintacticas_no_reconocidas[indice_estructuras_sintacticas_no_reconocidas].estructuraNoReconocida = guardarCadena(estructura);
    lista_estructuras_sintacticas_no_reconocidas[indice_estructuras_sintacticas_no_reconocidas].linea = linea;
    indice_estructuras_sintacticas_no_reconocidas++;
}

void imprimirEstructurasNoReconocidas() {
    printf( "* Listado de estructuras sintacticas no reconocidas:\n");
    if (indice_estructuras_sintacticas_no_reconocidas > 1) {  // Nos aseguramos de que haya más de un elemento
        for (int i = 0; i < indice_estructuras_sintacticas_no_reconocidas; i++) {
            char* estructura = lista_estructuras_sintacticas_no_reconocidas[i].estructuraNoReconocida;
            int linea = lista_estructuras_sintacticas_no_reconocidas[i].linea;
            printf( "\"%s\": linea %d\n", estructura, linea);
        }
        printf( "\n");
    } else if (indice_estructuras_sintacticas_no_reconocidas == 1) {
        char* estructura = lista_estructuras_sintacticas_no_reconocidas[0].estructuraNoReconocida;
        int linea = lista_estructuras_sintacticas_no_reconocidas[0].linea;
        printf( "\"%s\": linea %d\n", estructura, linea);     
        printf( "\n");      
    }
}

/* - CADENAS NO RECONOCIDAS - */

void agregarCadenasNoReconocidas(char* texto, int linea, int columna) {
    int indice_nuevo = indice_cadenas_no_reconocidas + 1;
    TipoCadenasNoReconocida* temp = realloc(lista_cadenas_no_reconocidas, sizeof(TipoCadenasNoReconocida) * indice_nuevo);
    if (temp == NULL) {
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para cadenas no reconocidas\n");
        exit(EXIT_FAILURE);
    }
    lista_cadenas_no_reconocidas = temp; // Actualizamos solo si realloc tuvo éxito
    lista_cadenas_no_reconocidas[indice_cadenas_no_reconocidas].texto = guardarCadena(texto);
    lista_cadenas_no_reconocidas[indice_cadenas_no_reconocidas].linea = linea;
    lista_cadenas_no_reconocidas[indice_cadenas_no_reconocidas].columna = columna;
    indice_cadenas_no_reconocidas++;
}

void imprimirCadenasNoReconocidas() {
    printf( "* Listado de cadenas no reconocidas:\n");
    if (lista_cadenas_no_reconocidas == NULL) {
        printf("-\n");
    }
    else {
        for (int i = 0; i < indice_cadenas_no_reconocidas; i++) {
            char* texto = lista_cadenas_no_reconocidas[i].texto;
            int linea = lista_cadenas_no_reconocidas[i].linea;
            int columna = lista_cadenas_no_reconocidas[i].columna;
            printf("%s: linea %d, columna %d\n", texto, linea, columna);
        }
        printf( "\n");
    }
}

void mostrarReporte() {
    // Listado de variables declaradas
    imprimirVariablesDeclaradas();

    // Listado de funciones declaradas o definidas
    imprimirFuncionesDeclaradasODefinidas();

    // Listado de sentencias 
    imprimirSentencias();

    // Listado de estructuras sintácticas no reconocidas
    imprimirEstructurasNoReconocidas();

    // Listado de cadenas no reconocidas
    imprimirCadenasNoReconocidas();
}

/* Nota: Flex mantiene buffers internos que aparecen como "still reachable" 
   en Valgrind pero no son memory leaks del código de usuario */
void liberarMemoria() {
    // Liberar lista de variables declaradas
    if (lista_variables_declaradas != NULL) {
        for (int i = 0; i < indice_variables_declaradas; i++) {
            free(lista_variables_declaradas[i].texto);
            free(lista_variables_declaradas[i].tipoDato);
        }
        free(lista_variables_declaradas);
        lista_variables_declaradas = NULL;
    }
    indice_variables_declaradas = 0;
    contador_orden_declaracion = 0;

    // Liberar lista de funciones declaradas o definidas
    if (lista_funciones_declaradas_o_definidas != NULL) {
        for (int i = 0; i < indice_funciones_declaradas_o_definidas; i++) {
            free(lista_funciones_declaradas_o_definidas[i].nombreFuncion);
            free(lista_funciones_declaradas_o_definidas[i].parametrosRecibidos);
            free(lista_funciones_declaradas_o_definidas[i].tipoQueRetorna);
            free(lista_funciones_declaradas_o_definidas[i].tipoInicializacion);
        }
        free(lista_funciones_declaradas_o_definidas);
        lista_funciones_declaradas_o_definidas = NULL;
    }
    indice_funciones_declaradas_o_definidas = 0;

    // Liberar lista de sentencias
    if (lista_sentencias != NULL) {
        for (int i = 0; i < indice_sentencias; i++) {
            free(lista_sentencias[i].tipo);
        }
        free(lista_sentencias);
        lista_sentencias = NULL;
    }
    indice_sentencias = 0;

    // Liberar lista de estructuras sintácticas no reconocidas
    if (lista_estructuras_sintacticas_no_reconocidas != NULL) {
        for (int i = 0; i < indice_estructuras_sintacticas_no_reconocidas; i++) {
            free(lista_estructuras_sintacticas_no_reconocidas[i].estructuraNoReconocida);
        }
        free(lista_estructuras_sintacticas_no_reconocidas);
        lista_estructuras_sintacticas_no_reconocidas = NULL;
    }
    indice_estructuras_sintacticas_no_reconocidas = 0;

    // Liberar lista de cadenas no reconocidas
    if (lista_cadenas_no_reconocidas != NULL) {
        for (int i = 0; i < indice_cadenas_no_reconocidas; i++) {
            free(lista_cadenas_no_reconocidas[i].texto);
        }
        free(lista_cadenas_no_reconocidas);
        lista_cadenas_no_reconocidas = NULL;
    }
    indice_cadenas_no_reconocidas = 0;

    // Liberar pilas
    char* elemento;
    while ((elemento = desapilar(&pilaVariables)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaParametros)) != NULL) {
        free(elemento);
    }
    
    // Limpiar la lista de parámetros global
    resetearParametros();
}

/* - MANEJO DE PARÁMETROS - */

char lista_parametros[500] = "";

void agregarParametro(char* tipo, char* nombre) {
    char parametro_completo[100];
    snprintf(parametro_completo, sizeof(parametro_completo), "%s %s", tipo, nombre);
    if (strlen(lista_parametros) > 0) {
        strcat(lista_parametros, ", ");
    }
    strcat(lista_parametros, parametro_completo);
}

void resetearParametros() {
    lista_parametros[0] = '\0';
}

char* obtenerListaParametros() {
    if (strlen(lista_parametros) == 0) {
        return "void";
    }
    return lista_parametros;
}