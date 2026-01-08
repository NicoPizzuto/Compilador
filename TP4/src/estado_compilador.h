#ifndef ESTADO_COMPILADOR_H
#define ESTADO_COMPILADOR_H

// Forward declarations de las estructuras definidas en general.h (evitar declaraciones circulares)
typedef struct TipoVariablesDeclaradas TipoVariablesDeclaradas;
typedef struct TipoFuncionesDeclaradasODefinidas TipoFuncionesDeclaradasODefinidas;
typedef struct TipoSentencias TipoSentencias;
typedef struct TipoEstructurasSintacticasNoReconocidas TipoEstructurasSintacticasNoReconocidas;
typedef struct TipoCadenasNoReconocida TipoCadenasNoReconocida;
typedef struct TipoErrorSemantico TipoErrorSemantico;

/**
 * Estructura que encapsula todo el estado del compilador.
 * Así se facilita la gestión de memoria y el mantenimiento del código, evitando
 * el uso excesivo de variables globales dispersas.
 */
typedef struct estado_compilador_t{
    // Variables
    TipoVariablesDeclaradas* lista_variables;
    int indice_variables;
    int contador_orden_declaracion;
    
    // Funciones
    TipoFuncionesDeclaradasODefinidas* lista_funciones;
    int indice_funciones;
    
    // Sentencias
    TipoSentencias* lista_sentencias;
    int indice_sentencias;
    
    // Estructuras no reconocidas
    TipoEstructurasSintacticasNoReconocidas* lista_estructuras_no_reconocidas;
    int indice_estructuras_no_reconocidas;
    
    // Cadenas no reconocidas
    TipoCadenasNoReconocida* lista_cadenas_no_reconocidas;
    int indice_cadenas_no_reconocidas;
    
    // Errores semánticos
    TipoErrorSemantico* lista_errores_semanticos;
    int indice_errores_semanticos;
    
    // Parámetros
    char** lista_parametros;
    int num_parametros;
    int capacidad_parametros;
    
} estado_compilador_t;

/**
 * @brief Crea y inicializa un nuevo estado del compilador.
 * @return Puntero al nuevo estado del compilador, o NULL si falla la asignación de memoria.
 */
estado_compilador_t* crearEstadoCompilador(void);

/**
 * @brief Destruye el estado del compilador, liberando toda la memoria asociada.
 * @param estado Puntero al estado del compilador a destruir.
 */
void destruirEstadoCompilador(estado_compilador_t*);

// Variable global única (necesaria para Bison/Flex)
extern estado_compilador_t* estado_global;

#endif