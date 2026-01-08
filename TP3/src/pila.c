#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "general.h"

struct Pila pilaVariables;
struct Pila pilaParametros;

void agregarPila(struct Pila* pila) {
    pila->tope = NULL;
}

struct Nodo* crearNodo(const char* nombre) {
    struct Nodo* nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    strcpy(nuevoNodo->nombre, nombre); 
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
        // Error de memoria
        fprintf(stderr, "Error al asignar memoria para el nombre\n");
        exit(EXIT_FAILURE);
    }
    pila->tope = pila->tope->siguiente;
    free(temp);
    return nombre;
}