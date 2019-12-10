/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	extern FILE* out;
	extern int row;
	extern int col;
	extern int yyleng;


#line 76 "alfa.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_ARRAY = 259,
    TOK_IGUAL = 260,
    TOK_MAS = 261,
    TOK_MAYOR = 262,
    TOK_MENOR = 263,
    TOK_LLAVEIZQUIERDA = 264,
    TOK_CORCHETEIZQUIERDO = 265,
    TOK_MAYORIGUAL = 266,
    TOK_MENORIGUAL = 267,
    TOK_LLAVEDERECHA = 268,
    TOK_CORCHETEDERECHO = 269,
    TOK_FALSE = 270,
    TOK_FUNCTION = 271,
    TOK_IF = 272,
    TOK_INT = 273,
    TOK_BOOLEAN = 274,
    TOK_AND = 275,
    TOK_IDENTIFICADOR = 276,
    TOK_ASTERISCO = 277,
    TOK_COMA = 278,
    TOK_CONSTANTE_ENTERA = 279,
    TOK_DISTINTO = 280,
    TOK_DIVISION = 281,
    TOK_ELSE = 282,
    TOK_ASIGNACION = 283,
    TOK_MENOS = 284,
    TOK_NOT = 285,
    TOK_OR = 286,
    TOK_PARENTESISDERECHO = 287,
    TOK_PARENTESISIZQUIERDO = 288,
    TOK_PRINTF = 289,
    TOK_PUNTOYCOMA = 290,
    TOK_SCANF = 291,
    TOK_RETURN = 292,
    TOK_TRUE = 293,
    TOK_WHILE = 294,
    TOK_ERROR = 295,
    MENOSU = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 166 "alfa.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    37,    37,    39,    40,    42,    44,    45,    47,    49,
      50,    52,    54,    55,    57,    58,    60,    62,    63,    65,
      66,    68,    70,    71,    73,    74,    76,    77,    79,    80,
      81,    82,    84,    85,    87,    88,    90,    92,    93,    95,
      97,    99,   101,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   118,   119,   121,
     122,   124,   125,   126,   127,   128,   129,   131,   132,   134,
     135,   137,   139
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_ARRAY", "TOK_IGUAL",
  "TOK_MAS", "TOK_MAYOR", "TOK_MENOR", "TOK_LLAVEIZQUIERDA",
  "TOK_CORCHETEIZQUIERDO", "TOK_MAYORIGUAL", "TOK_MENORIGUAL",
  "TOK_LLAVEDERECHA", "TOK_CORCHETEDERECHO", "TOK_FALSE", "TOK_FUNCTION",
  "TOK_IF", "TOK_INT", "TOK_BOOLEAN", "TOK_AND", "TOK_IDENTIFICADOR",
  "TOK_ASTERISCO", "TOK_COMA", "TOK_CONSTANTE_ENTERA", "TOK_DISTINTO",
  "TOK_DIVISION", "TOK_ELSE", "TOK_ASIGNACION", "TOK_MENOS", "TOK_NOT",
  "TOK_OR", "TOK_PARENTESISDERECHO", "TOK_PARENTESISIZQUIERDO",
  "TOK_PRINTF", "TOK_PUNTOYCOMA", "TOK_SCANF", "TOK_RETURN", "TOK_TRUE",
  "TOK_WHILE", "TOK_ERROR", "MENOSU", "$accept", "program",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -27

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-27)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,     5,    17,    27,   -27,    45,   -27,   -27,    20,    27,
      -2,   -27,   -27,   -27,    11,    45,   146,    20,   -27,   -27,
     -13,    16,    10,    -2,    15,   127,    -2,   127,    42,    38,
     146,    43,   -27,   -27,    53,   -27,   -27,   -27,   -27,   -27,
       1,   -27,   -27,    -2,   -27,    68,    51,   127,   -27,   127,
     127,   127,   -27,   -27,   133,   -27,   -27,   -27,    -3,   -27,
     133,   127,   -27,   -27,   -27,   127,   127,   127,   -27,   -27,
      45,    18,   -17,   -27,    54,    56,   127,   127,   127,   127,
     127,   127,   127,   104,   133,   123,   133,    -2,    57,    55,
      82,   127,   127,   127,   127,   127,   127,   -27,   -27,   -17,
       6,   -27,   -27,   -17,     6,    96,    60,    84,   -27,   -27,
      85,    45,   -27,   146,   133,   133,   133,   133,   133,   133,
     127,   -27,   -27,   146,    27,    55,    86,    96,    87,   -27,
     146,   -27,    74,   -27,   -27,    92,    97,   -27,   146,    94,
     -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,    10,    15,     3,
       0,     6,     8,     7,     0,     0,     0,    15,     4,    72,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    27,    28,     0,    32,    33,    29,    30,    31,
       0,    14,     5,     0,    71,     0,     0,     0,    70,     0,
       0,     0,    69,    55,    41,    52,    67,    68,    51,    40,
      42,     0,     2,    25,    26,     0,     0,     0,    13,    11,
      18,     0,    47,    50,     0,     0,     0,     0,     0,     0,
       0,     0,    58,     0,    35,     0,    34,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,    53,    54,    43,
      48,    46,    45,    44,    49,    60,     0,     0,    36,    21,
       0,     0,    17,     0,    61,    66,    65,    64,    63,    62,
       0,    57,    56,     0,    23,    20,     0,    60,     0,    22,
       0,    19,    37,    59,    39,     0,     0,    16,     0,     0,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,    -7,   -27,   -27,   -27,     3,   -27,    52,   114,
     -27,   -27,   -16,     0,   -27,   -26,   -27,   -27,   -27,   -27,
     -15,   -27,   -27,   -27,   -27,   -27,   -24,   -27,    -6,   -27,
     -27,   -27,   110,   -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    13,    20,    16,
      17,    88,   112,    89,   130,    29,    30,    31,    32,    33,
      53,    35,    36,    37,    38,    39,    54,   106,   121,    75,
      55,    56,    57,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      21,    34,    18,    60,    63,    78,    40,    66,    14,    79,
       1,    66,    76,    46,     3,    34,    59,     4,    23,    19,
      40,    22,    42,    71,    76,    72,    73,    74,    78,    67,
      82,     5,    79,    21,    44,    80,    15,    83,    77,    43,
      78,    84,    85,    86,    79,     6,     7,    80,    47,    81,
      90,    62,    99,   100,   101,   102,   103,   104,   105,    91,
      76,    92,    93,     6,     7,    94,    95,   114,   115,   116,
     117,   118,   119,    87,    77,    61,    78,   109,    64,    96,
      79,    65,    69,    80,    70,    81,    97,   126,    98,   110,
     111,   113,   122,   123,   124,    68,   127,   128,    34,   132,
     134,   136,    76,    40,   135,   137,   138,   140,    34,   131,
      76,   125,   139,    40,    87,    34,    77,   129,    78,   120,
      40,   133,    79,    34,    77,    80,    78,    81,    40,    76,
      79,    41,    45,    80,     0,    81,   107,   108,     0,    76,
       0,     0,    48,    77,     0,    78,     0,     0,    19,    79,
       0,    44,    80,    77,    81,    78,    49,    50,     0,    79,
      51,     0,    80,    24,    81,    52,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,    26,    27,     0,    28
};

