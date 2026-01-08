#ifndef GENERAL_H
#define GENERAL_H
#define YYLTYPE YYLTYPE
#define INICIO_CONTEO_LINEA 1
#define INICIO_CONTEO_COLUMNA 1

typedef struct YYLTYPE {
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;

typedef struct {
    char* texto;
    char* tipoDato;
    int linea;
    int ordenDeclaracion;
} TipoVariablesDeclaradas;

typedef struct {
    char* nombreFuncion;
    char* parametrosRecibidos;
    char* tipoQueRetorna;
    int linea;
    char* tipoInicializacion;
} TipoFuncionesDeclaradasODefinidas;

typedef struct {
    char* tipo;
    int linea;
    int columna;
} TipoSentencias;

typedef struct {
    char* estructuraNoReconocida;
    int linea;
} TipoEstructurasSintacticasNoReconocidas;

typedef struct {
    char* texto;
    int linea;
    int columna;
} TipoCadenasNoReconocida;

// ----------------------- VARIABLES GLOBALES -------------------

extern YYLTYPE yylloc;

// ----------------------- FUNCIONES ----------------------------

void inicializarUbicacion(void);
char* guardarCadena(char*);
int compararSentenciasPorLinea(const void*, const void*);
int compararVariablesPorLinea(const void*, const void*);
void agregarVariablesDeclaradas(char*, char*, int);
void imprimirVariablesDeclaradas();
void agregarSentencias(char*, int, int);
void imprimirSentencias();
void agregarCadenasNoReconocidas(char*, int, int);
void imprimirCadenasNoReconocidas();
void agregarFuncionesDeclaradasODefinidas(char*, char*, char*, int, char*);
void imprimirFuncionesDeclaradasODefinidas();
void agregarEstructurasSintacticasNoReconocidas(char*, int);
void imprimirEstructurasNoReconocidas();
void mostrarReporte();
void liberarMemoria();
void agregarParametro(char*, char*);
void resetearParametros();
char* obtenerListaParametros();
#endif