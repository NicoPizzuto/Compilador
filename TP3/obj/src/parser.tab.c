
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
#include "general.h"
#include "pila.h"

extern int yylex(void);
extern FILE* yyin;
extern FILE* yyout;
void yyerror(const char*);

char tipo_actual[100];



/* Line 189 of yacc.c  */
#line 90 "obj/src/parser.tab.c"

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
     UNARY_MINUS = 275,
     MINUSMINUS = 276,
     PLUSPLUS = 277,
     ESPECIFICADOR_TIPO = 278,
     IF = 279,
     ELSE = 280,
     DEFAULT = 281,
     CASE = 282,
     STRING_LITERAL = 283,
     SWITCH = 284,
     BREAK = 285,
     FOR = 286,
     DO = 287,
     WHILE = 288,
     CONTINUE = 289,
     RETURN = 290,
     VOID = 291,
     IDENTIFICADOR = 292,
     CONSTANTE = 293,
     CONSTANTE_REAL = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "src/parser.y"

    unsigned long unsigned_long_type;
    double double_type;
    char string_type[30];



/* Line 214 of yacc.c  */
#line 173 "obj/src/parser.tab.c"
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
#line 198 "obj/src/parser.tab.c"

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
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    43,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    16,    19,
      24,    27,    29,    31,    38,    45,    46,    48,    50,    52,
      54,    58,    62,    66,    70,    74,    76,    80,    82,    86,
      88,    92,    96,    98,   102,   106,   110,   114,   116,   120,
     124,   126,   130,   134,   136,   139,   142,   145,   147,   152,
     155,   158,   160,   162,   164,   166,   170,   171,   173,   175,
     179,   181,   183,   185,   187,   189,   191,   196,   200,   204,
     207,   209,   212,   215,   219,   224,   228,   230,   233,   236,
     238,   240,   242,   248,   256,   262,   268,   276,   286,   295,
     296,   298,   301,   304,   307,   311,   314,   318,   320,   323,
     325,   327,   329,   333,   335,   339,   343,   347,   354,   361,
     363,   367
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    -1,    48,    49,    -1,    82,    -1,    51,
      -1,    50,    -1,     1,    42,    -1,     1,    43,    -1,    39,
       7,    39,    42,    -1,    54,    42,    -1,    77,    -1,    52,
      -1,    79,    39,    23,    53,    24,    42,    -1,    38,    39,
      23,    53,    24,    42,    -1,    -1,    38,    -1,    83,    -1,
      55,    -1,    56,    -1,    39,     7,    55,    -1,    39,     6,
      55,    -1,    39,     5,    55,    -1,    39,     4,    55,    -1,
      39,     3,    55,    -1,    57,    -1,    56,     8,    57,    -1,
      58,    -1,    57,     9,    58,    -1,    59,    -1,    58,    11,
      59,    -1,    58,    10,    59,    -1,    60,    -1,    59,    15,
      60,    -1,    59,    14,    60,    -1,    59,    13,    60,    -1,
      59,    12,    60,    -1,    61,    -1,    60,    17,    61,    -1,
      60,    16,    61,    -1,    62,    -1,    61,    19,    62,    -1,
      61,    18,    62,    -1,    63,    -1,    22,    39,    -1,    21,
      39,    -1,    16,    62,    -1,    64,    -1,    39,    23,    65,
      24,    -1,    39,    22,    -1,    39,    21,    -1,    39,    -1,
      40,    -1,    41,    -1,    30,    -1,    23,    54,    24,    -1,
      -1,    66,    -1,    54,    -1,    66,    44,    54,    -1,    68,
      -1,    69,    -1,    70,    -1,    73,    -1,    74,    -1,    76,
      -1,    29,    54,    45,    67,    -1,    28,    45,    67,    -1,
      29,    54,    45,    -1,    28,    45,    -1,    42,    -1,    54,
      42,    -1,    46,    43,    -1,    46,    71,    43,    -1,    46,
      71,     1,    43,    -1,    46,     1,    43,    -1,    72,    -1,
      71,    72,    -1,    71,     1,    -1,     1,    -1,    77,    -1,
      67,    -1,    26,    23,    54,    24,    67,    -1,    26,    23,
      54,    24,    67,    27,    67,    -1,    31,    23,    54,    24,
      67,    -1,    35,    23,    54,    24,    67,    -1,    34,    67,
      35,    23,    54,    24,    42,    -1,    33,    23,    75,    42,
      75,    42,    75,    24,    67,    -1,    33,    23,    77,    75,
      42,    75,    24,    67,    -1,    -1,    54,    -1,    36,    42,
      -1,    32,    42,    -1,    37,    42,    -1,    37,    54,    42,
      -1,    78,    42,    -1,    78,    80,    42,    -1,    79,    -1,
      79,    79,    -1,    25,    -1,    38,    -1,    81,    -1,    80,
      44,    81,    -1,    39,    -1,    39,     7,    54,    -1,    39,
       7,    40,    -1,    39,     7,    41,    -1,    79,    39,    23,
      53,    24,    70,    -1,    38,    39,    23,    53,    24,    70,
      -1,    84,    -1,    83,    44,    84,    -1,    79,    39,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    54,    54,    56,    60,    61,    62,    63,    65,    70,
      76,    83,    84,    88,    96,   106,   108,   109,   115,   119,
     120,   121,   122,   123,   124,   128,   129,   133,   134,   138,
     139,   140,   144,   145,   146,   147,   148,   152,   153,   154,
     158,   159,   160,   164,   165,   166,   167,   171,   172,   173,
     174,   178,   179,   180,   181,   182,   185,   187,   191,   192,
     198,   199,   200,   201,   202,   203,   207,   209,   211,   213,
     218,   219,   223,   224,   225,   227,   232,   233,   234,   236,
     241,   242,   246,   248,   250,   255,   257,   259,   261,   265,
     267,   271,   273,   275,   277,   284,   285,   290,   292,   301,
     303,   308,   309,   313,   315,   317,   319,   326,   334,   345,
     346,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIV_ASSIGN", "MUL_ASSIGN", "SUB_ASSIGN",
  "ADD_ASSIGN", "ASSIGN", "OR", "AND", "NE", "EQ", "GE", "LE", "GT", "LT",
  "MINUS", "PLUS", "SLASH", "STAR", "UNARY_MINUS", "MINUSMINUS",
  "PLUSPLUS", "'('", "')'", "ESPECIFICADOR_TIPO", "IF", "ELSE", "DEFAULT",
  "CASE", "STRING_LITERAL", "SWITCH", "BREAK", "FOR", "DO", "WHILE",
  "CONTINUE", "RETURN", "VOID", "IDENTIFICADOR", "CONSTANTE",
  "CONSTANTE_REAL", "';'", "'}'", "','", "':'", "'{'", "$accept",
  "programa", "elemento_programa", "sentencia_expresion_global",
  "declaracion_externa", "prototipo_funcion", "lista_parametros_opt",
  "expresion", "expresion_asignacion", "expresion_logica_or",
  "expresion_logica_and", "expresion_igualdad", "expresion_relacional",
  "expresion_aditiva", "expresion_multiplicativa", "expresion_unaria",
  "expresion_postfija", "expresion_primaria",
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
     275,   276,   277,    40,    41,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,    59,   125,    44,    58,   123
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    70,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    77,    77,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    82,    82,    83,
      83,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     2,     4,
       2,     1,     1,     6,     6,     0,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2,     2,     1,     4,     2,
       2,     1,     1,     1,     1,     3,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     2,
       1,     2,     2,     3,     4,     3,     1,     2,     2,     1,
       1,     1,     5,     7,     5,     5,     7,     9,     8,     0,
       1,     2,     2,     2,     3,     2,     3,     1,     2,     1,
       1,     1,     3,     1,     3,     3,     3,     6,     6,     1,
       3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,    99,    54,
     100,    51,    52,    53,     3,     6,     5,    12,     0,    18,
      19,    25,    27,    29,    32,    37,    40,    43,    47,    11,
       0,    97,     4,     7,     8,    51,    46,    45,    44,    51,
       0,     0,     0,     0,     0,     0,     0,    50,    49,    56,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,    95,     0,   101,   100,     0,    98,
       0,    55,    15,    24,    23,    22,    21,    51,    20,    58,
       0,    57,    26,    28,    31,    30,    36,    35,    34,    33,
      39,    38,    42,    41,     0,    96,     0,    15,    16,     0,
       0,    17,   109,     9,    48,     0,    52,    53,   104,   102,
       0,     0,   111,     0,    59,     0,    14,     0,   108,   110,
      13,   107,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,    72,     0,    81,    60,    61,    62,
       0,    76,    63,    64,    65,    80,    97,    75,     0,    69,
       0,     0,    92,    89,     0,     0,    91,    93,     0,    71,
      78,    73,    77,     0,    67,    68,     0,    90,     0,    89,
       0,     0,    94,    74,     0,    66,     0,    89,     0,     0,
       0,    82,    84,     0,    89,     0,    85,     0,    89,     0,
       0,    83,     0,     0,    86,     0,    88,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,    15,    16,    17,    99,   135,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    80,    81,
     136,   137,   138,   139,   140,   141,   142,   143,   168,   144,
     145,    30,   100,    65,    66,    32,   101,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
    -146,    97,  -146,    83,    93,   -35,   -16,   247,  -146,  -146,
      22,    14,  -146,  -146,  -146,  -146,  -146,  -146,    25,  -146,
      56,    60,   118,    87,   132,   139,  -146,  -146,  -146,  -146,
      17,     3,  -146,  -146,  -146,    89,  -146,  -146,  -146,   138,
      52,    71,   247,   247,   247,   247,   259,  -146,  -146,   247,
    -146,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    66,  -146,    10,  -146,  -146,    73,  -146,
     247,  -146,    19,  -146,  -146,  -146,  -146,     4,  -146,  -146,
      79,    77,    60,   118,    87,    87,   132,   132,   132,   132,
     139,   139,  -146,  -146,   262,  -146,    91,    19,   100,   127,
     117,   123,  -146,  -146,  -146,   247,  -146,  -146,  -146,  -146,
     145,   -13,  -146,    20,  -146,   -12,  -146,    49,  -146,  -146,
    -146,  -146,   128,   147,   129,   247,   149,   131,   152,   191,
     154,   140,   213,  -146,  -146,   148,  -146,  -146,  -146,  -146,
     163,  -146,  -146,  -146,  -146,  -146,    20,  -146,   247,   191,
     135,   247,  -146,   226,   146,   247,  -146,  -146,   166,  -146,
     167,  -146,  -146,   187,  -146,   191,   192,  -146,   173,   247,
     195,   214,  -146,  -146,   191,  -146,   191,   247,   197,   247,
     191,   217,  -146,   198,   247,   221,  -146,   191,   247,   222,
     199,  -146,   233,   191,  -146,   191,  -146,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,  -146,   153,    -1,   -30,  -146,
     207,   208,   109,    50,   106,     1,  -146,  -146,  -146,  -146,
    -127,  -146,  -146,   -60,  -146,   119,  -146,  -146,  -145,  -146,
       2,  -146,     0,  -146,   165,  -146,  -146,   158
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -101
static const yytype_int16 yytable[] =
{
      18,    31,   154,    29,    37,    36,    40,    42,    43,    44,
      45,    70,    73,    74,    75,    76,    78,    42,    43,    44,
      45,    46,   164,    38,   178,    47,    48,    49,     8,   116,
     120,    69,   183,   117,   117,    47,    48,    49,   175,   189,
      78,    67,    68,   192,     8,     8,   103,   181,    79,   182,
     122,   118,    95,   186,    96,   121,    63,    98,    67,    64,
     191,    41,    92,    93,    51,     4,   196,    50,   197,    52,
       5,     6,     7,    94,     8,   123,    71,   124,   125,     9,
     126,   127,   128,   129,   130,   131,   132,    67,    39,    12,
      13,   133,   134,   108,    72,   117,    97,     2,     3,    55,
      56,    57,    58,   104,   114,    86,    87,    88,    89,     4,
      47,    48,    49,     4,     5,     6,     7,   146,     5,     6,
       7,   105,     8,     9,   150,    33,    34,     9,    53,    54,
      63,   158,    35,    12,    13,    10,    11,    12,    13,  -100,
     146,    42,    43,    44,    45,    70,    69,   163,    59,    60,
     166,   111,   167,   146,   171,   169,   112,    61,    62,    47,
      48,    49,    84,    85,   160,    90,    91,   113,   167,   115,
     148,   147,   151,   152,   149,   153,   167,   155,   185,     4,
     165,   170,   156,   167,     5,     6,     7,   167,     8,   123,
     159,   124,   125,     9,   126,   127,   128,   129,   130,   131,
     132,    67,    39,    12,    13,   133,   161,     4,   172,   117,
     173,   174,     5,     6,     7,   177,   176,   123,   179,   124,
     125,     9,   126,   127,   128,   129,   130,   131,   132,     4,
      39,    12,    13,   133,     5,     6,     7,   117,   180,   184,
     188,   194,     4,     9,   187,   190,   193,     5,     6,     7,
     110,     8,    39,    12,    13,   157,     9,   195,    82,   162,
      83,   109,     0,     4,    67,    39,    12,    13,     5,     6,
       7,   119,     0,     0,     0,     4,     0,     9,     4,     0,
       5,     6,     7,     5,     6,     7,    39,    12,    13,     9,
       0,     0,     9,     0,     0,     0,     0,     0,    77,    12,
      13,    39,   106,   107
};

