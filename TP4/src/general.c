#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "general.h" 
#include "pila.h"
#include "cola.h"

#define MAX_BUFFER 512

Simbolo *tablaDeSimbolos = NULL;

const tiposAritmeticos jerarquiaTipos[] = {
    {1, "char"},
    {1, "unsigned char"},
    {1, "short"},
    {1, "unsigned short"},
    {2, "int"},
    {2, "unsigned int"},
    {3, "long"},
    {3, "unsigned long"},
    {4, "float"},
    {4, "const float"},   // Sacar cuando se modifique el manejo de CONST
    {5, "double"},
    {6, "long double"}
};

void inicializarUbicacion(void)
{
    yylloc.first_line = yylloc.last_line = INICIO_CONTEO_LINEA;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

char* guardarCadena(char* yytext) {
    char* cadena = malloc(strlen(yytext) + 1);
    if (cadena == NULL) {
        fprintf(stderr, "Error al reservar memoria para el lexema\n");
        liberarMemoria(); // Libero recursos
        exit(EXIT_FAILURE);
    }
    strcpy(cadena, yytext);
    return cadena;
}

void mostrarReporte() {
    // Listado de variables declaradas
    var_imprimir(estado_global);

    // Listado de funciones declaradas o definidas
    func_imprimir(estado_global);

    // Listado de errores semánticos
    err_imprimirSemanticos(estado_global);

    // Listado de estructuras sintácticas no reconocidas
    err_imprimirEstructurasNoReconocidas(estado_global);

    // Listado de cadenas no reconocidas
    err_imprimirCadenasNoReconocidas(estado_global);
}

void liberarMemoria() {
    if (!estado_global) {
        // Veririficación para manejar seg fault si estado_global es NULL
        return;
    }
    
    // ==================== LIBERAR VARIABLES ====================
    if (estado_global->lista_variables != NULL) {
        for (int i = 0; i < estado_global->indice_variables; i++) {
            free(estado_global->lista_variables[i].texto);
            free(estado_global->lista_variables[i].tipoDato);
        }
        free(estado_global->lista_variables);
        estado_global->lista_variables = NULL;
    }
    estado_global->indice_variables = 0;
    estado_global->contador_orden_declaracion = 0;
    
    // ==================== LIBERAR FUNCIONES ====================
    if (estado_global->lista_funciones != NULL) {
        for (int i = 0; i < estado_global->indice_funciones; i++) {
            free(estado_global->lista_funciones[i].nombreFuncion);
            free(estado_global->lista_funciones[i].parametrosRecibidos);
            free(estado_global->lista_funciones[i].tipoQueRetorna);
            free(estado_global->lista_funciones[i].tipoInicializacion);
        }
        free(estado_global->lista_funciones);
        estado_global->lista_funciones = NULL;
    }
    estado_global->indice_funciones = 0;
    
    // ==================== LIBERAR SENTENCIAS ====================
    if (estado_global->lista_sentencias != NULL) {
        for (int i = 0; i < estado_global->indice_sentencias; i++) {
            free(estado_global->lista_sentencias[i].tipo);
        }
        free(estado_global->lista_sentencias);
        estado_global->lista_sentencias = NULL;
    }
    estado_global->indice_sentencias = 0;
    
    // ==================== LIBERAR ESTRUCTURAS NO RECONOCIDAS ====================
    if (estado_global->lista_estructuras_no_reconocidas != NULL) {
        for (int i = 0; i < estado_global->indice_estructuras_no_reconocidas; i++) {
            free(estado_global->lista_estructuras_no_reconocidas[i].estructuraNoReconocida);
        }
        free(estado_global->lista_estructuras_no_reconocidas);
        estado_global->lista_estructuras_no_reconocidas = NULL;
    }
    estado_global->indice_estructuras_no_reconocidas = 0;
    
    // ==================== LIBERAR CADENAS NO RECONOCIDAS ====================
    if (estado_global->lista_cadenas_no_reconocidas != NULL) {
        for (int i = 0; i < estado_global->indice_cadenas_no_reconocidas; i++) {
            free(estado_global->lista_cadenas_no_reconocidas[i].texto);
        }
        free(estado_global->lista_cadenas_no_reconocidas);
        estado_global->lista_cadenas_no_reconocidas = NULL;
    }
    estado_global->indice_cadenas_no_reconocidas = 0;
    
    // ==================== LIBERAR ERRORES SEMÁNTICOS ====================
    if (estado_global->lista_errores_semanticos != NULL) {
        for (int i = 0; i < estado_global->indice_errores_semanticos; i++) {
            free(estado_global->lista_errores_semanticos[i].mensaje);
            if (estado_global->lista_errores_semanticos[i].nota) {
                free(estado_global->lista_errores_semanticos[i].nota);
            }
        }
        free(estado_global->lista_errores_semanticos);
        estado_global->lista_errores_semanticos = NULL;
    }
    estado_global->indice_errores_semanticos = 0;
    
    // ==================== LIBERAR PARÁMETROS ====================
    if (estado_global->lista_parametros != NULL) {
        for (int i = 0; i < estado_global->num_parametros; i++) {
            free(estado_global->lista_parametros[i]);
        }
        free(estado_global->lista_parametros);
        estado_global->lista_parametros = NULL;
    }
    estado_global->num_parametros = 0;
    estado_global->capacidad_parametros = 0;
    
    // ==================== LIBERAR PILAS ====================
    char* elemento;
    while ((elemento = desapilar(&pilaVariables)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaParametros)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaVariables)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaParametros)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaParametrosInvocacion)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaErrorSintactico)) != NULL) {
        free(elemento);
    }
    while ((elemento = desapilar(&pilaColumnasVariables)) != NULL) {
        free(elemento);
    }
}

