#include <stdlib.h>

#include "estado_compilador.h"
#include "general.h"

estado_compilador_t* estado_global = NULL;

estado_compilador_t* crearEstadoCompilador(void) {
    estado_compilador_t* estado = malloc(sizeof(estado_compilador_t));
    if (!estado) return NULL;
    
    // Inicializar todo a NULL/0
    estado->lista_variables = NULL;
    estado->indice_variables = 0;
    estado->contador_orden_declaracion = 0;
    
    estado->lista_funciones = NULL;
    estado->indice_funciones = 0;
    
    estado->lista_sentencias = NULL;
    estado->indice_sentencias = 0;
    
    estado->lista_estructuras_no_reconocidas = NULL;
    estado->indice_estructuras_no_reconocidas = 0;
    
    estado->lista_cadenas_no_reconocidas = NULL;
    estado->indice_cadenas_no_reconocidas = 0;
    
    estado->lista_errores_semanticos = NULL;
    estado->indice_errores_semanticos = 0;
    
    estado->lista_parametros = NULL;
    estado->num_parametros = 0;
    estado->capacidad_parametros = 0;
    
    return estado;
}

void destruirEstadoCompilador(estado_compilador_t*estado) {
    if (!estado) return;
    // TODO: Liberar todas las listas y estructuras dentro de estado en libreMemoria()
    free(estado);
}