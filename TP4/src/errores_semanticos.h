#ifndef ERRORES_H
#define ERRORES_H

// Forward declaration
typedef struct estado_compilador_t estado_compilador_t;

/* === ERRORES SEMÁNTICOS === */

/**
 * Agrega un error semántico a la lista.
 */
void err_agregarSemantico(estado_compilador_t*, char*, int, int, char*);

/**
 * Imprime todos los errores semánticos registrados.
 */
void err_imprimirSemanticos(estado_compilador_t*);

/* === ESTRUCTURAS SINTÁCTICAS NO RECONOCIDAS === */

/**
 * Agrega una estructura sintáctica no reconocida.
 */
void err_agregarEstructuraNoReconocida(estado_compilador_t*, char*, int);

/**
 * Imprime las estructuras sintácticas no reconocidas.
 */
void err_imprimirEstructurasNoReconocidas(estado_compilador_t*);

/* === CADENAS NO RECONOCIDAS === */

/**
 * Agrega una cadena no reconocida (errores léxicos).
 */
void err_agregarCadenaNoReconocida(estado_compilador_t*, char*, int, int);

/**
 * Imprime las cadenas no reconocidas.
 */
void err_imprimirCadenasNoReconocidas(estado_compilador_t*);

#endif