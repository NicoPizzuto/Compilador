%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "general.h"
#include "estado_compilador.h"
#include "variables.h"
#include "funciones.h"
#include "errores_semanticos.h"
#include "utils.h"
#include "pila.h"
#include "cola.h"

extern int yylex(void);
extern FILE* yyin;
extern FILE* yyout;
void yyerror(const char*);

%}

%error-verbose
%locations

%union {
    unsigned long unsigned_long_type;
    double double_type;
    char* string_type;
}

/* Declaraciones de precedencia (de menor a mayor precedencia) */
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left STAR SLASH
%right PLUSPLUS MINUSMINUS
%left '(' ')'

%token <string_type> ESPECIFICADOR_TIPO

/* Tokens específicos */
%token <string_type> IF MINUS ELSE GT STAR ASSIGN MINUSMINUS GE AND SUB_ASSIGN
%token <string_type> DEFAULT EQ SLASH CASE MUL_ASSIGN DIV_ASSIGN PLUSPLUS
%token <string_type> LE STRING_LITERAL OR SWITCH BREAK NE FOR DO LT WHILE CONTINUE
%token <string_type> RETURN PLUS ADD_ASSIGN VOID

%token <string_type> IDENTIFICADOR
%token <unsigned_long_type> CONSTANTE
%token <double_type> CONSTANTE_REAL

%type <string_type> especificador_tipo especificadores_declaracion
%type <unsigned_long_type> lista_argumentos_invocacion lista_expresiones
%type <string_type> expresion expresion_primaria expresion_postfija expresion_multiplicativa expresion_aditiva expresion_unaria expresion_relacional
%type <string_type> expresion_igualdad expresion_logica_and expresion_logica_or expresion_asignacion


%start programa

%%

programa
    : /* empty */ 
    | programa elemento_programa
    ;

elemento_programa
    : definicion_funcion
    | declaracion_externa
    | sentencia_expresion_global
    | error ';'
        { yyerrok; }
    | error '}'
        { yyerrok; }
    ;

sentencia_expresion_global
    : IDENTIFICADOR ASSIGN IDENTIFICADOR ';'
        {
            char estructura[100]; 
            sprintf(estructura, "%s = %s;", $1, $3);
            err_agregarEstructuraNoReconocida(estado_global, estructura, @1.first_line);
        }
    | expresion ';'
        {
            err_agregarEstructuraNoReconocida(estado_global, "expresion;", @1.first_line);
        }
;

declaracion_externa
    : declaracion
    | prototipo_funcion
    ;

prototipo_funcion
    : especificadores_declaracion IDENTIFICADOR '(' lista_parametros_opt ')' ';'
        { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            func_agregar($2, tipoDeclaracion, FUNCION_DEC, @2.first_line, @2.first_column);
            free($2);
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
            limpiarPilaErrorSintactico();
        }
    | VOID IDENTIFICADOR '(' lista_parametros_opt ')' ';'
        { 
            func_agregar($2, "void", FUNCION_DEC, @2.first_line, @2.first_column);
            free($1);
            free($2);
            limpiarPilaErrorSintactico();
        }
    ;

lista_parametros_opt
    : /* empty */
    | VOID  { free($1); }
    | lista_parametros
    ;


/* ---- EXPRESIONES ---- */

expresion
    : expresion_asignacion
        { $$ = $1; }
    ;

expresion_asignacion
    : expresion_logica_or
        { $$ = $1; }
    | CONSTANTE ASSIGN expresion_asignacion
    {
        char* mensaje = malloc(512);
        if (mensaje) {
            snprintf(mensaje, 512, "%d:%d: Se requiere un valor-L modificable como operando izquierdo de la asignacion", @2.first_line, @2.first_column);
            err_agregarSemantico(estado_global, mensaje, @2.first_line, @2.first_column, NULL);
            free(mensaje);
        }
        free($3);
        $$ = guardarCadena("unknown");
    }
    | CONSTANTE_REAL ASSIGN expresion_asignacion
    {
    }
    | IDENTIFICADOR ASSIGN expresion_asignacion
    {
        char* tipoIdentificador = ts_obtenerTipo($1, @1.first_line, @1.first_column);
        if (strcmp(tipoIdentificador, "unknown") != 0)
            $$ = validarAsignacion($1, $3, @2.first_line, @2.first_column);
        else
            $$ = guardarCadena("unknown");

        free($1);
        free($3);
        free(tipoIdentificador);
    }
    | IDENTIFICADOR ADD_ASSIGN expresion_asignacion
    {
    }
    | IDENTIFICADOR SUB_ASSIGN expresion_asignacion
    {
    }
    | IDENTIFICADOR MUL_ASSIGN expresion_asignacion
    {
    }
    | IDENTIFICADOR DIV_ASSIGN expresion_asignacion
    {
    }
    ;