// ================= FUNCIONES TABLA DE SÍMBOLOS =================

// Función auxiliar para crear símbolo temporal y evitar código duplicado
static Simbolo* crearSimbolo(char* nombre, char* tipo, Clase clase, int linea, int columna) {
    if (!nombre || !tipo) {
        printf("ERROR: Fallo de parametros en crearSimbolo\n");
        exit(EXIT_FAILURE);
    }
    
    Simbolo* simbolo = malloc(sizeof(Simbolo));
    if (!simbolo) {
        printf("ERROR: Fallo al reservar memoria para el simbolo en crearSimbolo\n");
        exit(EXIT_FAILURE);
    }
    
    simbolo->nombre = guardarCadena(nombre);
    simbolo->tipo = guardarCadena(tipo);
    simbolo->clase = clase;
    simbolo->linea = linea;
    simbolo->columna = columna;
    agregarCola(&simbolo->parametros);
    simbolo->siguiente = NULL;

    return simbolo;
}

// Se encarga específicamente de liberar el símbolo especial, de clase NO_ENCONTRADO
void liberarSimboloEspecial(Simbolo* simbolo) {
    if (simbolo && simbolo->clase == NO_ENCONTRADO) {
        if (simbolo->nombre) free(simbolo->nombre);
        if (simbolo->tipo) free(simbolo->tipo);
        free(simbolo);
    }
}

// Retorna 1 si se insertó el símbolo, 0 en caso contrario
int ts_validarInsercionSimbolo(char* nombre, char* tipo, Clase clase, int linea, int columna) {
    if (!nombre || !tipo) {
        printf("ERROR: Fallo de parametros en ts_validarInsercionSimbolo\n");
        exit(EXIT_FAILURE);
    }

    Simbolo* simbolo = ts_buscarSimbolo(nombre);
    
    if (simbolo->clase == NO_ENCONTRADO) {
        liberarSimboloEspecial(simbolo);
        ts_insertarSimbolo(crearSimbolo(nombre, tipo, clase, linea, columna));
        return 1;
    }

    if (clase == VARIABLE || clase == CONST_VAR) {
        manejoErrorVariables(simbolo, nombre, tipo, linea, columna);
        return 0;
    }

    if (clase == FUNCION_DEC || clase == FUNCION_DEF)
        return manejoErrorFunciones(simbolo, nombre, tipo, clase, linea, columna);

    return 0;   // Protección contra undefined behavior, por si se agregan nuevas clases
}

