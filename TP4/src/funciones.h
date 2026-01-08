#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct Cola Cola;
typedef enum Clase Clase;
typedef struct estado_compilador_t estado_compilador_t;

void sent_agregar(estado_compilador_t*, char*, int, int);

void func_agregar(char*, char*, Clase, int, int);

char* armarListaParametros(const Cola*);

char* func_verificarInvocacion(char*, int, int);

void func_imprimir(estado_compilador_t*);

#endif