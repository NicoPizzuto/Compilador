%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "general.h"
#include "pila.h"

extern int yylex(void);
extern FILE* yyin;
extern FILE* yyout;
void yyerror(const char*);

char tipo_actual[100];

%}

%error-verbose 
%locations

%union {
    unsigned long unsigned_long_type;
    double double_type;
    char string_type[30];
}

/* Declaraciones de precedencia (de menor a mayor precedencia) */
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN
%left OR
%left AND
%left EQ NE
%left LT GT LE GE
%left PLUS MINUS
%left STAR SLASH
%right PLUSPLUS MINUSMINUS UNARY_MINUS
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

%type <string_type> especificador_tipo
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
            agregarEstructurasSintacticasNoReconocidas(estructura, @1.first_line);
        }
    | expresion ';'
        {
            agregarEstructurasSintacticasNoReconocidas("expresion;", @1.first_line);
        }
;

declaracion_externa
    : declaracion
    | prototipo_funcion
    ;

prototipo_funcion
    : especificador_tipo IDENTIFICADOR '(' lista_parametros_opt ')' ';'
        { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas($2, params_copia, $1, @2.first_line, "declaracion");
        }
    | VOID IDENTIFICADOR '(' lista_parametros_opt ')' ';'
        { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas($2, params_copia, "void", @2.first_line, "declaracion");
        }
    ;

lista_parametros_opt
    : /* empty */
    | VOID
    | lista_parametros
    ;

/* ---- EXPRESIONES ---- */

expresion
    : expresion_asignacion
    ;

expresion_asignacion
    : expresion_logica_or
    | IDENTIFICADOR ASSIGN expresion_asignacion
    | IDENTIFICADOR ADD_ASSIGN expresion_asignacion
    | IDENTIFICADOR SUB_ASSIGN expresion_asignacion
    | IDENTIFICADOR MUL_ASSIGN expresion_asignacion
    | IDENTIFICADOR DIV_ASSIGN expresion_asignacion
    ;

expresion_logica_or
    : expresion_logica_and
    | expresion_logica_or OR expresion_logica_and
    ;

expresion_logica_and
    : expresion_igualdad
    | expresion_logica_and AND expresion_igualdad
    ;

expresion_igualdad
    : expresion_relacional
    | expresion_igualdad EQ expresion_relacional
    | expresion_igualdad NE expresion_relacional
    ;

expresion_relacional
    : expresion_aditiva
    | expresion_relacional LT expresion_aditiva
    | expresion_relacional GT expresion_aditiva
    | expresion_relacional LE expresion_aditiva
    | expresion_relacional GE expresion_aditiva
    ;

expresion_aditiva
    : expresion_multiplicativa
    | expresion_aditiva PLUS expresion_multiplicativa
    | expresion_aditiva MINUS expresion_multiplicativa
    ;

expresion_multiplicativa
    : expresion_unaria
    | expresion_multiplicativa STAR expresion_unaria
    | expresion_multiplicativa SLASH expresion_unaria
    ;

expresion_unaria
    : expresion_postfija
    | PLUSPLUS IDENTIFICADOR
    | MINUSMINUS IDENTIFICADOR
    | MINUS expresion_unaria %prec UNARY_MINUS
    ;

expresion_postfija
    : expresion_primaria
    | IDENTIFICADOR '(' lista_argumentos_invocacion ')'
    | IDENTIFICADOR PLUSPLUS
    | IDENTIFICADOR MINUSMINUS
    ;

expresion_primaria
    : IDENTIFICADOR
    | CONSTANTE
    | CONSTANTE_REAL
    | STRING_LITERAL
    | '(' expresion ')'
    ;

lista_argumentos_invocacion
    : /* empty */
    | lista_expresiones
    ;

lista_expresiones
    : expresion
    | lista_expresiones ',' expresion
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
        { agregarSentencias("case", @1.first_line, @1.first_column); }
    | DEFAULT ':' sentencia
        { agregarSentencias("default", @1.first_line, @1.first_column); }
    | CASE expresion ':'
        { agregarSentencias("case", @1.first_line, @1.first_column); }
    | DEFAULT ':'
        { agregarSentencias("default", @1.first_line, @1.first_column); }
    ;

