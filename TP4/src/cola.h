#ifndef COLA_H
#define COLA_H

//==================== ESTRUCTURAS ====================
typedef struct NodoCola {
    char* tipo;   // Para las variables es el tipo del inicializador, si es que existe
    char* nombre;
    int columna;
    int columnaInicializador;   // Solo para variables
    struct NodoCola* siguiente;
} NodoCola;

typedef struct Cola {
    NodoCola* inicio;
    NodoCola* final;
} Cola;

//==================== VARIABLES GLOBALES ====================
extern Cola colaParametros;
extern Cola colaParametrosInvocacion;
extern Cola colaVariables;

//==================== FUNCIONES ====================
void agregarCola(Cola*);
NodoCola* crearNodoCola(char*, char*, int, int);
void encolar(Cola*, char*, char*, int, int);
NodoCola desencolar(Cola*);
void vaciarCola(Cola*);

#endif