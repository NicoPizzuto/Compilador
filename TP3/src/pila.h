#ifndef PILA_H
#define PILA_H

extern struct Pila pilaVariables;
extern struct Pila pilaParametros;

struct Nodo {
    char nombre[50];
    struct Nodo* siguiente;
};

struct Pila {
    struct Nodo* tope;
};

void agregarPila(struct Pila*);
void apilar(struct Pila*, const char*);
char* desapilar(struct Pila*); 
#endif