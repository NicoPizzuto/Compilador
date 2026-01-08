#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "general.h"

struct Pila pilaVariables;
struct Pila pilaParametros;
struct Pila pilaParametrosInvocacion;
struct Pila pilaErrorSintactico;
struct Pila pilaColumnasVariables;

struct Pila pilaTipos;

void agregarPila(struct Pila* pila) {
    pila->tope = NULL;
}

struct Nodo* crearNodo(const char* nombre) {
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    strncpy(nuevoNodo->nombre, nombre, sizeof(nuevoNodo->nombre) - 1);
    nuevoNodo->nombre[sizeof(nuevoNodo->nombre) - 1] = '\0'; 
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void apilar(struct Pila* pila, const char* nombre) {
    struct Nodo* nuevoNodo = crearNodo(nombre);
    nuevoNodo->siguiente = pila->tope;
    pila->tope = nuevoNodo;
}

char* desapilar(struct Pila* pila) {
    if (pila->tope == NULL) {
        return NULL;
    }
    struct Nodo* temp = pila->tope;
    
    char* nombre = guardarCadena(temp->nombre);
    if (nombre == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nombre\n");
        exit(EXIT_FAILURE);
    }
    
    pila->tope = pila->tope->siguiente;
    free(temp);
    return nombre;
}

char* consultarTope(const struct Pila* pila) {
    if (!pila->tope) {
        return NULL;
    }
    return pila->tope->nombre;
}

void limpiarPilaErrorSintactico() {
    char* token_texto;
    while ((token_texto = desapilar(&pilaErrorSintactico)) != NULL) {
        free(token_texto);
    }
}

char* generarLineaDesdePila() {
    if (pilaErrorSintactico.tope == NULL) {
        return guardarCadena("");
    }
    
    char buffer[2048];
    buffer[0] = '\0';
    struct Pila pilaAux;
    agregarPila(&pilaAux);
    char* token_texto;
    while ((token_texto = desapilar(&pilaErrorSintactico)) != NULL){
        apilar(&pilaAux, token_texto);
    }
    int primera = 1;
    int esPrimerElemento = 1; 
    while ((token_texto = desapilar(&pilaAux)) != NULL){
        if (esPrimerElemento) {
            esPrimerElemento = 0;
            free(token_texto);
            continue;
        }
        if (!primera){
            strcat(buffer, " ");
        }
        strcat(buffer, token_texto);
        primera = 0;
        free(token_texto);
    }
    return guardarCadena(buffer);
}