static const yytype_int16 yycheck[] =
{
       1,     1,   129,     1,    39,     4,     7,     3,     4,     5,
       6,     7,    42,    43,    44,    45,    46,     3,     4,     5,
       6,     7,   149,    39,   169,    21,    22,    23,    25,    42,
      42,    31,   177,    46,    46,    21,    22,    23,   165,   184,
      70,    38,    39,   188,    25,    25,    42,   174,    49,   176,
       1,   111,    42,   180,    44,   115,    39,    38,    38,    42,
     187,    39,    61,    62,     8,    16,   193,    42,   195,     9,
      21,    22,    23,     7,    25,    26,    24,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    94,    23,    46,    23,     0,     1,    12,
      13,    14,    15,    24,   105,    55,    56,    57,    58,    16,
      21,    22,    23,    16,    21,    22,    23,   117,    21,    22,
      23,    44,    25,    30,   125,    42,    43,    30,    10,    11,
      39,   132,    39,    40,    41,    38,    39,    40,    41,    39,
     140,     3,     4,     5,     6,     7,   146,   148,    16,    17,
     151,    24,   153,   153,   155,   153,    39,    18,    19,    21,
      22,    23,    53,    54,     1,    59,    60,    44,   169,    24,
      23,    43,    23,    42,    45,    23,   177,    23,   179,    16,
      45,    35,    42,   184,    21,    22,    23,   188,    25,    26,
      42,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    16,    42,    46,
      43,    24,    21,    22,    23,    42,    24,    26,    23,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    16,
      39,    40,    41,    42,    21,    22,    23,    46,    24,    42,
      42,    42,    16,    30,    27,    24,    24,    21,    22,    23,
      97,    25,    39,    40,    41,    42,    30,    24,    51,   140,
      52,    96,    -1,    16,    38,    39,    40,    41,    21,    22,
      23,   113,    -1,    -1,    -1,    16,    -1,    30,    16,    -1,
      21,    22,    23,    21,    22,    23,    39,    40,    41,    30,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,     0,     1,    16,    21,    22,    23,    25,    30,
      38,    39,    40,    41,    49,    50,    51,    52,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    77,
      78,    79,    82,    42,    43,    39,    62,    39,    39,    39,
      54,    39,     3,     4,     5,     6,     7,    21,    22,    23,
      42,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    39,    42,    80,    81,    38,    39,    79,
       7,    24,    23,    55,    55,    55,    55,    39,    55,    54,
      65,    66,    57,    58,    59,    59,    60,    60,    60,    60,
      61,    61,    62,    62,     7,    42,    44,    23,    38,    53,
      79,    83,    84,    42,    24,    44,    40,    41,    54,    81,
      53,    24,    39,    44,    54,    24,    42,    46,    70,    84,
      42,    70,     1,    26,    28,    29,    31,    32,    33,    34,
      35,    36,    37,    42,    43,    54,    67,    68,    69,    70,
      71,    72,    73,    74,    76,    77,    79,    43,    23,    45,
      54,    23,    42,    23,    67,    23,    42,    42,    54,    42,
       1,    43,    72,    54,    67,    45,    54,    54,    75,    77,
      35,    54,    42,    43,    24,    67,    24,    42,    75,    23,
      24,    67,    67,    75,    42,    54,    67,    27,    42,    75,
      24,    67,    75,    24,    42,    24,    67,    67
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
#line 64 "src/parser.y"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 66 "src/parser.y"
    { yyerrok; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 71 "src/parser.y"
    {
            char estructura[100]; 
            sprintf(estructura, "%s = %s;", (yyvsp[(1) - (4)].string_type), (yyvsp[(3) - (4)].string_type));
            agregarEstructurasSintacticasNoReconocidas(estructura, (yylsp[(1) - (4)]).first_line);
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 77 "src/parser.y"
    {
            agregarEstructurasSintacticasNoReconocidas("expresion;", (yylsp[(1) - (2)]).first_line);
        ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 89 "src/parser.y"
    { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas((yyvsp[(2) - (6)].string_type), params_copia, (yyvsp[(1) - (6)].string_type), (yylsp[(2) - (6)]).first_line, "declaracion");
        ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 97 "src/parser.y"
    { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas((yyvsp[(2) - (6)].string_type), params_copia, "void", (yylsp[(2) - (6)]).first_line, "declaracion");
        ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 208 "src/parser.y"
    { agregarSentencias("case", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 210 "src/parser.y"
    { agregarSentencias("default", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 212 "src/parser.y"
    { agregarSentencias("case", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 214 "src/parser.y"
    { agregarSentencias("default", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 226 "src/parser.y"
    { yyerrok; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 228 "src/parser.y"
    { yyerrok; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 235 "src/parser.y"
    { yyerrok; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 237 "src/parser.y"
    { yyerrok; ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 247 "src/parser.y"
    { agregarSentencias("if", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 249 "src/parser.y"
    { agregarSentencias("if/else", (yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 251 "src/parser.y"
    { agregarSentencias("switch", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 256 "src/parser.y"
    { agregarSentencias("while", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 258 "src/parser.y"
    { agregarSentencias("do/while", (yylsp[(1) - (7)]).first_line, (yylsp[(1) - (7)]).first_column); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 260 "src/parser.y"
    { agregarSentencias("for", (yylsp[(1) - (9)]).first_line, (yylsp[(1) - (9)]).first_column); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 262 "src/parser.y"
    { agregarSentencias("for", (yylsp[(1) - (8)]).first_line, (yylsp[(1) - (8)]).first_column); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 272 "src/parser.y"
    { agregarSentencias("continue", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 274 "src/parser.y"
    { agregarSentencias("break", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 276 "src/parser.y"
    { agregarSentencias("return", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 278 "src/parser.y"
    { agregarSentencias("return", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 286 "src/parser.y"
    { agregarVariablesDeclaradas("", tipo_actual, (yylsp[(1) - (3)]).first_line); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 291 "src/parser.y"
    { strcpy(tipo_actual, (yyvsp[(1) - (1)].string_type)); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 293 "src/parser.y"
    { 
            strcpy(tipo_actual, (yyvsp[(1) - (2)].string_type));
            strcat(tipo_actual, " ");
            strcat(tipo_actual, (yyvsp[(2) - (2)].string_type));
        ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 302 "src/parser.y"
    { strcpy((yyval.string_type), (yyvsp[(1) - (1)].string_type)); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 304 "src/parser.y"
    { strcpy((yyval.string_type), "void"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 314 "src/parser.y"
    { apilar(&pilaVariables, (yyvsp[(1) - (1)].string_type)); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 316 "src/parser.y"
    { apilar(&pilaVariables, (yyvsp[(1) - (3)].string_type)); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 318 "src/parser.y"
    { apilar(&pilaVariables, (yyvsp[(1) - (3)].string_type)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 320 "src/parser.y"
    { apilar(&pilaVariables, (yyvsp[(1) - (3)].string_type)); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 327 "src/parser.y"
    { 
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas((yyvsp[(2) - (6)].string_type), params_copia, (yyvsp[(1) - (6)].string_type), (yylsp[(2) - (6)]).first_line, "definicion");
        ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 335 "src/parser.y"
    {
            char* params = obtenerListaParametros();
            char params_copia[500];
            strcpy(params_copia, params);
            resetearParametros();
            agregarFuncionesDeclaradasODefinidas((yyvsp[(2) - (6)].string_type), params_copia, "void", (yylsp[(2) - (6)]).first_line, "definicion");
        ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 351 "src/parser.y"
    { agregarParametro((yyvsp[(1) - (2)].string_type), (yyvsp[(2) - (2)].string_type)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1934 "obj/src/parser.tab.c"
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
#line 354 "src/parser.y"


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
