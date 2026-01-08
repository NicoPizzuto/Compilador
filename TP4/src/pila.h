#ifndef PILA_H
#define PILA_H

extern struct Pila pilaVariables;
extern struct Pila pilaParametros;
extern struct Pila pilaParametrosInvocacion;
extern struct Pila pilaErrorSintactico;
extern struct Pila pilaColumnasVariables;

extern struct Pila pilaTipos;
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
char* consultarTope(const struct Pila*); 
void limpiarPilaErrorSintactico(void);
char* generarLineaDesdePila(void);

#endif