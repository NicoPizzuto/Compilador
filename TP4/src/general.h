#ifndef GENERAL_H
#define GENERAL_H

#include "estado_compilador.h"
#include "pila.h"
#include "variables.h"
#include "funciones.h"
#include "errores_semanticos.h"
#include "cola.h"

#define YYLTYPE YYLTYPE
#define INICIO_CONTEO_LINEA 1
#define INICIO_CONTEO_COLUMNA 1

// ----------------------- ESTRUCTURAS -------------------------------------

/* =========================================================================
 *  Estructuras de la Tabla de Símbolos (Para TP4)
 * -------------------------------------------------------------------------
 *  Simbolo:
 *      Representa una entrada en la tabla de símbolos. Cada identificador
 *      (variable, función, parámetro, etc.) del programa fuente genera un
 *      símbolo que se almacena en una lista enlazada.
 *
 *      Campos principales:
 *        - nombre: nombre del identificador (ej: "x", "miFuncion").
 *        - tipo: tipo de dato asociado (ej: "int", "float").
 *        - clase: clase del símbolo (ej: "variable", "funcion", "parametro").
 *        - alcance: nivel de alcance en el que está definido.
 *          (ej: 0 = global, 1 = dentro de función, 2+ = dentro de bloques anidados).
 *
 *      Caso particular: Funciones
 *        - Si el símbolo corresponde a una función, además de su tipo
 *          (tipo de retorno), se almacena:
 *              · param_count: número de parámetros formales.
 *              · params: lista enlazada de parámetros (struct Param).
 *
 *      Caso particular: Variables / Parámetros
 *        - Se almacenan como símbolos individuales en el scope donde fueron
 *          declarados. Si son parámetros de función, además estarán reflejados
 *          dentro de la lista "params" de la función correspondiente.
 *
 * -------------------------------------------------------------------------
 *  Param:
 *      Representa un parámetro formal de una función.
 *      - type: tipo de dato del parámetro (ej: "int").
 *      - name: nombre del parámetro (puede ser NULL en prototipos).
 *      - next: enlace al siguiente parámetro.
 *
 * -------------------------------------------------------------------------
 *  Nota de implementación:
 *      - Se utiliza una lista enlazada para almacenar símbolos en cada scope.
 *      - El manejo de scopes se realiza con una pila de tablas de símbolos
 *        (SymbolTable), permitiendo anidamiento de bloques { }.
 *      - lookup() busca un identificador en el scope actual y, si no está,
 *        recorre scopes padres hasta llegar al global.
 *      - insert_symbol() agrega un nuevo identificador en el scope actual.
 * =========================================================================
*/

typedef struct tiposAritmeticos {
    int peso;   // El de menor peso se convierte al de mayor peso en las expresiones que combinan tipos
    char* tipo;
} tiposAritmeticos;

typedef struct Param {
    char* type;
    char* name;   // puede ser NULL si es prototipo sin nombre
    struct Param* siguiente;
} Param;

typedef enum Clase{
    VARIABLE,
    CONST_VAR, 
    FUNCION_DEC,
    FUNCION_DEF,
    NO_ENCONTRADO
} Clase;

typedef struct Simbolo {
    int alcance; // Nivel de scope
    char* nombre; // Identificador
    char* tipo; // Tipo de dato
    int linea;
    int columna;
    Clase clase; // Verifica si en variable o función
    Cola parametros;    
    struct Simbolo* siguiente; // Siguiente en la lista enlazada
} Simbolo;

typedef struct YYLTYPE {
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

typedef struct TipoVariablesDeclaradas{
    char* texto;
    char* tipoDato;
    int linea;
    int columna;
    int ordenDeclaracion;
} TipoVariablesDeclaradas;

typedef struct TipoFuncionesDeclaradasODefinidas{
    char* nombreFuncion;
    char* parametrosRecibidos;
    char* tipoQueRetorna;
    int linea;
    char* tipoInicializacion;
} TipoFuncionesDeclaradasODefinidas;

typedef struct TipoSentencias{
    char* tipo;
    int linea;
    int columna;
} TipoSentencias;

typedef struct TipoEstructurasSintacticasNoReconocidas{
    char* estructuraNoReconocida;
    int linea;
} TipoEstructurasSintacticasNoReconocidas;

typedef struct TipoCadenasNoReconocida{
    char* texto;
    int linea;
    int columna;
} TipoCadenasNoReconocida;

typedef struct TipoErrorSemantico{
    char* mensaje;
    int linea;
    int columna;
    char* nota;
} TipoErrorSemantico;

// ----------------------- VARIABLES GLOBALES -------------------

extern YYLTYPE yylloc;
extern struct Pila pilaVariables;  
extern struct Pila pilaParametros;
extern struct Pila pilaParametrosInvocacion;
extern Simbolo* tablaDeSimbolos;
extern const tiposAritmeticos jerarquiaTipos[];

// ----------------------- FUNCIONES ----------------------------

void inicializarUbicacion(void);
char* guardarCadena(char*);
void mostrarReporte();
void liberarMemoria();

// ================= TABLA DE SÍMBOLOS =================

void liberarSimboloEspecial(Simbolo*);

// Valida conflictos de redeclaración y genera errores semánticos específicos.
// Incluye validaciones para: redeclaración como tipo diferente, conflicto de tipos, redeclaración de variable, redefinición de función.
int ts_validarInsercionSimbolo(char*, char*, Clase, int, int);

// Verifica conflictos y genera errores semánticos con formato exacto del enunciado.
// Es una función de validación previa a la inserción real realizada por var_agregar o func_agregar.
void ts_insertarSimbolo(Simbolo*);

// Obtiene el tipo de un identificador.
char* ts_obtenerTipo(char*, int, int);

Simbolo* ts_buscarSimbolo(char*);

// ================= VALIDACIONES =================

char* validarMultiplicacion(char*, char*, int, int);

char* deducirTipoConstante(const char*);

void manejoErrorVariables(Simbolo*, char*, char*, int, int);

int manejoErrorFunciones(Simbolo*, char*, char*, Clase, int, int);

char* armarTipoParametros(const Cola*);

char* armarTipoFuncion(char*, const Cola*);

char* armarTipoPunteroFuncion(char*, const Cola*);

void validarReturnConExpresion(char*, int, int);

char* validarAsignacion(char*, char*, int, int);

int validar_asignacion_const(char*, int, int);

int tiposCompatibles(const char*, const char*);

char* tipoAritmeticoMayor(char*, char*);

int ts_esFuncion(char*);

int ts_esVariableConstante(char*);

#endif