sentencia_expresion
    : ';'
    | expresion ';'
    ;

sentencia_compuesta
    : '{' '}'
    | '{' lista_elementos_bloque '}'
    | '{' lista_elementos_bloque error '}'
        { yyerrok; }
    | '{' error '}'
        { yyerrok; }
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
        { agregarSentencias("if", @1.first_line, @1.first_column); }
    | IF '(' expresion ')' sentencia ELSE sentencia
        { agregarSentencias("if/else", @1.first_line, @1.first_column); }
    | SWITCH '(' expresion ')' sentencia
        { agregarSentencias("switch", @1.first_line, @1.first_column); }
    ;

sentencia_iteracion
    : WHILE '(' expresion ')' sentencia
        { agregarSentencias("while", @1.first_line, @1.first_column); }
    | DO sentencia WHILE '(' expresion ')' ';'
        { agregarSentencias("do/while", @1.first_line, @1.first_column); }
    | FOR '(' expresion_opt ';' expresion_opt ';' expresion_opt ')' sentencia
        { agregarSentencias("for", @1.first_line, @1.first_column); }
    | FOR '(' declaracion expresion_opt ';' expresion_opt ')' sentencia
        { agregarSentencias("for", @1.first_line, @1.first_column); }
    ;

expresion_opt
    : /* empty */
    | expresion
    ;

sentencia_salto
    : CONTINUE ';'
        { agregarSentencias("continue", @1.first_line, @1.first_column); }
    | BREAK ';'
        { agregarSentencias("break", @1.first_line, @1.first_column); }
    | RETURN ';'
        { agregarSentencias("return", @1.first_line, @1.first_column); }
    | RETURN expresion ';'
        { agregarSentencias("return", @1.first_line, @1.first_column); }
    ;

/* ---- DECLARACIONES ---- */

declaracion
    : especificadores_declaracion ';'
    | especificadores_declaracion lista_declaradores ';'
        { agregarVariablesDeclaradas("", tipo_actual, @1.first_line); }
    ;

especificadores_declaracion
    : especificador_tipo
        { strcpy(tipo_actual, $1); }
    | especificador_tipo especificador_tipo
        { 
            strcpy(tipo_actual, $1);
            strcat(tipo_actual, " ");
            strcat(tipo_actual, $2);
        }
    ;

especificador_tipo
    : ESPECIFICADOR_TIPO  
        { strcpy($$, $1); }
    | VOID  
        { strcpy($$, "void"); }
    ;

lista_declaradores
    : declarador
    | lista_declaradores ',' declarador
    ;

declarador
    : IDENTIFICADOR
        { apilar(&pilaVariables, $1); }
    | IDENTIFICADOR ASSIGN expresion
        { apilar(&pilaVariables, $1); }
    | IDENTIFICADOR ASSIGN CONSTANTE
        { apilar(&pilaVariables, $1); }
    | IDENTIFICADOR ASSIGN CONSTANTE_REAL
        { apilar(&pilaVariables, $1); }
    ;

/* ---- DEFINICIONES DE FUNCIONES ---- */

definicion_funcion
    : especificador_tipo IDENTIFICADOR '(' lista_parametros_opt ')' sentencia_compuesta
        { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas($2, params_copia, $1, @2.first_line, "definicion");
        }
    | VOID IDENTIFICADOR '(' lista_parametros_opt ')' sentencia_compuesta
        {
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas($2, params_copia, "void", @2.first_line, "definicion");
        }
    ;

lista_parametros
    : parametro
    | lista_parametros ',' parametro
    ;

parametro
    : especificador_tipo IDENTIFICADOR 
        { agregarParametro($1, $2); }
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

    inicializarUbicacion();
    
    // Se inicializan las pilas
    agregarPila(&pilaVariables);
    agregarPila(&pilaParametros);

    #if YYDEBUG
        yydebug = 1;
    #endif

    yyparse();

    mostrarReporte();
    liberarMemoria();
    fclose(yyin);
    if (existeParametroSalida) fclose(yyout);
    return 0;
}

void yyerror(const char* literalCadena) {
    fprintf(stderr, "Bison: %d:%d: %s\n", yylloc.first_line, yylloc.first_column, literalCadena);
}