void ts_insertarSimbolo(Simbolo* nuevoSimbolo) {
    if (!nuevoSimbolo) {
        printf("ERROR: Fallo de parametros en ts_insertarSimbolo\n");
        exit(EXIT_FAILURE);
    }
    
    // Si el nuevo símbolo es una función, se le agregan los parámetros
    if (nuevoSimbolo->clase == FUNCION_DEC || nuevoSimbolo->clase == FUNCION_DEF) {
        NodoCola nuevoParametro;
        
        while (colaParametros.inicio) {
            nuevoParametro = desencolar(&colaParametros);
            encolar(&nuevoSimbolo->parametros, nuevoParametro.tipo, nuevoParametro.nombre, nuevoParametro.columna, nuevoParametro.columnaInicializador);
            if (nuevoParametro.tipo) free(nuevoParametro.tipo);
            if (nuevoParametro.nombre) free(nuevoParametro.nombre);
        }
    }
    
    if(!tablaDeSimbolos) {
        tablaDeSimbolos = nuevoSimbolo;
    }
    else {
        nuevoSimbolo->siguiente = tablaDeSimbolos;   //Se inserta al inicio
        tablaDeSimbolos = nuevoSimbolo;
    }
}

// Busca un símbolo en la tabla y devuelve su tipo (tipo de retorno para las funciones)
char* ts_obtenerTipo(char* nombre, int linea, int columna) {
    
    if (!nombre) {
        printf("ERROR: Fallo de parametros en ts_insertarSimbolo\n");
        exit(EXIT_FAILURE);
    }

    Simbolo* simbolo = ts_buscarSimbolo(nombre);

    if (simbolo->clase == NO_ENCONTRADO) {
        liberarSimboloEspecial(simbolo);
        NodoCola* aux = colaParametros.inicio;

        // Buscar en la cola de parámetros
        while(aux && strcmp(nombre, aux->nombre) != 0)
            aux = aux->siguiente;

        if (!aux) {
            char* mensaje = malloc(MAX_BUFFER);
            if (!mensaje) {
                printf("ERROR: No se pudo alojar mensaje\n");
                exit(EXIT_FAILURE);
            }

            snprintf(mensaje, MAX_BUFFER, "%d:%d: '%s' sin declarar", linea, columna, nombre);
            err_agregarSemantico(estado_global, mensaje, linea, columna, NULL);
            free(mensaje);
            return guardarCadena("unknown");
        }
        else {
            char* copia = guardarCadena(aux->tipo);
            return copia;   // Cuando se libere la cadena en el parser, se liberará la copia (no la cadena de la tabla)
        }
    }

    if (simbolo->clase == FUNCION_DEC || simbolo->clase == FUNCION_DEF)
        return armarTipoPunteroFuncion(simbolo->tipo, &simbolo->parametros);
    else {
        char* copia = guardarCadena(simbolo->tipo);
        return copia;   // Cuando se libere la cadena en el parser, se liberará la copia (no la cadena de la tabla)
    }
}

// Busca un identificador en la tabla
Simbolo* ts_buscarSimbolo(char* nombre) {

    if (!nombre) {
        printf("ERROR: Fallo de parametros en ts_buscarSimbolo\n");
        exit(EXIT_FAILURE);
    }

    Simbolo* aux = tablaDeSimbolos;
    while(aux && strcmp(nombre, aux->nombre) != 0)
        aux = aux->siguiente;

    if (!aux)
        return crearSimbolo("", "", NO_ENCONTRADO, -1, 0);  // Se debe liberar fuera de la función

    return aux;
}

// ================= VALIDACIONES SEMÁNTICAS =================

