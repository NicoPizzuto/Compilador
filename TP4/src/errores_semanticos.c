#include "errores_semanticos.h"
#include "estado_compilador.h"
#include "general.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

/* ==================== ERRORES SEMÁNTICOS ==================== */

void err_agregarSemantico(estado_compilador_t* estado, char* mensaje, int linea, int columna, char* nota) {
    if (!estado) {
        fprintf(stderr, "ERROR INTERNO: estado es NULL en err_agregarSemantico\n");
        exit(EXIT_FAILURE);
    }
    
    int indice_nuevo = estado->indice_errores_semanticos + 1;
    
    estado->lista_errores_semanticos = reallocSeguro(
        estado->lista_errores_semanticos,
        sizeof(TipoErrorSemantico) * indice_nuevo,
        "errores semanticos"
    );
    
    int idx = estado->indice_errores_semanticos;
    estado->lista_errores_semanticos[idx].mensaje = duplicarCadena(mensaje);
    estado->lista_errores_semanticos[idx].linea = linea;
    estado->lista_errores_semanticos[idx].columna = columna;
    estado->lista_errores_semanticos[idx].nota = nota ? duplicarCadena(nota) : NULL;
    
    estado->indice_errores_semanticos++;
}

void err_imprimirSemanticos(estado_compilador_t* estado) {
    printf("* Listado de errores semanticos:\n");
    
    if (estado->indice_errores_semanticos == 0) {
        printf("-\n\n");
        return;
    }
    
    for (int i = 0; i < estado->indice_errores_semanticos; i++) {
        printf("%s\n", estado->lista_errores_semanticos[i].mensaje);   // Se eliminan línea y columna (ya vienen con el mensaje)
        if (estado->lista_errores_semanticos[i].nota) {
            // IMPORTANTE: NO agregar "Nota:" aquí porque ya viene en la nota
            printf("%s\n", estado->lista_errores_semanticos[i].nota);
        }
    }
    printf("\n");
}

/* ==================== ESTRUCTURAS NO RECONOCIDAS ==================== */

void err_agregarEstructuraNoReconocida(estado_compilador_t* estado, char* estructura, int linea) {
    if (!estado) {
        fprintf(stderr, "ERROR INTERNO: estado es NULL en err_agregarEstructuraNoReconocida\n");
        exit(EXIT_FAILURE);
    }
    
    int indice_nuevo = estado->indice_estructuras_no_reconocidas + 1;
    
    estado->lista_estructuras_no_reconocidas = reallocSeguro(
        estado->lista_estructuras_no_reconocidas,
        sizeof(TipoEstructurasSintacticasNoReconocidas) * indice_nuevo,
        "estructuras no reconocidas"
    );
    
    int idx = estado->indice_estructuras_no_reconocidas;
    estado->lista_estructuras_no_reconocidas[idx].estructuraNoReconocida = duplicarCadena(estructura);
    estado->lista_estructuras_no_reconocidas[idx].linea = linea;
    
    estado->indice_estructuras_no_reconocidas++;
}

void err_imprimirEstructurasNoReconocidas(estado_compilador_t* estado) {
    printf("* Listado de errores sintacticos:\n");
    
    if (estado->indice_estructuras_no_reconocidas == 0) {
        printf("-\n\n");
        return;
    }
    
    for (int i = 0; i < estado->indice_estructuras_no_reconocidas; i++) {
        printf("\"%s\": linea %d\n", 
               estado->lista_estructuras_no_reconocidas[i].estructuraNoReconocida,
               estado->lista_estructuras_no_reconocidas[i].linea);
    }
    printf("\n");
}

/* ==================== CADENAS NO RECONOCIDAS ==================== */

void err_agregarCadenaNoReconocida(estado_compilador_t* estado, char* texto, int linea, int columna) {
    if (!estado) {
        fprintf(stderr, "ERROR INTERNO: estado es NULL en err_agregarCadenaNoReconocida\n");
        exit(EXIT_FAILURE);
    }
    
    int indice_nuevo = estado->indice_cadenas_no_reconocidas + 1;
    
    estado->lista_cadenas_no_reconocidas = reallocSeguro(
        estado->lista_cadenas_no_reconocidas,
        sizeof(TipoCadenasNoReconocida) * indice_nuevo,
        "cadenas no reconocidas"
    );
    
    int idx = estado->indice_cadenas_no_reconocidas;
    estado->lista_cadenas_no_reconocidas[idx].texto = duplicarCadena(texto);
    estado->lista_cadenas_no_reconocidas[idx].linea = linea;
    estado->lista_cadenas_no_reconocidas[idx].columna = columna;
    
    estado->indice_cadenas_no_reconocidas++;
}

void err_imprimirCadenasNoReconocidas(estado_compilador_t* estado) {
    printf("* Listado de errores lexicos:\n");
    
    if (estado->lista_cadenas_no_reconocidas == NULL || estado->indice_cadenas_no_reconocidas == 0) {
        printf("-\n\n");
        return;
    }
    
    for (int i = 0; i < estado->indice_cadenas_no_reconocidas; i++) {
        printf("%s: linea %d, columna %d\n",
               estado->lista_cadenas_no_reconocidas[i].texto,
               estado->lista_cadenas_no_reconocidas[i].linea,
               estado->lista_cadenas_no_reconocidas[i].columna);
    }
}