%{
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include <string.h>

%}

%pointer
%option noyywrap
%x tokenNoReconocido

DIGITO_DECIMAL [0-9]
DIGITO_DECIMAL_SIN_CERO [1-9]
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [0-9a-fA-F]
NO_DIGITO [_a-zA-Z]
IDENTIFICADOR {NO_DIGITO}({NO_DIGITO}|{DIGITO_DECIMAL})*

SUFIJO_UNSIGNED (u|U)
SUFIJO_LONG (l|L)
SUFIJO_ENTERO ({SUFIJO_UNSIGNED}{SUFIJO_LONG}?|{SUFIJO_LONG}{SUFIJO_UNSIGNED}?)
SUFIJO_FLOTANTE ([fFlL])

PARTE_ENTERA {DIGITO_DECIMAL}+
PARTE_FRACCION ("."{DIGITO_DECIMAL}*)
PARTE_EXPONENTE (e|E)("+"|"-")?{DIGITO_DECIMAL}+

CONSTANTE_REAL ({PARTE_ENTERA}{PARTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_FLOTANTE}?|{PARTE_FRACCION}{PARTE_EXPONENTE}?{SUFIJO_FLOTANTE}?|{PARTE_ENTERA}{PARTE_EXPONENTE}{SUFIJO_FLOTANTE}?)

CONSTANTE_ENTERA_DECIMAL {DIGITO_DECIMAL_SIN_CERO}{DIGITO_DECIMAL}*{SUFIJO_ENTERO}? 
CONSTANTE_ENTERA_OCTAL 0{DIGITO_OCTAL}*{SUFIJO_ENTERO}? 
CONSTANTE_ENTERA_HEXADECIMAL 0(x|X){DIGITO_HEXADECIMAL}+{SUFIJO_ENTERO}? 
CONSTANTE_ENTERA ({CONSTANTE_ENTERA_DECIMAL}|{CONSTANTE_ENTERA_OCTAL}|{CONSTANTE_ENTERA_HEXADECIMAL}|0{SUFIJO_ENTERO}?)

CADENA_LITERAL \"([^\\\n"]|\\.)*\"

%%

"if"        { return IF; }
"else"      { return ELSE; }
"switch"    { return SWITCH; }
"while"     { return WHILE; }
"do"        { return DO; }
"for"       { return FOR; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }
"return"    { yylloc.last_column += yyleng;  return RETURN; }

"const"     { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"void"      { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return VOID; }
"char"      { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"short"     { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"int"       { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"long"      { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"float"     { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"double"    { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"signed"    { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }
"unsigned"  { yylval.string_type = guardarCadena(yytext); yylloc.last_column += yyleng; return ESPECIFICADOR_TIPO; }

"="         { apilar(&pilaErrorSintactico, guardarCadena(yytext)); yylloc.last_column += yyleng; return ASSIGN; }
"=="        { return EQ; }
"!="        { return NE; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LE; }
">="        { return GE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { yylloc.last_column += yyleng; return STAR; }
"/"         { return SLASH; }
"++"        { return PLUSPLUS; }
"--"        { return MINUSMINUS; }
"+="        { return ADD_ASSIGN; }
"-="        { return SUB_ASSIGN; }
"*="        { return MUL_ASSIGN; }
"/="        { return DIV_ASSIGN; }
"&&"        { return AND; }
"||"        { return OR; }
";"         { return ';'; }
","         { yylloc.last_column += yyleng; return ','; }
"("         { yylloc.last_column += yyleng; return '('; }
")"         { yylloc.last_column += yyleng; return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
":"         { return ':'; }

'(\\.|[^\\'\n])'  {
    yylloc.last_column += yyleng;
    yylval.unsigned_long_type = yytext[1];
    return CONSTANTE;
}

{CONSTANTE_REAL} {
    apilar(&pilaErrorSintactico, guardarCadena(yytext));
    yylloc.last_column += yyleng;
    yylval.double_type = atof(yytext);  
    return CONSTANTE_REAL;
}

{CONSTANTE_ENTERA} {
    yylloc.last_column += yyleng;
    yylval.unsigned_long_type = strtoul(yytext, NULL, 0);
    return CONSTANTE;
}

{IDENTIFICADOR} {
    apilar(&pilaErrorSintactico, guardarCadena(yytext));
    yylloc.first_column = yylloc.last_column;
    yylloc.last_column += yyleng;
    yylval.string_type = guardarCadena(yytext);
    return IDENTIFICADOR;
}

{CADENA_LITERAL} {
    yylloc.first_column = yylloc.last_column;
    yylloc.last_column += yyleng;
    yylval.string_type = guardarCadena(yytext);
    return STRING_LITERAL;
}

[ \t]+ {
    yylloc.first_column = yylloc.last_column += yyleng; 
}

\n {
    yylloc.first_line = yylloc.last_line += 1;
    yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA;
}

. {
    yyless(0);
    BEGIN(tokenNoReconocido);
}

<tokenNoReconocido>{
    <<EOF>> {
        BEGIN(INITIAL);
    }
    " "|\t|\n {
        yyless(0);
        BEGIN(INITIAL); 
    }
    [^ \t\n]+ {
        err_agregarCadenaNoReconocida(estado_global, yytext, yylloc.first_line, yylloc.first_column);
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
    }
}
%%