expresion_logica_or
    : expresion_logica_and
        { $$ = $1; }
    | expresion_logica_or OR expresion_logica_and
    ;

expresion_logica_and
    : expresion_igualdad
        { $$ = $1; }
    | expresion_logica_and AND expresion_igualdad
    ;

expresion_igualdad
    : expresion_relacional
        { $$ = $1; }
    | expresion_igualdad EQ expresion_relacional
    | expresion_igualdad NE expresion_relacional
    ;

expresion_relacional
    : expresion_aditiva
        { $$ = $1; }
    | expresion_relacional LT expresion_aditiva
    | expresion_relacional GT expresion_aditiva
    | expresion_relacional LE expresion_aditiva
    | expresion_relacional GE expresion_aditiva
    ;

expresion_aditiva
    : expresion_multiplicativa
        { $$ = $1; }
    | expresion_aditiva PLUS expresion_multiplicativa
    | expresion_aditiva MINUS expresion_multiplicativa
    ;

expresion_multiplicativa
    : expresion_unaria
        { $$ = $1; }
    | expresion_multiplicativa STAR expresion_unaria
        {
            $$ = validarMultiplicacion($1, $3, @2.first_line, @2.first_column);
            free($1);
            free($3);
        }
    | expresion_multiplicativa SLASH expresion_unaria
        {
        }
    ;

expresion_unaria
    : expresion_postfija
        { $$ = $1; }
    | PLUSPLUS IDENTIFICADOR
        {
            $$ = ts_obtenerTipo($2, @2.first_line, @2.first_column);
            free($2);
        }
    | MINUSMINUS IDENTIFICADOR
    | MINUS expresion_unaria
        { $$ = $2; }
    ;

expresion_postfija
    : expresion_primaria
        { $$ = $1; }
    | IDENTIFICADOR '(' lista_argumentos_invocacion ')'
        {
            $$ = func_verificarInvocacion($1, @1.first_line, @1.first_column);
        }
    | IDENTIFICADOR PLUSPLUS
    | IDENTIFICADOR MINUSMINUS
    ;

expresion_primaria
    : IDENTIFICADOR
    {
        $$ = ts_obtenerTipo($1, @1.first_line, @1.first_column);
        free($1);
    }
    | CONSTANTE 
    { 
        $$ = guardarCadena("int");
    }
    | CONSTANTE_REAL 
    { 
        $$ = guardarCadena("float");
    }
    | STRING_LITERAL 
    { 
        $$ = guardarCadena("char *");
        free($1);
    }
    | '(' expresion ')' 
    { 
        $$ = guardarCadena($2);
        free($2);
    } 
    ;

lista_argumentos_invocacion
    : /* empty */
      { $$ = 0; } 
    | lista_expresiones
     { $$ = $1; } 
    ;

lista_expresiones
    : expresion
    { $$ = 1;
      encolar(&colaParametrosInvocacion, $1, NULL, @1.first_column, -1);
    }
    | lista_expresiones ',' expresion
    { $$ = $1 + 1;
      encolar(&colaParametrosInvocacion, $3, NULL, @3.first_column, -1);
    }
    ;

/* ---- SENTENCIAS ---- */

sentencia
    : sentencia_etiquetada
    | sentencia_expresion
    | sentencia_compuesta
    | sentencia_seleccion
    | sentencia_iteracion
    | sentencia_salto
    ;

sentencia_etiquetada
    : CASE expresion ':' sentencia
        { sent_agregar(estado_global, "case", @1.first_line, @1.first_column); }
    | DEFAULT ':' sentencia
        { sent_agregar(estado_global, "default", @1.first_line, @1.first_column); }
    | CASE expresion ':'
        { sent_agregar(estado_global, "case", @1.first_line, @1.first_column); }
    | DEFAULT ':'
        { sent_agregar(estado_global, "default", @1.first_line, @1.first_column); }
    | CASE expresion ':' error
        { 
            yyerrok;
            sent_agregar(estado_global, "case", @1.first_line, @1.first_column); 
        }
    | DEFAULT ':' error
        { 
            yyerrok;
            sent_agregar(estado_global, "default", @1.first_line, @1.first_column); 
        }
    ;

