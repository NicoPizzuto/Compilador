#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "general.h"

Cola colaParametros;
Cola colaParametrosInvocacion;
Cola colaVariables;

void agregarCola(Cola* cola) {
    cola->inicio = NULL;
    cola->final = NULL;
}

NodoCola* crearNodoCola(char* tipo, char* nombre, int columna, int columnaInicializador) {
    NodoCola* nuevoNodo = malloc(sizeof(NodoCola));
    if (!nuevoNodo) {
        printf("ERROR: No se pudo asignar memoria para el nuevo nodo\n");
        exit(EXIT_FAILURE);
    }

    //Reserva memoria sólo para aquellos campos que son necesarios (!= NULL)
    nuevoNodo->tipo = (tipo) ? guardarCadena(tipo) : NULL;
    nuevoNodo->nombre = (nombre) ? guardarCadena(nombre) : NULL;
    nuevoNodo->columna = columna;
    nuevoNodo->columnaInicializador = columnaInicializador;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void encolar(Cola* cola, char* tipo, char* nombre, int columna, int columnaInicializador) {
    NodoCola* nuevoNodo = crearNodoCola(tipo, nombre, columna, columnaInicializador);

    if (!cola->inicio)
        cola->inicio = nuevoNodo;
    else
        cola->final->siguiente = nuevoNodo;

    cola->final = nuevoNodo;
}

NodoCola desencolar(Cola* cola) {
    NodoCola* aux = cola->inicio;
    NodoCola infoNodo;

    //Protección contra segmentation fault, en caso de que aux == NULL
    //No debería ser necesaria si se verificó que la cola no estuviera vacía, antes de invocar a la función
    if (!aux) {
        infoNodo.tipo = NULL;
        infoNodo.nombre = NULL;
        infoNodo.columna = -1;
        infoNodo.columnaInicializador = -1;
        return infoNodo;
    }

    //Reserva memoria sólo para aquellos campos que son necesarios (!= NULL)
    infoNodo.tipo = (aux->tipo) ? guardarCadena(aux->tipo) : NULL;
    infoNodo.nombre = (aux->nombre) ? guardarCadena(aux->nombre) : NULL;
    infoNodo.columna = aux->columna;
    infoNodo.columnaInicializador = aux->columnaInicializador;

    cola->inicio = aux->siguiente;
    if(!cola->inicio)
        cola->final = NULL;

    if (aux->tipo) free(aux->tipo);
    if (aux->nombre) free(aux->nombre);
    free(aux);
    return infoNodo;
}

void vaciarCola(Cola* cola) {
    NodoCola nodoDesencolado;
    
    while (cola->inicio) {
        nodoDesencolado = desencolar(cola);
        if (nodoDesencolado.tipo) free(nodoDesencolado.tipo);
        if (nodoDesencolado.nombre) free(nodoDesencolado.nombre);
    }
}