// Retorna el tipo del resultado de la expresión, o "unknown" en caso de error
char* validarMultiplicacion(char* tipoOperando1, char* tipoOperando2, int linea, int columna) {
    
    if (!tipoOperando1 || !tipoOperando2) {
        printf("ERROR: Fallo de parametros en validarMultiplicacion\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(tipoOperando1, "unknown") == 0 || strcmp(tipoOperando2, "unknown") == 0)
        return guardarCadena("unknown");

    char* tipoResultante = tipoAritmeticoMayor(tipoOperando1, tipoOperando2);
    if (strcmp(tipoResultante, "unknown") != 0)
        return guardarCadena(tipoResultante);
    else {
        char* mensaje = malloc(MAX_BUFFER);
        if (!mensaje) {
            printf("ERROR: No se pudo alojar mensaje\n");
            exit(EXIT_FAILURE);
        }

        snprintf(mensaje, MAX_BUFFER, "%d:%d: Operandos invalidos del operador binario * (tienen '%s' y '%s')", linea, columna, 
            tipoOperando1, tipoOperando2);
        err_agregarSemantico(estado_global, mensaje, linea, columna, NULL);
        free(mensaje);
        return guardarCadena(tipoResultante);
    }
}

// función auxiliar que de una constante "literal" trata de identificar el tipo
char* deducirTipoConstante(const char* valor) {
    if (!valor) return NULL;
    
    int len = strlen(valor);
    if (len >= 2 && valor[0] == '"' && valor[len-1] == '"') {
        return guardarCadena("char*");
    }

    // Comillas simples
    if (valor[0] == '\'' && valor[strlen(valor) - 1] == '\'' && strlen(valor) == 3) {
        return guardarCadena("char");
    }

    // Si contiene un punto decimal → float o double
    if (strchr(valor, '.') != NULL) {
        return guardarCadena("float");
    }

    // Por defecto, int
    return guardarCadena("int");
}

void manejoErrorVariables(Simbolo* simbolo, char* nombre, char* tipo, int linea, int columna) {
    if (!simbolo || !nombre || !tipo) {
        printf("ERROR: Fallo de parametros en manejoErrorVariables\n");
        exit(EXIT_FAILURE);
    }
    
    char* mensaje = malloc(MAX_BUFFER);
    char* nota = malloc(MAX_BUFFER);
    if (!mensaje || !nota) {
        printf("ERROR: No se pudo alojar mensaje o nota\n");
        exit(EXIT_FAILURE);
    }

    if (simbolo->clase != VARIABLE && simbolo->clase != CONST_VAR) {
        char* tipoFuncion = armarTipoFuncion(simbolo->tipo, &simbolo->parametros);
        snprintf(mensaje, MAX_BUFFER, "%d:%d: '%s' redeclarado como un tipo diferente de simbolo", linea, columna, nombre);
        snprintf(nota, MAX_BUFFER, "Nota: la declaracion previa de '%s' es de tipo '%s': %d:%d", 
            nombre, tipoFuncion, simbolo->linea, simbolo->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        free(tipoFuncion);
    }

    if (simbolo->clase == VARIABLE || simbolo->clase == CONST_VAR) { 
        if (strcmp(simbolo->tipo, tipo) == 0) {
            snprintf(mensaje, MAX_BUFFER, "%d:%d: Redeclaracion de '%s'", linea, columna, nombre);
            snprintf(nota, MAX_BUFFER, "Nota: la declaracion previa de '%s' es de tipo '%s': %d:%d",
                     nombre, simbolo->tipo, simbolo->linea, simbolo->columna);
            err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        }
        else {
            snprintf(mensaje, MAX_BUFFER, "%d:%d: conflicto de tipos para '%s'; la ultima es de tipo '%s'", linea, columna, nombre, tipo);
            snprintf(nota, MAX_BUFFER, "Nota: la declaracion previa de '%s' es de tipo '%s': %d:%d",
                     nombre, simbolo->tipo, simbolo->linea, simbolo->columna);
            err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        }
    }
    
    free(mensaje);
    free(nota);
}

// Retorna 1 si se insertó el símbolo, 0 en caso contrario
int manejoErrorFunciones(Simbolo* simbolo, char* nombre, char* tipo, Clase clase, int linea, int columna) {
    if (!simbolo || !nombre || !tipo) {
        printf("ERROR: Fallo de parametros en manejoErrorFunciones\n");
        exit(EXIT_FAILURE);
    }
    
    char* mensaje = malloc(MAX_BUFFER);
    char* nota = malloc(MAX_BUFFER);
    if (!mensaje || !nota) {
        printf("ERROR: No se pudo alojar mensaje o nota\n");
        exit(EXIT_FAILURE);
    }

    if (simbolo->clase != FUNCION_DEC && simbolo->clase != FUNCION_DEF) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: '%s' redeclarado como un tipo diferente de simbolo", linea, columna, nombre);
        snprintf(nota, MAX_BUFFER, "Nota: la declaracion previa de '%s' es de tipo '%s': %d:%d",
                 nombre, simbolo->tipo, simbolo->linea, simbolo->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        // Se vacía para evitar que los parámetros actuales, que ya no sirven, se mezclen con futuras declaraciones/definiciones de funciones
        vaciarCola(&colaParametros);
        free(mensaje);
        free(nota);
        return 0;
    }

    char* tipoFuncionTS = armarTipoFuncion(simbolo->tipo, &simbolo->parametros);

    if (clase == FUNCION_DEF && simbolo->clase == FUNCION_DEF) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: Redefinicion de '%s'", linea, columna, nombre);
        snprintf(nota, MAX_BUFFER, "Nota: la definicion previa de '%s' es de tipo '%s': %d:%d",
                 nombre, tipoFuncionTS, simbolo->linea, simbolo->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        vaciarCola(&colaParametros);
        free(tipoFuncionTS);
        free(mensaje);
        free(nota);
        return 0;
    }

    char* tipoFuncionParser = armarTipoFuncion(tipo, &colaParametros);
    int resultado;

    // Se procede con el chequeo de tipos entre cabeceras de funciones (prototipo y definición o 2 prototipos)
    
    if (clase == FUNCION_DEC && simbolo->clase == FUNCION_DEF)
        resultado = 0;
    else if (strcmp(tipoFuncionTS, tipoFuncionParser) == 0) {
        resultado = 1;
        ts_insertarSimbolo(crearSimbolo(nombre, tipo, clase, linea, columna));   // No hay conflicto de tipos, se inserta el nuevo símbolo
    }
    else {
        resultado = 0;
        snprintf(mensaje, MAX_BUFFER, "%d:%d: conflicto de tipos para '%s'; la ultima es de tipo '%s'", linea, columna, nombre, tipoFuncionParser);
        snprintf(nota, MAX_BUFFER, "Nota: la declaracion previa de '%s' es de tipo '%s': %d:%d",
                 nombre, tipoFuncionTS, simbolo->linea, simbolo->columna);
        err_agregarSemantico(estado_global, mensaje, linea, columna, nota);
        vaciarCola(&colaParametros);
    }

    free(tipoFuncionTS);
    free(tipoFuncionParser);
    free(mensaje);
    free(nota);
    return resultado;
}

// Construye un string con los tipos de los parámetros (ej. "int, double")
char* armarTipoParametros(const Cola* cola) {
    
    if (!cola) {
        printf("ERROR: Fallo de parametros en armarTipoParametros\n");
        exit(EXIT_FAILURE);
    }
    
    char* resultado = malloc(MAX_BUFFER);
    if (!resultado) {
        printf("ERROR: Fallo al reservar memoria para el resultado en armarTipoParametros\n");
        exit(EXIT_FAILURE);
    }
    strcpy(resultado, "");

    for (NodoCola* aux = cola->inicio; aux; aux = aux->siguiente) {
        if (aux->tipo)
            strcat(resultado, aux->tipo);
        else
            printf("Tipo NULL en armarTipoParametros\n"); //Protección contra segmentation fault (SACAR)
        
        if(aux->siguiente)
            strcat(resultado, ", ");
    }

    if (strlen(resultado) == 0)
        strcpy(resultado, "void");

    return resultado;   //Luego se debe liberar memoria
}

// Construye un string con el tipo completo de la función (ej. "int(int, double)")
char* armarTipoFuncion(char* tipoRetorno, const Cola* cola) {
    
    if (!tipoRetorno || !cola) {
        printf("ERROR: Fallo de parametros en armarTipoFuncion\n");
        exit(EXIT_FAILURE);
    }
    
    char* resultado = malloc(MAX_BUFFER);
    if (!resultado) {
        printf("ERROR: Fallo al reservar memoria para el resultado en armarTipoFuncion\n");
        exit(EXIT_FAILURE);
    }

    char* tipoParametros = armarTipoParametros(cola);
    snprintf(resultado, MAX_BUFFER, "%s(%s)", tipoRetorno, tipoParametros);
    free(tipoParametros);

    return resultado;   // Luego se debe liberar memoria
}

// Construye un string con el tipo completo del puntero a función (ej. "int (*)(int, double)")
char* armarTipoPunteroFuncion(char* tipoRetorno, const Cola* cola) {

    if (!tipoRetorno || !cola) {
        printf("ERROR: Fallo de parametros en armarTipoPunteroFuncion\n");
        exit(EXIT_FAILURE);
    }

    char* resultado = malloc(MAX_BUFFER);
    if (!resultado) {
        printf("ERROR: Fallo al reservar memoria para el resultado en armarTipoPunteroFuncion\n");
        exit(EXIT_FAILURE);
    }

    char* tipoParametros = armarTipoParametros(cola);
    snprintf(resultado, MAX_BUFFER, "%s (*)(%s)", tipoRetorno, tipoParametros);
    free(tipoParametros);

    return resultado;   // Luego se debe liberar memoria
}

void validarReturnConExpresion(char* tipoRetornado, int linea, int columna) {

    if (!tipoRetornado) {
        printf("ERROR: Fallo de parametros en validarReturnConExpresion()\n");
        exit(EXIT_FAILURE);
    }

    char* tipoRetornoFuncion = consultarTope(&pilaTipos);
    if (!tipoRetornoFuncion)
        tipoRetornoFuncion = "void";

    if (tiposCompatibles(tipoRetornoFuncion, tipoRetornado) == 0) {
        char* mensaje = malloc(MAX_BUFFER);
        if (!mensaje) {
            printf("ERROR: No se pudo alojar mensaje\n");
            exit(EXIT_FAILURE);
        }

        snprintf(mensaje, MAX_BUFFER, "%d:%d: Incompatibilidad de tipos al retornar el tipo '%s' pero se esperaba '%s'",
            linea, columna, tipoRetornado, tipoRetornoFuncion);
        err_agregarSemantico(estado_global, mensaje, linea, columna, NULL);
        free(mensaje);
    }
}

char* validarAsignacion(char* identificador, char* tipoOperandoDerecho, int linea, int columnaOperador) {

    if (!identificador || !tipoOperandoDerecho) {
        printf("ERROR: Fallo de parametros en validarAsignacion()\n");
        exit(EXIT_FAILURE);
    }

    // Esta invocacion no puede devolver el simbolo especial (NO_ENCONTRADO), porque esto ya se validó en el parser
    Simbolo* simbolo = ts_buscarSimbolo(identificador);
    int flag = 0;
    char* mensaje = malloc(MAX_BUFFER);
    if (!mensaje) {
        printf("ERROR: No se pudo alojar mensaje\n");
        exit(EXIT_FAILURE);
    }

    if (simbolo->clase == CONST_VAR) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: Asignacion de la variable de solo lectura '%s'", linea, columnaOperador, identificador);
        err_agregarSemantico(estado_global, mensaje, linea, columnaOperador, NULL);
        flag = 1;
    }

    // Verifica que el tipo del operando derecho no sea "void"
    if (strcmp(tipoOperandoDerecho, "void") == 0) {
        snprintf(mensaje, MAX_BUFFER, "%d:%d: No se ignora el valor de retorno void como deberia ser", linea, columnaOperador);
        err_agregarSemantico(estado_global, mensaje, linea, columnaOperador, NULL);
        flag = 1;
    }

    if (tiposCompatibles(simbolo->tipo, tipoOperandoDerecho) == 0)
        flag = 1;

    free(mensaje);
    if (flag) {
        return guardarCadena("unknown");
    }
    else {
        char* copia = guardarCadena(simbolo->tipo);
        return copia;   // Cuando se libere la cadena en el parser, se liberará la copia (no la cadena de la tabla)
    }
}

int validar_asignacion_const(char* identificador, int linea, int columna) {
  
    if (!estado_global || !identificador) {
        return 0;
    }
    if (ts_esVariableConstante(identificador)) {
        char* mensaje = malloc(MAX_BUFFER);
        if (mensaje) {
            snprintf(mensaje, MAX_BUFFER, "Asignacion de la variable de solo lectura '%s'", identificador);
            err_agregarSemantico(estado_global, mensaje, linea, columna, NULL);
            free(mensaje);
        }
        return 0;
    }
    
    return 1;
}

// Si los tipos son compatibles devuelve 1, caso contrario retorna 0
int tiposCompatibles(const char* tipo1, const char* tipo2) {
    
    if (!tipo1 || !tipo2) {
        printf("ERROR: Fallo de parametros en tiposCompatibles\n");
        exit(EXIT_FAILURE);
    }

    // Necesario para operaciones con tipos que no son aritméticos (ej. char*)
    if (strcmp(tipo1, tipo2) == 0)
        return 1;
    
    int flagTipo1 = 0, flagTipo2 = 0, cantTiposAritmeticos = sizeof(jerarquiaTipos) / sizeof(jerarquiaTipos[0]);
    for (int i = 0; i < cantTiposAritmeticos && !(flagTipo1 && flagTipo2); i++) {
        if (!flagTipo1 && strcmp(tipo1, jerarquiaTipos[i].tipo) == 0) flagTipo1 = 1;
        if (!flagTipo2 && strcmp(tipo2, jerarquiaTipos[i].tipo) == 0) flagTipo2 = 1;
    }

    // Retorna 1 solo si ambos tipos forman parte del conjunto de tipos aritméticos
    return flagTipo1 && flagTipo2;
}

// Verifica que ambos tipos sean aritméticos, y devuelve el tipo de mayor peso (mayor jerarquía en la conversión de tipos)
char* tipoAritmeticoMayor(char* tipo1, char* tipo2) {

    if (!tipo1 || !tipo2) {
        printf("ERROR: Fallo de parametros en tipoAritmeticoMayor\n");
        exit(EXIT_FAILURE);
    }

    int pesoTipo1 = 0, pesoTipo2 = 0, cantTipos = sizeof(jerarquiaTipos) / sizeof(jerarquiaTipos[0]);

    for (int i = 0; i < cantTipos && (pesoTipo1 == 0 || pesoTipo2 == 0); i++) {
        if (strcmp(tipo1, jerarquiaTipos[i].tipo) == 0) pesoTipo1 = jerarquiaTipos[i].peso;
        if (strcmp(tipo2, jerarquiaTipos[i].tipo) == 0) pesoTipo2 = jerarquiaTipos[i].peso;
    }

    if (pesoTipo1 == 0 || pesoTipo2 == 0)
        return "unknown";

    if (pesoTipo1 == 1 && pesoTipo2 == 1)
        return "int";   // Los primeros 4 tipos siempre se convierten a "int"
    else if (pesoTipo1 >= pesoTipo2)
        return tipo1;
    else
        return tipo2;
}

int ts_esFuncion(char* nombre) {
    if (!tablaDeSimbolos || !nombre) {
        return 0;
    }
    
    // Verificar funciones estándar
    if (strcmp(nombre, "printf") == 0 || strcmp(nombre, "scanf") == 0 || 
        strcmp(nombre, "malloc") == 0 || strcmp(nombre, "free") == 0) {
        return 1;
    }
    
    // Buscar en funciones declaradas/definidas
    for (int i = 0; i < estado_global->indice_funciones; i++) {
        if (strcmp(estado_global->lista_funciones[i].nombreFuncion, nombre) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int ts_esVariableConstante(char* nombre) {
    if (!nombre) {
        printf("ERROR: función esVariableConstante");
        return 0;
    }
    for (int i=0; i<estado_global->indice_variables; i++) {
        if (strcmp(estado_global->lista_variables[i].texto, nombre) == 0) {
           return (strstr(estado_global->lista_variables[i].tipoDato, "const") != NULL);
        }
    }
    
    return 0;
}