
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "src/parser.y"

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



/* Line 189 of yacc.c  */
#line 95 "obj/src/parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIV_ASSIGN = 258,
     MUL_ASSIGN = 259,
     SUB_ASSIGN = 260,
     ADD_ASSIGN = 261,
     ASSIGN = 262,
     OR = 263,
     AND = 264,
     NE = 265,
     EQ = 266,
     GE = 267,
     LE = 268,
     GT = 269,
     LT = 270,
     MINUS = 271,
     PLUS = 272,
     SLASH = 273,
     STAR = 274,
     MINUSMINUS = 275,
     PLUSPLUS = 276,
     ESPECIFICADOR_TIPO = 277,
     IF = 278,
     ELSE = 279,
     DEFAULT = 280,
     CASE = 281,
     STRING_LITERAL = 282,
     SWITCH = 283,
     BREAK = 284,
     FOR = 285,
     DO = 286,
     WHILE = 287,
     CONTINUE = 288,
     RETURN = 289,
     VOID = 290,
     IDENTIFICADOR = 291,
     CONSTANTE = 292,
     CONSTANTE_REAL = 293
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 25 "src/parser.y"

    unsigned long unsigned_long_type;
    double double_type;
    char* string_type;



/* Line 214 of yacc.c  */
#line 177 "obj/src/parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "obj/src/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      22,    23,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    16,    19,
      24,    27,    29,    31,    38,    45,    46,    48,    50,    52,
      54,    58,    62,    66,    70,    74,    78,    82,    84,    88,
      90,    94,    96,   100,   104,   106,   110,   114,   118,   122,
     124,   128,   132,   134,   138,   142,   144,   147,   150,   153,
     155,   160,   163,   166,   168,   170,   172,   174,   178,   179,
     181,   183,   187,   189,   191,   193,   195,   197,   199,   204,
     208,   212,   215,   220,   224,   226,   229,   232,   235,   239,
     244,   248,   250,   253,   256,   258,   260,   262,   268,   276,
     282,   288,   296,   306,   315,   316,   318,   321,   324,   327,
     331,   334,   338,   340,   343,   345,   347,   351,   353,   357,
     364,   371,   373,   377,   380,   383,   385
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    -1,    47,    48,    -1,    81,    -1,    50,
      -1,    49,    -1,     1,    41,    -1,     1,    42,    -1,    38,
       7,    38,    41,    -1,    53,    41,    -1,    76,    -1,    51,
      -1,    77,    38,    22,    52,    23,    41,    -1,    37,    38,
      22,    52,    23,    41,    -1,    -1,    37,    -1,    82,    -1,
      54,    -1,    55,    -1,    39,     7,    54,    -1,    40,     7,
      54,    -1,    38,     7,    54,    -1,    38,     6,    54,    -1,
      38,     5,    54,    -1,    38,     4,    54,    -1,    38,     3,
      54,    -1,    56,    -1,    55,     8,    56,    -1,    57,    -1,
      56,     9,    57,    -1,    58,    -1,    57,    11,    58,    -1,
      57,    10,    58,    -1,    59,    -1,    58,    15,    59,    -1,
      58,    14,    59,    -1,    58,    13,    59,    -1,    58,    12,
      59,    -1,    60,    -1,    59,    17,    60,    -1,    59,    16,
      60,    -1,    61,    -1,    60,    19,    61,    -1,    60,    18,
      61,    -1,    62,    -1,    21,    38,    -1,    20,    38,    -1,
      16,    61,    -1,    63,    -1,    38,    22,    64,    23,    -1,
      38,    21,    -1,    38,    20,    -1,    38,    -1,    39,    -1,
      40,    -1,    29,    -1,    22,    53,    23,    -1,    -1,    65,
      -1,    53,    -1,    65,    43,    53,    -1,    67,    -1,    68,
      -1,    69,    -1,    72,    -1,    73,    -1,    75,    -1,    28,
      53,    44,    66,    -1,    27,    44,    66,    -1,    28,    53,
      44,    -1,    27,    44,    -1,    28,    53,    44,     1,    -1,
      27,    44,     1,    -1,    41,    -1,    53,    41,    -1,    53,
       1,    -1,    45,    42,    -1,    45,    70,    42,    -1,    45,
      70,     1,    42,    -1,    45,     1,    42,    -1,    71,    -1,
      70,    71,    -1,    70,     1,    -1,     1,    -1,    76,    -1,
      66,    -1,    25,    22,    53,    23,    66,    -1,    25,    22,
      53,    23,    66,    26,    66,    -1,    30,    22,    53,    23,
      66,    -1,    34,    22,    53,    23,    66,    -1,    33,    66,
      34,    22,    53,    23,    41,    -1,    32,    22,    74,    41,
      74,    41,    74,    23,    66,    -1,    32,    22,    76,    74,
      41,    74,    23,    66,    -1,    -1,    53,    -1,    35,    41,
      -1,    31,    41,    -1,    36,    41,    -1,    36,    53,    41,
      -1,    77,    41,    -1,    77,    79,    41,    -1,    78,    -1,
      77,    78,    -1,    24,    -1,    80,    -1,    79,    43,    80,
      -1,    38,    -1,    38,     7,    53,    -1,    77,    38,    22,
      52,    23,    69,    -1,    37,    38,    22,    52,    23,    69,
      -1,    83,    -1,    82,    43,    83,    -1,    78,    38,    -1,
      77,    38,    -1,    78,    -1,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    66,    70,    71,    72,    73,    75,    80,
      86,    93,    94,    98,   107,   116,   118,   119,   126,   131,
     133,   144,   147,   159,   162,   165,   168,   174,   176,   180,
     182,   186,   188,   189,   193,   195,   196,   197,   198,   202,
     204,   205,   209,   211,   217,   223,   225,   230,   231,   236,
     238,   242,   243,   247,   252,   256,   260,   265,   274,   275,
     280,   284,   293,   294,   295,   296,   297,   298,   302,   304,
     306,   308,   310,   315,   323,   325,   327,   334,   335,   336,
     338,   345,   346,   347,   349,   354,   355,   359,   364,   369,
     377,   379,   381,   383,   387,   389,   393,   395,   397,   399,
     410,   415,   424,   429,   442,   450,   451,   455,   461,   476,
     484,   493,   494,   498,   504,   512,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIV_ASSIGN", "MUL_ASSIGN", "SUB_ASSIGN",
  "ADD_ASSIGN", "ASSIGN", "OR", "AND", "NE", "EQ", "GE", "LE", "GT", "LT",
  "MINUS", "PLUS", "SLASH", "STAR", "MINUSMINUS", "PLUSPLUS", "'('", "')'",
  "ESPECIFICADOR_TIPO", "IF", "ELSE", "DEFAULT", "CASE", "STRING_LITERAL",
  "SWITCH", "BREAK", "FOR", "DO", "WHILE", "CONTINUE", "RETURN", "VOID",
  "IDENTIFICADOR", "CONSTANTE", "CONSTANTE_REAL", "';'", "'}'", "','",
  "':'", "'{'", "$accept", "programa", "elemento_programa",
  "sentencia_expresion_global", "declaracion_externa", "prototipo_funcion",
  "lista_parametros_opt", "expresion", "expresion_asignacion",
  "expresion_logica_or", "expresion_logica_and", "expresion_igualdad",
  "expresion_relacional", "expresion_aditiva", "expresion_multiplicativa",
  "expresion_unaria", "expresion_postfija", "expresion_primaria",
  "lista_argumentos_invocacion", "lista_expresiones", "sentencia",
  "sentencia_etiquetada", "sentencia_expresion", "sentencia_compuesta",
  "lista_elementos_bloque", "elemento_bloque", "sentencia_seleccion",
  "sentencia_iteracion", "expresion_opt", "sentencia_salto", "declaracion",
  "especificadores_declaracion", "especificador_tipo",
  "lista_declaradores", "declarador", "definicion_funcion",
  "lista_parametros", "parametro", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    40,    41,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,    59,   125,    44,    58,   123
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    72,    72,    72,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     2,     4,
       2,     1,     1,     6,     6,     0,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     2,     2,     2,     1,
       4,     2,     2,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       3,     2,     4,     3,     1,     2,     2,     2,     3,     4,
       3,     1,     2,     2,     1,     1,     1,     5,     7,     5,
       5,     7,     9,     8,     0,     1,     2,     2,     2,     3,
       2,     3,     1,     2,     1,     1,     3,     1,     3,     6,
       6,     1,     3,     2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,   104,    56,
       0,    53,    54,    55,     3,     6,     5,    12,     0,    18,
      19,    27,    29,    31,    34,    39,    42,    45,    49,    11,
       0,   102,     4,     7,     8,    53,    54,    55,    48,    47,
      46,    53,     0,     0,     0,     0,     0,     0,     0,    52,
      51,    58,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   100,   103,
       0,   105,     0,    57,    15,    26,    25,    24,    23,    53,
      22,    60,     0,    59,    20,    21,    28,    30,    33,    32,
      38,    37,    36,    35,    41,    40,    44,    43,     0,    15,
     101,     0,    16,     0,   116,   102,    17,   111,     9,    50,
       0,   108,     0,   107,   106,     0,   114,   113,     0,    61,
       0,    14,     0,   110,   112,    13,   109,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    77,
       0,    86,    62,    63,    64,     0,    81,    65,    66,    67,
      85,     0,    80,     0,     0,     0,     0,    97,    94,     0,
       0,    96,    98,     0,    76,    75,    83,    78,    82,     0,
      73,    69,     0,     0,    95,     0,    94,     0,     0,    99,
      79,     0,    72,    68,     0,    94,     0,     0,     0,    87,
      89,     0,    94,     0,    90,     0,    94,     0,     0,    88,
       0,     0,    91,     0,    93,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,    15,    16,    17,   103,   140,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    82,    83,
     141,   142,   143,   144,   145,   146,   147,   148,   175,   149,
     150,   104,    31,    70,    71,    32,   106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
    -157,    41,  -157,    42,   104,   -15,    15,   333,  -157,  -157,
      18,   143,    37,    68,  -157,  -157,  -157,  -157,    26,  -157,
      65,    82,    83,    86,    94,    84,  -157,  -157,  -157,  -157,
     -20,  -157,  -157,  -157,  -157,    -5,  -157,  -157,  -157,  -157,
    -157,   372,    96,    93,   333,   333,   333,   333,   345,  -157,
    -157,   333,   333,   333,  -157,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,    38,  -157,  -157,
     -19,  -157,   333,  -157,    40,  -157,  -157,  -157,  -157,     6,
    -157,  -157,   111,    98,  -157,  -157,    82,    83,    86,    86,
      94,    94,    94,    94,    84,    84,  -157,  -157,   333,    40,
    -157,    97,  -157,   128,    11,   115,   113,  -157,  -157,  -157,
     333,  -157,   131,   154,  -157,    44,  -157,  -157,   138,  -157,
      51,  -157,   244,  -157,  -157,  -157,  -157,   124,   145,   125,
     333,   146,   129,   149,   307,   150,   133,    66,  -157,  -157,
       7,  -157,  -157,  -157,  -157,   280,  -157,  -157,  -157,  -157,
    -157,    13,  -157,   333,   172,   132,   333,  -157,    92,   144,
     333,  -157,  -157,   136,  -157,  -157,   137,  -157,  -157,   157,
    -157,  -157,   208,   158,  -157,   141,   333,   161,   162,  -157,
    -157,   307,  -157,  -157,   307,   333,   148,   333,   307,   164,
    -157,   174,   333,   193,  -157,   307,   333,   195,   178,  -157,
     197,   307,  -157,   307,  -157,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,  -157,  -157,    88,    -1,   -14,  -157,
     166,   167,    60,    78,    64,     3,  -157,  -157,  -157,  -157,
    -129,  -157,  -157,  -101,  -157,    77,  -157,  -157,  -156,  -157,
       2,     0,   -28,  -157,   126,  -157,  -157,   107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -72
