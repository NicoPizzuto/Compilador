#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* reallocSeguro(void* ptr, size_t nuevo_tamanio, const char* nombre_tipo) {
    void* temp = realloc(ptr, nuevo_tamanio);
    if (temp == NULL && nuevo_tamanio > 0) {
        fprintf(stderr, "Error al asignar memoria para %s\n", nombre_tipo);
        exit(EXIT_FAILURE);
    }
    return temp;
}

char* duplicarCadena(const char* origen) {
    if (!origen) return NULL;
    
    char* copia = malloc(strlen(origen) + 1);
    if (!copia) {
        fprintf(stderr, "Error al reservar memoria para cadena\n");
        exit(EXIT_FAILURE);
    }
    strcpy(copia, origen);
    return copia;
}