sentencia_expresion
    : ';'
        { limpiarPilaErrorSintactico(); }
    | expresion ';'
        { limpiarPilaErrorSintactico(); }
    | expresion error
        {
            yyerrok;
        }
    ;

sentencia_compuesta
    : '{' '}'
    | '{' lista_elementos_bloque '}'
    | '{' lista_elementos_bloque error '}'
        { yyerrok; }
    | '{' error '}'
        { 
            yyerrok; 
        }
    ;

lista_elementos_bloque
    : elemento_bloque
    | lista_elementos_bloque elemento_bloque
    | lista_elementos_bloque error
        { yyerrok; }
    | error
        { yyerrok; }
    ;

elemento_bloque
    : declaracion
    | sentencia
    ;

sentencia_seleccion
    : IF '(' expresion ')' sentencia
        { 
            sent_agregar(estado_global, "if", @1.first_line, @1.first_column);

        }
    | IF '(' expresion ')' sentencia ELSE sentencia
        { 
            sent_agregar(estado_global, "if/else", @1.first_line, @1.first_column);

        }
    | SWITCH '(' expresion ')' sentencia
        { 
            sent_agregar(estado_global, "switch", @1.first_line, @1.first_column);

        }
    ;

sentencia_iteracion
    : WHILE '(' expresion ')' sentencia
        { sent_agregar(estado_global, "while", @1.first_line, @1.first_column); }
    | DO sentencia WHILE '(' expresion ')' ';'
        { sent_agregar(estado_global, "do/while", @1.first_line, @1.first_column); }
    | FOR '(' expresion_opt ';' expresion_opt ';' expresion_opt ')' sentencia
        { sent_agregar(estado_global, "for", @1.first_line, @1.first_column); }
    | FOR '(' declaracion expresion_opt ';' expresion_opt ')' sentencia
        { sent_agregar(estado_global, "for", @1.first_line, @1.first_column); }
    ;

expresion_opt
    : /* empty */
    | expresion
    ;

sentencia_salto
    : CONTINUE ';'
        { sent_agregar(estado_global, "continue", @1.first_line, @1.first_column);limpiarPilaErrorSintactico(); }
    | BREAK ';'
        { sent_agregar(estado_global, "break", @1.first_line, @1.first_column); limpiarPilaErrorSintactico();}
    | RETURN ';'
        { sent_agregar(estado_global, "return", @1.first_line, @1.first_column); }
    | RETURN expresion ';'
        { 
            sent_agregar(estado_global, "return", @1.first_line, @1.first_column);
            validarReturnConExpresion($2, @2.first_line, @2.first_column);
            free($2);
        }
    ;

/* ---- DECLARACIONES ---- */

declaracion
    : especificadores_declaracion ';'
     { 
        char* tipoDeclaracion = desapilar(&pilaTipos);
        free(tipoDeclaracion);
        limpiarPilaErrorSintactico(); }
    | especificadores_declaracion lista_declaradores ';'
        { 
            char* tipoDeclaracion = desapilar(&pilaTipos);
            free(tipoDeclaracion);
            limpiarPilaErrorSintactico();
        }
    ;

especificadores_declaracion
    : especificador_tipo
        { 
            apilar(&pilaTipos, $1);
            free($1);
        }
    | especificadores_declaracion especificador_tipo
        { 
            char* tipoActual = desapilar(&pilaTipos);
            size_t longitudNuevoTipo = strlen(tipoActual) + strlen($2) + 2;
            char* nuevoTipo = malloc(longitudNuevoTipo);
            snprintf(nuevoTipo, longitudNuevoTipo, "%s %s", tipoActual, $2);
            apilar(&pilaTipos, nuevoTipo);
            free(tipoActual);
            free($2);
        }
    ;

especificador_tipo
    : ESPECIFICADOR_TIPO 
        {
            $$ = guardarCadena($1); 
            free($1); 
        }
    ;

lista_declaradores
    : declarador
    | lista_declaradores ',' declarador
    ;

declarador
    : IDENTIFICADOR
        { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            var_agregar($1, tipoDeclaracion, @1.first_line, @1.first_column);
            free($1);
        }
    | IDENTIFICADOR ASSIGN expresion
        { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            if (var_agregar($1, tipoDeclaracion, @1.first_line, @1.first_column) && strcmp($3, "unknown") != 0) {
                validarInicializacion(tipoDeclaracion, $3, @3.first_line, @3.first_column);
            }
                
            free($1);
            free($3);
        }
    ;