static const yytype_int16 yycheck[] =
{
      10,    16,     9,    27,    30,    22,    16,    10,     5,    26,
       3,    10,     6,    23,     9,    30,    26,     0,    15,    21,
      30,    10,    35,    47,     6,    49,    50,    51,    22,    28,
      33,     4,    26,    43,    24,    29,    16,    61,    20,    23,
      22,    65,    66,    67,    26,    18,    19,    29,    33,    31,
      32,    13,    76,    77,    78,    79,    80,    81,    82,     5,
       6,     7,     8,    18,    19,    11,    12,    91,    92,    93,
      94,    95,    96,    70,    20,    33,    22,    87,    35,    25,
      26,    28,    14,    29,    33,    31,    32,   113,    32,    32,
      35,     9,    32,     9,     9,    43,   120,   123,   113,    13,
      13,    27,     6,   113,   130,    13,     9,    13,   123,   125,
       6,   111,   138,   123,   111,   130,    20,   124,    22,    23,
     130,   127,    26,   138,    20,    29,    22,    31,   138,     6,
      26,    17,    22,    29,    -1,    31,    32,    14,    -1,     6,
      -1,    -1,    15,    20,    -1,    22,    -1,    -1,    21,    26,
      -1,    24,    29,    20,    31,    22,    29,    30,    -1,    26,
      33,    -1,    29,    17,    31,    38,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    36,    37,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,     9,     0,     4,    18,    19,    44,    45,
      46,    47,    48,    49,    48,    16,    51,    52,    44,    21,
      50,    75,    10,    48,    17,    34,    36,    37,    39,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      75,    51,    35,    23,    24,    74,    75,    33,    15,    29,
      30,    33,    38,    62,    68,    72,    73,    74,    75,    75,
      68,    33,    13,    57,    35,    28,    10,    28,    50,    14,
      33,    68,    68,    68,    68,    71,     6,    20,    22,    26,
      29,    31,    33,    68,    68,    68,    68,    48,    53,    55,
      32,     5,     7,     8,    11,    12,    25,    32,    32,    68,
      68,    68,    68,    68,    68,    68,    69,    32,    14,    75,
      32,    35,    54,     9,    68,    68,    68,    68,    68,    68,
      23,    70,    32,     9,     9,    55,    57,    68,    57,    44,
      56,    54,    13,    70,    13,    57,    27,    13,     9,    57,
      13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      65,    66,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     2,     0,    10,     2,     0,     3,
       0,     2,     1,     0,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     7,    11,     7,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 37 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
#line 1360 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 39 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1366 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 40 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1372 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 42 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1378 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 44 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n");}
#line 1384 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n");}
#line 1390 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1396 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R10:\t<tipo> ::= int\n");}
#line 1402 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R11:\t<tipo> ::= boolean\n");}
#line 1408 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 52 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
#line 1414 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 54 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");}
#line 1420 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 55 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1426 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 57 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R:20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1432 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R21:\t<funciones> ::= \n");}
#line 1438 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 60 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");}
#line 1444 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1450 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}
#line 1456 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 65 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1462 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 66 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
#line 1468 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 68 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
#line 1474 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 70 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1480 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");}
#line 1486 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 73 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1492 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 74 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1498 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 76 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1504 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 77 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R33:\t<sentencia_simple> ::= <bloque>\n");}
#line 1510 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 79 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1516 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 80 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1522 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 81 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1528 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 82 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1534 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 84 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1540 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 85 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1546 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 87 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
#line 1552 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 88 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1558 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 90 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
#line 1564 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 92 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
#line 1570 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 93 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
#line 1576 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 95 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
#line 1582 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 97 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");}
#line 1588 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 99 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R56:\t<escritura> ::= printf <exp>\n");}
#line 1594 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 101 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1600 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 103 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R72:\t<exp> ::= <exp> + <exp>\n");}
#line 1606 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 104 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R73:\t<exp> ::= <exp> - <exp>\n");}
#line 1612 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 105 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R74:\t<exp> ::= <exp> / <exp>\n");}
#line 1618 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 106 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R75:\t<exp> ::= <exp> * <exp>\n");}
#line 1624 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 107 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R76:\t<exp> ::= - <exp>\n");}
#line 1630 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 108 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R77:\t<exp> ::= <exp> && <exp>\n");}
#line 1636 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 109 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R78:\t<exp> ::= <exp> || <exp>\n");}
#line 1642 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 110 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R79:\t<exp> ::= ! <exp>\n");}
#line 1648 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 111 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R80:\t<exp> ::= <identificador>\n");}
#line 1654 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 112 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R81:\t<exp> ::= <constante>\n");}
#line 1660 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 113 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R82:\t<exp> ::= ( <exp> )\n");}
#line 1666 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 114 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R83:\t<exp> ::= ( <comparacion> )\n");}
#line 1672 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 115 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R85:\t<exp> ::= <elemento_vector>\n");}
#line 1678 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 116 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R88:\t<exp> ::= <identificaor> ( <lista_expresiones> )\n");}
#line 1684 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 118 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
#line 1690 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 119 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R90:\t<lista_expresiones> ::=\n");}
#line 1696 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 121 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 1702 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 122 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R92:\t<resto_lista_expresiones> ::= \n");}
#line 1708 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 124 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R93:\t<comparacion> ::= <exp> == <exp>\n");}
#line 1714 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 125 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R94:\t<comparacion> ::= <exp> != <exp>\n");}
#line 1720 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 126 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
#line 1726 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 127 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
#line 1732 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 128 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R97:\t<comparacion> ::= <exp> < <exp>\n");}
#line 1738 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 129 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R98:\t<comparacion> ::= <exp> > <exp>\n");}
#line 1744 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 131 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R99:\t<constante> ::= <constante_logica>\n");}
#line 1750 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 132 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R100:\t<constante> ::= <constante_entera>\n");}
#line 1756 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 134 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R102:\t<constante_logica> ::= true\n");}
#line 1762 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 135 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R103:\t<constante_logica> ::= false\n");}
#line 1768 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 137 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");}
#line 1774 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 139 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
#line 1780 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 1784 "alfa.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
  return yyresult;
}
#line 141 "alfa.y" /* yacc.c:1906  */


int yyerror(char* s){
		if(yylval != -1)
			fprintf(stderr, "****Error sintactico en [lin %d col %d]\n", row, col-yyleng);
		return -1;
	}
