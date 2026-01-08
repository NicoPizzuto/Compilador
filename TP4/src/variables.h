#ifndef VARIABLES_H
#define VARIABLES_H

// Para evitar declaraciones circulares
typedef struct estado_compilador_t estado_compilador_t;

/**
 * @brief Agrega una variable declarada al estado del compilador.
 * @param estado Puntero al estado del compilador.
 * @param identificador Nombre de la variable.
 * @param tipoDato Tipo de dato de la variable.
 * @param linea Número de línea donde se declaró la variable.
 * @param columna Número de columna donde se declaró la variable.
 */
int var_agregar(char*, char*, int, int);

void validarInicializacion(char*, char*, int, int);

/**
 * @brief Imprime todas las variables declaradas en el estado del compilador.
 * @param estado Puntero al estado del compilador.
 */
void var_imprimir(estado_compilador_t*);

char* quitarConst(const char* cadena);

/**
 * @brief Verifica si una variable ha sido declarada en el estado del compilador.
 * @param estado Puntero al estado del compilador.
 * @param identificador Nombre de la variable a verificar.
 * @param linea Número de línea donde se usa la variable (para reportar errores).
 * @return 1 si la variable está declarada, 0 si no lo está.
 */

#endif