/* ---- DEFINICIONES DE FUNCIONES ---- */

definicion_funcion
    : especificadores_declaracion IDENTIFICADOR '(' lista_parametros_opt ')' sentencia_compuesta
        { 
            char* tipoDefinicion = consultarTope(&pilaTipos);
            func_agregar($2, tipoDefinicion, FUNCION_DEF, @2.first_line, @2.first_column);
            free($2);
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        }
    | VOID IDENTIFICADOR '(' lista_parametros_opt ')' sentencia_compuesta
        {
            func_agregar($2, "void", FUNCION_DEF, @2.first_line, @2.first_column);
            free($1);
            free($2);
        }
    ;

lista_parametros
    : parametro
    | lista_parametros ',' parametro
    ;

parametro
    : especificador_tipo IDENTIFICADOR 
        { 
            encolar(&colaParametros, $1, $2, @2.first_column, -1);
            free($1);
            free($2);
        }
    | especificadores_declaracion IDENTIFICADOR
        { 
            char* tipoCompuestoParametro = consultarTope(&pilaTipos);
            encolar(&colaParametros, tipoCompuestoParametro, $2, @2.first_column, -1);
            free($2);
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        }
    | especificador_tipo
        { 
            encolar(&colaParametros, $1, NULL, @1.first_column, -1); 
            free($1);
        }
    | especificadores_declaracion
        { 
            char* tipoCompuestoParametro = consultarTope(&pilaTipos);
            encolar(&colaParametros, tipoCompuestoParametro, NULL, @1.first_column, -1);
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        }
    ;

%%

int main(int argc, char *argv[]) {
    int existeParametroSalida = 1;
    
    // Verifico cantidad de argumentos
    switch (argc) {
    case 1:
        printf("Se necesita al menos un parametro, opcional, parametro archivo salida: %s <archivo_entrada> [<archivo_salida>]\n", argv[0]);
        printf("Ejemplo: %s datos.txt resultados.txt\n", argv[0]);
        return 1;
        break;

    case 2:
        existeParametroSalida = 0;
        break;
    
    default:
        // Codigo para manejar posibles errores
        break;
    }

    if (argc > 3) {
        printf("Se esperaban maximo 2 parametros adicionales: %s <archivo_entrada> [<archivo_salida>]\n", argv[0]);
        printf("Ejemplo: %s datos.txt resultados.txt\n", argv[0]);
        printf("\n[INFO] Utilizando %s como ruta archivo entrada y %s ruta salida... ", argv[1], argv[2]);
        return 1;
    }

    const char* pathEntrada = argv[1];
    const char* pathSalida = NULL;

    if (existeParametroSalida) {
        pathSalida = argv[2];
        yyout = fopen(pathSalida, "w");	
    }

    yyin = fopen(pathEntrada, "r");

    // Crear el estado del compilador
    estado_global = crearEstadoCompilador();
    if (!estado_global) {
        fprintf(stderr, "Error al inicializar el compilador\n");
        return EXIT_FAILURE;
    }

    inicializarUbicacion();
    
    // Se inicializan las pilas
    agregarPila(&pilaVariables);
    agregarPila(&pilaParametros);
    agregarPila(&pilaErrorSintactico);
    agregarPila(&pilaColumnasVariables);
    agregarPila(&pilaParametrosInvocacion);
    agregarPila(&pilaTipos);
    agregarCola(&colaParametros);
    agregarCola(&colaParametrosInvocacion);
    agregarCola(&colaVariables);

    #if YYDEBUG
        yydebug = 1;
    #endif

    yyparse();

    mostrarReporte();
    liberarMemoria();
    destruirEstadoCompilador(estado_global);
    fclose(yyin);
    if (existeParametroSalida) fclose(yyout);
    return 0;
}

void yyerror(const char* literalCadena) {
    char* linea_con_error = generarLineaDesdePila();
    
    if (linea_con_error && strlen(linea_con_error) > 0) {
        err_agregarEstructuraNoReconocida(estado_global, linea_con_error, yylloc.first_line-1);
    } else {
        err_agregarEstructuraNoReconocida(estado_global, "error de sintaxis", yylloc.first_line-1);
    }
    
    if (linea_con_error) {
        free(linea_con_error);
    }
}