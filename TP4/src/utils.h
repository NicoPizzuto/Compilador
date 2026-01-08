#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/**
 * @brief Realiza una realloc segura, verificando si la asignación fue exitosa.
 * Si no se pudo asignar memoria, imprime un mensaje de error y termina el programa.
 */
void* reallocSeguro(void*, size_t, const char*);

/**
 * @brief Duplica una cadena de caracteres.
 * Reserva memoria para la nueva cadena y copia el contenido.
 * Si no se pudo asignar memoria, imprime un mensaje de error y termina el programa.
 */
char* duplicarCadena(const char*);

#endif