static const yytype_int16 yytable[] =
{
      18,    30,    69,    29,     8,   159,    42,    38,   164,    44,
      45,    46,    47,    72,   123,    49,    50,    51,    67,   126,
     186,    68,   100,    39,   101,   171,    49,    50,    51,   191,
      75,    76,    77,    78,    80,     8,   197,     8,    84,    85,
     200,     2,     3,   183,    52,    98,   105,   108,   165,   116,
      81,   113,   189,    40,    68,   190,    43,     4,    80,   194,
      99,     5,     6,     7,     8,     8,   199,    54,    96,    97,
       9,   105,   204,    55,   205,    53,    69,   102,    10,    11,
      12,    13,     4,    33,    34,   121,     5,     6,     7,   122,
     105,    56,   125,    57,    58,     9,   122,   111,    59,    60,
      61,    62,    65,    66,    41,    12,    13,   162,     4,   119,
      63,    64,     5,     6,     7,    74,     8,    88,    89,    73,
       4,     9,   151,    69,     5,     6,     7,    94,    95,   155,
      41,    12,    13,     9,   109,   113,   163,    90,    91,    92,
      93,   110,    35,    36,    37,   151,    44,    45,    46,    47,
      48,   115,   169,   117,   120,   173,   118,   174,   151,   178,
     176,    98,     8,    49,    50,    51,   152,   153,   156,   154,
     157,   158,   160,   170,   161,   174,   172,   179,   177,   180,
     181,   184,   185,   187,   174,   188,   193,   112,     4,   192,
     195,   174,     5,     6,     7,   174,   -71,   128,   -71,   129,
     130,     9,   131,   132,   133,   134,   135,   136,   137,   182,
      41,    12,    13,   138,   -71,   196,   198,   122,   201,   202,
     203,    86,   168,    87,     4,   124,     0,   114,     5,     6,
       7,     0,   -70,   128,   -70,   129,   130,     9,   131,   132,
     133,   134,   135,   136,   137,   127,    41,    12,    13,   138,
     -70,     0,     0,   122,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     5,     6,     7,     0,     8,   128,
       0,   129,   130,     9,   131,   132,   133,   134,   135,   136,
     137,   166,    41,    12,    13,   138,   139,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       5,     6,     7,     0,     8,   128,     0,   129,   130,     9,
     131,   132,   133,   134,   135,   136,   137,     0,    41,    12,
      13,   138,   167,     4,     0,   122,     0,     5,     6,     7,
       0,     0,   128,     0,   129,   130,     9,   131,   132,   133,
     134,   135,   136,   137,     0,    41,    12,    13,   138,     4,
       0,     0,   122,     5,     6,     7,     0,     0,     0,     0,
       0,     4,     9,     0,     0,     5,     6,     7,     0,     0,
       0,    41,    12,    13,     9,    44,    45,    46,    47,    72,
       0,     0,     0,    79,    12,    13,     0,     0,     0,     0,
       0,     0,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
       1,     1,    30,     1,    24,   134,     7,     4,     1,     3,
       4,     5,     6,     7,   115,    20,    21,    22,    38,   120,
     176,    41,    41,    38,    43,   154,    20,    21,    22,   185,
      44,    45,    46,    47,    48,    24,   192,    24,    52,    53,
     196,     0,     1,   172,     7,     7,    74,    41,    41,    38,
      51,    38,   181,    38,    41,   184,    38,    16,    72,   188,
      22,    20,    21,    22,    24,    24,   195,    41,    65,    66,
      29,    99,   201,     8,   203,     7,   104,    37,    37,    38,
      39,    40,    16,    41,    42,    41,    20,    21,    22,    45,
     118,     9,    41,    10,    11,    29,    45,    98,    12,    13,
      14,    15,    18,    19,    38,    39,    40,    41,    16,   110,
      16,    17,    20,    21,    22,    22,    24,    57,    58,    23,
      16,    29,   122,   151,    20,    21,    22,    63,    64,   130,
      38,    39,    40,    29,    23,    38,   137,    59,    60,    61,
      62,    43,    38,    39,    40,   145,     3,     4,     5,     6,
       7,    23,   153,    38,    23,   156,    43,   158,   158,   160,
     158,     7,    24,    20,    21,    22,    42,    22,    22,    44,
      41,    22,    22,     1,    41,   176,    44,    41,    34,    42,
      23,    23,    41,    22,   185,    23,   187,    99,    16,    41,
      26,   192,    20,    21,    22,   196,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,     1,
      38,    39,    40,    41,    42,    41,    23,    45,    23,    41,
      23,    55,   145,    56,    16,   118,    -1,   101,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     1,    38,    39,    40,    41,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     1,    38,    39,    40,    41,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    -1,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    16,    -1,    45,    -1,    20,    21,    22,
      -1,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    40,    41,    16,
      -1,    -1,    45,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    16,    29,    -1,    -1,    20,    21,    22,    -1,    -1,
      -1,    38,    39,    40,    29,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,     0,     1,    16,    20,    21,    22,    24,    29,
      37,    38,    39,    40,    48,    49,    50,    51,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    76,
      77,    78,    81,    41,    42,    38,    39,    40,    61,    38,
      38,    38,    53,    38,     3,     4,     5,     6,     7,    20,
      21,    22,     7,     7,    41,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    38,    41,    78,
      79,    80,     7,    23,    22,    54,    54,    54,    54,    38,
      54,    53,    64,    65,    54,    54,    56,    57,    58,    58,
      59,    59,    59,    59,    60,    60,    61,    61,     7,    22,
      41,    43,    37,    52,    77,    78,    82,    83,    41,    23,
      43,    53,    52,    38,    80,    23,    38,    38,    43,    53,
      23,    41,    45,    69,    83,    41,    69,     1,    25,    27,
      28,    30,    31,    32,    33,    34,    35,    36,    41,    42,
      53,    66,    67,    68,    69,    70,    71,    72,    73,    75,
      76,    77,    42,    22,    44,    53,    22,    41,    22,    66,
      22,    41,    41,    53,     1,    41,     1,    42,    71,    53,
       1,    66,    44,    53,    53,    74,    76,    34,    53,    41,
      42,    23,     1,    66,    23,    41,    74,    22,    23,    66,
      66,    74,    41,    53,    66,    26,    41,    74,    23,    66,
      74,    23,    41,    23,    66,    66
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 7:

/* Line 1455 of yacc.c  */
#line 74 "src/parser.y"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 76 "src/parser.y"
    { yyerrok; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 81 "src/parser.y"
    {
            char estructura[100]; 
            sprintf(estructura, "%s = %s;", (yyvsp[(1) - (4)].string_type), (yyvsp[(3) - (4)].string_type));
            err_agregarEstructuraNoReconocida(estado_global, estructura, (yylsp[(1) - (4)]).first_line);
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 87 "src/parser.y"
    {
            err_agregarEstructuraNoReconocida(estado_global, "expresion;", (yylsp[(1) - (2)]).first_line);
        ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "src/parser.y"
    { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            func_agregar((yyvsp[(2) - (6)].string_type), tipoDeclaracion, FUNCION_DEC, (yylsp[(2) - (6)]).first_line, (yylsp[(2) - (6)]).first_column);
            free((yyvsp[(2) - (6)].string_type));
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
            limpiarPilaErrorSintactico();
        ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 108 "src/parser.y"
    { 
            func_agregar((yyvsp[(2) - (6)].string_type), "void", FUNCION_DEC, (yylsp[(2) - (6)]).first_line, (yylsp[(2) - (6)]).first_column);
            free((yyvsp[(1) - (6)].string_type));
            free((yyvsp[(2) - (6)].string_type));
            limpiarPilaErrorSintactico();
        ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 118 "src/parser.y"
    { free((yyvsp[(1) - (1)].string_type)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 127 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 132 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 134 "src/parser.y"
    {
        char* mensaje = malloc(512);
        if (mensaje) {
            snprintf(mensaje, 512, "%d:%d: Se requiere un valor-L modificable como operando izquierdo de la asignacion", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column);
            err_agregarSemantico(estado_global, mensaje, (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, NULL);
            free(mensaje);
        }
        free((yyvsp[(3) - (3)].string_type));
        (yyval.string_type) = guardarCadena("unknown");
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "src/parser.y"
    {
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 148 "src/parser.y"
    {
        char* tipoIdentificador = ts_obtenerTipo((yyvsp[(1) - (3)].string_type), (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
        if (strcmp(tipoIdentificador, "unknown") != 0)
            (yyval.string_type) = validarAsignacion((yyvsp[(1) - (3)].string_type), (yyvsp[(3) - (3)].string_type), (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column);
        else
            (yyval.string_type) = guardarCadena("unknown");

        free((yyvsp[(1) - (3)].string_type));
        free((yyvsp[(3) - (3)].string_type));
        free(tipoIdentificador);
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 160 "src/parser.y"
    {
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 163 "src/parser.y"
    {
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 166 "src/parser.y"
    {
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 169 "src/parser.y"
    {
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 175 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 181 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 187 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 194 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 203 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 210 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 212 "src/parser.y"
    {
            (yyval.string_type) = validarMultiplicacion((yyvsp[(1) - (3)].string_type), (yyvsp[(3) - (3)].string_type), (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column);
            free((yyvsp[(1) - (3)].string_type));
            free((yyvsp[(3) - (3)].string_type));
        ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 218 "src/parser.y"
    {
        ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 224 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 226 "src/parser.y"
    {
            (yyval.string_type) = ts_obtenerTipo((yyvsp[(2) - (2)].string_type), (yylsp[(2) - (2)]).first_line, (yylsp[(2) - (2)]).first_column);
            free((yyvsp[(2) - (2)].string_type));
        ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 232 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(2) - (2)].string_type); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 237 "src/parser.y"
    { (yyval.string_type) = (yyvsp[(1) - (1)].string_type); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 239 "src/parser.y"
    {
            (yyval.string_type) = func_verificarInvocacion((yyvsp[(1) - (4)].string_type), (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column);
        ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 248 "src/parser.y"
    {
        (yyval.string_type) = ts_obtenerTipo((yyvsp[(1) - (1)].string_type), (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column);
        free((yyvsp[(1) - (1)].string_type));
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 253 "src/parser.y"
    { 
        (yyval.string_type) = guardarCadena("int");
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 257 "src/parser.y"
    { 
        (yyval.string_type) = guardarCadena("float");
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 261 "src/parser.y"
    { 
        (yyval.string_type) = guardarCadena("char *");
        free((yyvsp[(1) - (1)].string_type));
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 266 "src/parser.y"
    { 
        (yyval.string_type) = guardarCadena((yyvsp[(2) - (3)].string_type));
        free((yyvsp[(2) - (3)].string_type));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 274 "src/parser.y"
    { (yyval.unsigned_long_type) = 0; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 276 "src/parser.y"
    { (yyval.unsigned_long_type) = (yyvsp[(1) - (1)].unsigned_long_type); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 281 "src/parser.y"
    { (yyval.unsigned_long_type) = 1;
      encolar(&colaParametrosInvocacion, (yyvsp[(1) - (1)].string_type), NULL, (yylsp[(1) - (1)]).first_column, -1);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 285 "src/parser.y"
    { (yyval.unsigned_long_type) = (yyvsp[(1) - (3)].unsigned_long_type) + 1;
      encolar(&colaParametrosInvocacion, (yyvsp[(3) - (3)].string_type), NULL, (yylsp[(3) - (3)]).first_column, -1);
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 303 "src/parser.y"
    { sent_agregar(estado_global, "case", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 305 "src/parser.y"
    { sent_agregar(estado_global, "default", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 307 "src/parser.y"
    { sent_agregar(estado_global, "case", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 309 "src/parser.y"
    { sent_agregar(estado_global, "default", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 311 "src/parser.y"
    { 
            yyerrok;
            sent_agregar(estado_global, "case", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); 
        ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 316 "src/parser.y"
    { 
            yyerrok;
            sent_agregar(estado_global, "default", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); 
        ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 324 "src/parser.y"
    { limpiarPilaErrorSintactico(); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 326 "src/parser.y"
    { limpiarPilaErrorSintactico(); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 328 "src/parser.y"
    {
            yyerrok;
        ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 337 "src/parser.y"
    { yyerrok; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 339 "src/parser.y"
    { 
            yyerrok; 
        ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 348 "src/parser.y"
    { yyerrok; ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 350 "src/parser.y"
    { yyerrok; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 360 "src/parser.y"
    { 
            sent_agregar(estado_global, "if", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column);

        ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 365 "src/parser.y"
    { 
            sent_agregar(estado_global, "if/else", (yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column);

        ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 370 "src/parser.y"
    { 
            sent_agregar(estado_global, "switch", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column);

        ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 378 "src/parser.y"
    { sent_agregar(estado_global, "while", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 380 "src/parser.y"
    { sent_agregar(estado_global, "do/while", (yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 382 "src/parser.y"
    { sent_agregar(estado_global, "for", (yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 384 "src/parser.y"
    { sent_agregar(estado_global, "for", (yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 394 "src/parser.y"
    { sent_agregar(estado_global, "continue", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column);limpiarPilaErrorSintactico(); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 396 "src/parser.y"
    { sent_agregar(estado_global, "break", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); limpiarPilaErrorSintactico();;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 398 "src/parser.y"
    { sent_agregar(estado_global, "return", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 400 "src/parser.y"
    { 
            sent_agregar(estado_global, "return", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column);
            validarReturnConExpresion((yyvsp[(2) - (3)].string_type), (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column);
            free((yyvsp[(2) - (3)].string_type));
        ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 411 "src/parser.y"
    { 
        char* tipoDeclaracion = desapilar(&pilaTipos);
        free(tipoDeclaracion);
        limpiarPilaErrorSintactico(); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 416 "src/parser.y"
    { 
            char* tipoDeclaracion = desapilar(&pilaTipos);
            free(tipoDeclaracion);
            limpiarPilaErrorSintactico();
        ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 425 "src/parser.y"
    { 
            apilar(&pilaTipos, (yyvsp[(1) - (1)].string_type));
            free((yyvsp[(1) - (1)].string_type));
        ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 430 "src/parser.y"
    { 
            char* tipoActual = desapilar(&pilaTipos);
            size_t longitudNuevoTipo = strlen(tipoActual) + strlen((yyvsp[(2) - (2)].string_type)) + 2;
            char* nuevoTipo = malloc(longitudNuevoTipo);
            snprintf(nuevoTipo, longitudNuevoTipo, "%s %s", tipoActual, (yyvsp[(2) - (2)].string_type));
            apilar(&pilaTipos, nuevoTipo);
            free(tipoActual);
            free((yyvsp[(2) - (2)].string_type));
        ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 443 "src/parser.y"
    {
            (yyval.string_type) = guardarCadena((yyvsp[(1) - (1)].string_type)); 
            free((yyvsp[(1) - (1)].string_type)); 
        ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 456 "src/parser.y"
    { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            var_agregar((yyvsp[(1) - (1)].string_type), tipoDeclaracion, (yylsp[(1) - (1)]).first_line, (yylsp[(1) - (1)]).first_column);
            free((yyvsp[(1) - (1)].string_type));
        ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 462 "src/parser.y"
    { 
            char* tipoDeclaracion = consultarTope(&pilaTipos);
            if (var_agregar((yyvsp[(1) - (3)].string_type), tipoDeclaracion, (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column) && strcmp((yyvsp[(3) - (3)].string_type), "unknown") != 0) {
                validarInicializacion(tipoDeclaracion, (yyvsp[(3) - (3)].string_type), (yylsp[(3) - (3)]).first_line, (yylsp[(3) - (3)]).first_column);
            }
                
            free((yyvsp[(1) - (3)].string_type));
            free((yyvsp[(3) - (3)].string_type));
        ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 477 "src/parser.y"
    { 
            char* tipoDefinicion = consultarTope(&pilaTipos);
            func_agregar((yyvsp[(2) - (6)].string_type), tipoDefinicion, FUNCION_DEF, (yylsp[(2) - (6)]).first_line, (yylsp[(2) - (6)]).first_column);
            free((yyvsp[(2) - (6)].string_type));
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 485 "src/parser.y"
    {
            func_agregar((yyvsp[(2) - (6)].string_type), "void", FUNCION_DEF, (yylsp[(2) - (6)]).first_line, (yylsp[(2) - (6)]).first_column);
            free((yyvsp[(1) - (6)].string_type));
            free((yyvsp[(2) - (6)].string_type));
        ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 499 "src/parser.y"
    { 
            encolar(&colaParametros, (yyvsp[(1) - (2)].string_type), (yyvsp[(2) - (2)].string_type), (yylsp[(2) - (2)]).first_column, -1);
            free((yyvsp[(1) - (2)].string_type));
            free((yyvsp[(2) - (2)].string_type));
        ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 505 "src/parser.y"
    { 
            char* tipoCompuestoParametro = consultarTope(&pilaTipos);
            encolar(&colaParametros, tipoCompuestoParametro, (yyvsp[(2) - (2)].string_type), (yylsp[(2) - (2)]).first_column, -1);
            free((yyvsp[(2) - (2)].string_type));
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 513 "src/parser.y"
    { 
            encolar(&colaParametros, (yyvsp[(1) - (1)].string_type), NULL, (yylsp[(1) - (1)]).first_column, -1); 
            free((yyvsp[(1) - (1)].string_type));
        ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 518 "src/parser.y"
    { 
            char* tipoCompuestoParametro = consultarTope(&pilaTipos);
            encolar(&colaParametros, tipoCompuestoParametro, NULL, (yylsp[(1) - (1)]).first_column, -1);
            char* tipoDesapilado = desapilar(&pilaTipos);
            free(tipoDesapilado);
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2345 "obj/src/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 526 "src/parser.y"


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
