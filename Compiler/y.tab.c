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
#line 6 "boo-yacc.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdio.h>
// Include header definition of data type
	#include "boo-variable.h"
// Include header definition of methods
	#include "boo-yacc.h"
// Global counter for saving the current scope
	int globalCounter, ignore;
	typedData *topOfTheStack=NULL;
	typedData *staticStackValues=NULL;

// http://stackoverflow.com/questions/26211770/how-to-detect-error-line-number-using-yacc-parser#26219633
// http://stackoverflow.com/questions/496448/how-to-correctly-use-the-extern-keyword-in-c#496476 
	extern int yylineno;

// http://stackoverflow.com/questions/20106574/simple-yacc-grammars-give-an-error
	int yylex();

#line 88 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    STRING = 259,
    NUMBERS = 260,
    IF = 261,
    ELSE = 262,
    PRINT = 263,
    SHOW = 264,
    AND = 265,
    OR = 266,
    NOT = 267,
    EQ = 268,
    NEQ = 269,
    EXIT = 270,
    BOOL = 271,
    TRUE = 272,
    FALSE = 273,
    INT = 274,
    INTEGER = 275,
    CASTING = 276,
    UMINUS = 277
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define NUMBERS 260
#define IF 261
#define ELSE 262
#define PRINT 263
#define SHOW 264
#define AND 265
#define OR 266
#define NOT 267
#define EQ 268
#define NEQ 269
#define EXIT 270
#define BOOL 271
#define TRUE 272
#define FALSE 273
#define INT 274
#define INTEGER 275
#define CASTING 276
#define UMINUS 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "boo-yacc.y" /* yacc.c:355  */

	int integer;		//value of terminal
	char *lexeme; 		//identifier
	typedData *data;	//variable type defined in the boo-variable.h

#line 178 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

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
      21,    22,    29,    27,    35,    28,    33,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    34,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,    36,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    71,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    91,    92,    93,    96,
     100,   102,   105,    99,   110,   112,   111,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "NUMBERS", "IF", "ELSE",
  "PRINT", "SHOW", "AND", "OR", "NOT", "EQ", "NEQ", "EXIT", "BOOL", "TRUE",
  "FALSE", "INT", "INTEGER", "'('", "')'", "'{'", "'}'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "CASTING", "UMINUS", "'.'", "'='", "','",
  "'|'", "$accept", "start", "scope", "$@1", "declaration", "$@2", "$@3",
  "$@4", "$@5", "$@6", "$@7", "decl", "assignment", "statement", "$@8",
  "$@9", "$@10", "else_statement", "$@11", "if_scope", "$@12", "$@13",
  "$@14", "$@15", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    40,    41,   123,   125,    60,    62,    43,    45,    42,
      47,   276,   277,    46,    61,    44,   124
};
# endif

#define YYPACT_NINF -63

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-63)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,   -15,   -63,   121,    74,   121,     1,    -7,     6,   -63,
     -63,     8,    29,   121,   -63,   121,   121,    35,    53,     5,
       7,   -63,   154,   121,   -63,    18,    20,   281,    21,   163,
     184,   121,   -63,    19,   121,    23,   121,    30,   223,    53,
     -63,   133,   -63,   -63,   -63,   -63,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   -63,   281,    32,   -63,
     -63,   -63,   244,   121,   -63,   254,   121,   -63,   275,   121,
     -63,   -63,    43,   -63,   321,   302,   -13,   -13,   -13,   -13,
     -23,   -23,   -63,   -63,   -63,   -63,   281,    40,   -63,   281,
      40,   -63,   281,    40,   -63,    15,   -63,    77,   -63,   -63,
     -15,   100,   121,    49,    50,    60,    40,    51,    40,    40,
      54,   193,   214,   -63,    15,   -63,   121,   -63,   -63,   -63,
      15,   -63,    81,   281,    15,    15,    15,   -63,    71,   -63,
     -63,   -63,   -63,   -63,    15,    72,   -63
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    50,    49,     0,     0,     0,     0,     0,     0,    47,
      48,     0,     0,     0,     4,     0,     0,     0,     3,     0,
       0,     8,     0,     0,    50,     0,     0,    30,     0,     0,
       0,     0,    12,    16,     0,    14,     0,    18,     0,     3,
      65,     0,     1,     2,     7,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,    29,     0,    13,
      10,    11,     0,     0,    28,     0,     0,    28,     0,     0,
      28,    56,     0,    66,    52,    51,    59,    60,    57,    58,
      61,    62,    63,    64,    31,    53,    22,    17,    55,    20,
      15,    54,    24,    19,     5,    46,    28,     0,    28,    28,
       0,     0,     0,     0,     0,     0,    23,    26,    21,    25,
       0,     0,     0,    42,    46,    32,     0,    44,    38,    40,
      46,    37,    34,    27,    46,    46,    46,    43,     0,    33,
      45,    39,    41,    35,    46,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -63,   -14,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
     -63,   -62,     3,   -63,   -63,   -63,   -63,   -63,   -63,   199,
     -63,   -63,   -63,   -63,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    39,    19,    67,    64,    70,    98,    96,
      99,    87,   104,    21,    58,    95,   122,   129,   134,   105,
     125,   126,   120,   124,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    29,    30,    20,    43,    90,    54,    55,    93,    33,
      38,    35,    40,    41,    52,    53,    54,    55,   100,    23,
      57,    20,    31,   101,   102,    72,    32,    34,    62,    36,
     103,    65,    37,    68,   106,    42,   108,   109,    44,    34,
      45,    36,    20,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    63,    59,    84,     1,    66,     2,     3,
      86,     4,     5,    89,    69,     6,    92,    94,     7,     8,
       9,    10,    11,    12,    13,    97,    14,    24,    28,     2,
     107,    15,   113,   114,   115,   116,     6,   117,   128,    16,
      25,     9,    10,    26,   133,    13,   136,     0,   111,   112,
       0,     0,    15,    24,   110,     2,     0,     0,     0,     0,
      16,     0,     6,   123,     0,     0,    25,     9,    10,    26,
       0,    13,     0,     0,    24,     0,     2,     0,    15,     0,
       0,     0,     0,     6,     0,     0,    16,    25,     9,    10,
      26,     0,    13,    46,    47,     0,    48,    49,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    16,    50,    51,
      52,    53,    54,    55,    46,    47,     0,    48,    49,    73,
       0,     0,     0,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,    54,    55,     0,     0,    56,    50,    51,
      52,    53,    54,    55,    46,    47,    60,    48,    49,     0,
       0,     0,     0,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,    54,    55,     0,     0,    61,    50,    51,
      52,    53,    54,    55,    46,    47,   118,    48,    49,     0,
       0,     0,     0,    46,    47,     0,    48,    49,     0,    50,
      51,    52,    53,    54,    55,    71,     0,   119,    50,    51,
      52,    53,    54,    55,    46,    47,     0,    48,    49,     0,
       0,     0,     0,     0,    46,    47,    85,    48,    49,    50,
      51,    52,    53,    54,    55,     0,    88,     0,     0,    50,
      51,    52,    53,    54,    55,    46,    47,     0,    48,    49,
       0,    46,    47,     0,    48,    49,     0,    91,     0,     0,
      50,    51,    52,    53,    54,    55,    50,    51,    52,    53,
      54,    55,    46,   121,     0,    48,    49,     0,     0,   127,
       0,     0,     0,   130,   131,   132,     0,    50,    51,    52,
      53,    54,    55,   135,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    51,    52,    53,
      54,    55
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     0,    18,    67,    29,    30,    70,     3,
      13,     3,    15,    16,    27,    28,    29,    30,     3,    34,
      23,    18,    21,     8,     9,    39,    33,    21,    31,    21,
      15,    34,     3,    36,    96,     0,    98,    99,    33,    21,
      33,    21,    39,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    34,    33,    23,     3,    34,     5,     6,
      63,     8,     9,    66,    34,    12,    69,    24,    15,    16,
      17,    18,    19,    20,    21,    35,    23,     3,     4,     5,
       3,    28,    33,    33,    24,    34,    12,    33,     7,    36,
      16,    17,    18,    19,    23,    21,    24,    -1,   101,   102,
      -1,    -1,    28,     3,     4,     5,    -1,    -1,    -1,    -1,
      36,    -1,    12,   116,    -1,    -1,    16,    17,    18,    19,
      -1,    21,    -1,    -1,     3,    -1,     5,    -1,    28,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    36,    16,    17,    18,
      19,    -1,    21,    10,    11,    -1,    13,    14,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    25,    26,
      27,    28,    29,    30,    10,    11,    -1,    13,    14,    36,
      -1,    -1,    -1,    10,    11,    -1,    13,    14,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    25,    26,
      27,    28,    29,    30,    10,    11,    33,    13,    14,    -1,
      -1,    -1,    -1,    10,    11,    -1,    13,    14,    -1,    25,
      26,    27,    28,    29,    30,    -1,    -1,    33,    25,    26,
      27,    28,    29,    30,    10,    11,    33,    13,    14,    -1,
      -1,    -1,    -1,    10,    11,    -1,    13,    14,    -1,    25,
      26,    27,    28,    29,    30,    22,    -1,    33,    25,    26,
      27,    28,    29,    30,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,    10,    11,    22,    13,    14,    25,
      26,    27,    28,    29,    30,    -1,    22,    -1,    -1,    25,
      26,    27,    28,    29,    30,    10,    11,    -1,    13,    14,
      -1,    10,    11,    -1,    13,    14,    -1,    22,    -1,    -1,
      25,    26,    27,    28,    29,    30,    25,    26,    27,    28,
      29,    30,    10,   114,    -1,    13,    14,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,    -1,    25,    26,    27,
      28,    29,    30,   134,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     8,     9,    12,    15,    16,    17,
      18,    19,    20,    21,    23,    28,    36,    38,    39,    41,
      49,    50,    61,    34,     3,    16,    19,    61,     4,    61,
      61,    21,    33,     3,    21,     3,    21,     3,    61,    40,
      61,    61,     0,    38,    33,    33,    10,    11,    13,    14,
      25,    26,    27,    28,    29,    30,    33,    61,    51,    33,
      33,    33,    61,    34,    43,    61,    34,    42,    61,    34,
      44,    22,    38,    36,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    23,    22,    61,    48,    22,    61,
      48,    22,    61,    48,    24,    52,    46,    35,    45,    47,
       3,     8,     9,    15,    49,    56,    48,     3,    48,    48,
       4,    61,    61,    33,    33,    24,    34,    33,    33,    33,
      59,    56,    53,    61,    60,    57,    58,    56,     7,    54,
      56,    56,    56,    23,    55,    56,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    40,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    42,    41,    43,    41,    44,    41,
      45,    41,    46,    41,    47,    41,    48,    48,    48,    49,
      51,    52,    53,    50,    54,    55,    54,    56,    57,    56,
      58,    56,    59,    56,    60,    56,    56,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     2,     2,     1,     2,
       3,     3,     2,     3,     0,     4,     0,     4,     0,     4,
       0,     6,     0,     6,     0,     6,     3,     5,     0,     3,
       0,     0,     0,     9,     0,     0,     5,     3,     0,     5,
       0,     5,     0,     4,     0,     5,     0,     1,     1,     1,
       1,     3,     3,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3
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
        case 4:
#line 71 "boo-yacc.y" /* yacc.c:1646  */
    {pushStack();}
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "boo-yacc.y" /* yacc.c:1646  */
    {popStack();}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "boo-yacc.y" /* yacc.c:1646  */
    { printExpression((yyvsp[-1].data)); }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "boo-yacc.y" /* yacc.c:1646  */
    { showExpression((yyvsp[-1].data)); }
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 78 "boo-yacc.y" /* yacc.c:1646  */
    { exit(EXIT_SUCCESS); }
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 79 "boo-yacc.y" /* yacc.c:1646  */
    { printf("%s",(yyvsp[-1].lexeme)); }
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 82 "boo-yacc.y" /* yacc.c:1646  */
    { insertNotInstantiatedVariable("int", (yyvsp[0].lexeme)); }
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "boo-yacc.y" /* yacc.c:1646  */
    { insertNotInstantiatedVariable("bool", (yyvsp[0].lexeme)); }
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 84 "boo-yacc.y" /* yacc.c:1646  */
    { insertNotInstantiatedVariable("integer", (yyvsp[0].lexeme)); }
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 85 "boo-yacc.y" /* yacc.c:1646  */
    { insertInstantiatedVariable("int", (yyvsp[-2].lexeme), (yyvsp[0].data)); }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 86 "boo-yacc.y" /* yacc.c:1646  */
    { insertInstantiatedVariable("bool", (yyvsp[-2].lexeme), (yyvsp[0].data)); }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "boo-yacc.y" /* yacc.c:1646  */
    { insertInstantiatedVariable("integer", (yyvsp[-2].lexeme), (yyvsp[0].data)); }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "boo-yacc.y" /* yacc.c:1646  */
    { insertNotInstantiatedVariable(firstVar()->type, (yyvsp[0].lexeme)); }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "boo-yacc.y" /* yacc.c:1646  */
    { insertInstantiatedVariable(firstVar()->type, (yyvsp[-2].lexeme), (yyvsp[0].data)); }
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].data)) { yyerror("Invalid expression to assign!"); exit(EXIT_FAILURE); } else { if(!ignore) { assignValue((yyvsp[-2].lexeme), (yyvsp[0].data)); } } }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "boo-yacc.y" /* yacc.c:1646  */
    {if(!(yyvsp[0].data)){yyerror("Invalid condition!");exit(EXIT_FAILURE);}}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 102 "boo-yacc.y" /* yacc.c:1646  */
    {pushStack(); if((yyvsp[-2].data)->value>0){ignore=0;}else{ignore=1;}}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 105 "boo-yacc.y" /* yacc.c:1646  */
    {popStack();}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 107 "boo-yacc.y" /* yacc.c:1646  */
    {ignore=0;}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 112 "boo-yacc.y" /* yacc.c:1646  */
    {pushStack(); if(ignore){ignore=0;}else{ignore=1;}}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 115 "boo-yacc.y" /* yacc.c:1646  */
    {popStack();}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 119 "boo-yacc.y" /* yacc.c:1646  */
    { if(!ignore){printExpression((yyvsp[-1].data));}}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 120 "boo-yacc.y" /* yacc.c:1646  */
    { if(!ignore){showExpression((yyvsp[-1].data));}}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 121 "boo-yacc.y" /* yacc.c:1646  */
    {if(!ignore){exit(EXIT_SUCCESS);}}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 122 "boo-yacc.y" /* yacc.c:1646  */
    { if(!ignore){printf("%s",(yyvsp[-1].lexeme));}}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 126 "boo-yacc.y" /* yacc.c:1646  */
    { (yyval.data)=lookupPrimitive("bool", 1); }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 127 "boo-yacc.y" /* yacc.c:1646  */
    { (yyval.data)=lookupPrimitive("bool", 0); }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 128 "boo-yacc.y" /* yacc.c:1646  */
    { (yyval.data)=newAnonymous("integer", (yyvsp[0].integer)); }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 129 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].lexeme)) { (yyval.data)=NULL; yyerror("Invalid variable name!"); exit(EXIT_FAILURE); } else { (yyval.data)=getTypedData((yyvsp[0].lexeme)); } }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 130 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid members of the OR operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=orExpression((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 131 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid members of the AND operator!"); exit(EXIT_FAILURE); } else { if(strcmp((yyvsp[-2].data)->type,(yyvsp[0].data)->type)) { yyerror("Variables type of AND operator don't match!"); exit(EXIT_FAILURE); } else { (yyval.data)=andExpression((yyvsp[-2].data), (yyvsp[0].data)); } } }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 132 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1].data)) { (yyval.data)=NULL; yyerror("Invalid member of NOT operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=notExpression((yyvsp[-1].data)); } }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 133 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1].data)) { (yyval.data)=NULL; yyerror("Invalid member of INT CAST operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=castExpression((yyvsp[-1].data), "int"); } }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 134 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1].data)) { (yyval.data)=NULL; yyerror("Invalid member of BOOL CAST operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=castExpression((yyvsp[-1].data), "bool"); } }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 135 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1].data)) { (yyval.data)=NULL; yyerror("Invalid member of ( ) operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=(yyvsp[-1].data); } }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 136 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of < operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=lessThan((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 137 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of > operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=greterThan((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 138 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of == operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=eqExpression((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 139 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of != operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=different((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 140 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of + operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=plus((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 141 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of - operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=minus((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 142 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of * operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=multiply((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 143 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-2].data) || !(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of / operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=divide((yyvsp[-2].data), (yyvsp[0].data)); } }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 144 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[0].data)) { (yyval.data)=NULL; yyerror("Invalid member of - operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=negative((yyvsp[0].data)); } }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 145 "boo-yacc.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1].data)) { (yyval.data)=NULL; yyerror("Invalid member of | | operator!"); exit(EXIT_FAILURE); } else { (yyval.data)=modulo((yyvsp[-1].data)); } }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1670 "y.tab.c" /* yacc.c:1646  */
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
#line 148 "boo-yacc.y" /* yacc.c:1906  */


/*
 ***********************************************************
 *********************** FUNCTIONS *************************
 ***********************************************************
*/

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the first value is less than the second
 */
typedData* lessThan(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of < operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of < operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value < t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the first value is greater than the second
 */
typedData* greterThan(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of > operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of > operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value > t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending of the values are different or not
 */
typedData* different(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of != operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of != operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value != t2->value)
		return lookupPrimitive("int", 1);
	else
		return lookupPrimitive("int", 0);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the sum of the two parameters
 */
typedData* plus(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of + operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of + operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value + t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the difference of the two parameters
 */
typedData* minus(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of - operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of - operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value - t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the multiplication of the two parameters
 */
typedData* multiply(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of * operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of * operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value * t2->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a new element of type integer containing the division of the two parameters. In case of zero dividend, an error is raised and the program is exited
 */
typedData* divide(typedData* t1, typedData* t2)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("First member of / operator is not of type integer!");
		exit(EXIT_FAILURE);
	}

	if(strcmp(t2->type, "integer"))
	{
		yyerror("Second member of / operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t2->value)
		return newAnonymous("integer", t1->value / t2->value);
	else
	{
		yyerror("Cannot divide by zero, you ignorant!");
		exit(EXIT_FAILURE);
	}
}

/*
 * Given one typedData (parameter), checks that it is of type integer and returns a reference to a new element of type integer containing the negation of the parameter
 */
typedData* negative(typedData* t1)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("Member of - (negative) operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	return newAnonymous("integer", t1->value*-1);
}

/*
 * Given one typedData (parameter), checks that it is of type integer and returns a reference to a new element of type integer containing the modulo of the parameter
 */
typedData* modulo(typedData* t1)
{
	if(strcmp(t1->type, "integer"))
	{
		yyerror("Member of | | operator is not of type integer!");
		exit(EXIT_FAILURE);
	}
	if(t1->value<0)
		return newAnonymous("integer", t1->value*-1);
	else
		return newAnonymous("integer", t1->value);
}

/*
 * Given two typedData (parameters), checks that they are both of type integer and returns a reference to a 0-1 static int, depending if the values are equal or not
 */
typedData* eqExpression(typedData* t1, typedData* t2)
{	
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value == t2->value)
			return lookupPrimitive(t1->type, 1);
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of equals operation are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if((t1->value>0 && t2->value>0) || (t1->value<1 && t2->value<1))
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointers are valid or of the same type because the semantic action has already checked if they are not null or of the same type, returning a particular error notice
 */
typedData* orExpression(typedData* t1, typedData* t2)
{
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value>0 || t2->value>0)
			return lookupPrimitive(t1->type, 1); 
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of OR operator are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t1->value>0 || t2->value>0)
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointers are valid or of the same type because the semantic action has already checked if they are not null or of the same type, returning a particular error notice
 */
typedData* andExpression(typedData* t1, typedData* t2)
{	
	if(!t1->init)
	{
		yyerror(strcat(t1->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!t2->init)
	{
		yyerror(strcat(t2->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t1->type, t2->type) && strcmp(t1->type, "integer"))
		if(t1->value>0 && t2->value>0)
			return lookupPrimitive(t1->type, 1); 
		else
			return lookupPrimitive(t1->type, 0);
	else
		if(!strcmp(t1->type, "bool") || !strcmp(t2->type, "bool"))
		{
			yyerror("Values of AND operator are not of the same type!");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t1->value>0 && t2->value>0)
				return lookupPrimitive("int", 1);
			else
				return lookupPrimitive("int", 0);
		}
}

/*
 * There is no need to check if the pointer is valid beacause the semantic action has already checked if it is not null, returning a particular error notice
 */
typedData* notExpression(typedData* t)
{
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	// If type of t1 (but also of t2, since they have the same type) is integer strcmp(t1->type, "integer") will return 0 and thus false
	if(!strcmp(t->type, "bool"))
		if(t->value)
			return lookupPrimitive(t->type, 0); 
		else
			return lookupPrimitive(t->type, 1);
	else
		{
			printf("Notice: cast to int on line %d was necessary for and operation\n", yylineno);
			if(t->value)
				return lookupPrimitive("int", 0);
			else
				return lookupPrimitive("int", 1);
		}
}

/*
 * There is no need to check if the pointer is valid because the semantic action has already checked if it is not null, returning a particular error notice
 */
typedData* castExpression(typedData* t, char* type)
{
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	typedData* temp=NULL;
	if(!strcmp(t->type, type))
	{
		printf("Notice: The expression at line %d is already of type %s\n", yylineno, t->type);
		free(temp);
		return t;
	}
	if(!strcmp("bool", type))
		if(t->value>0)
			temp=lookupPrimitive("bool", 1);
		else
			temp=lookupPrimitive("bool", 0);
	else
		if(!strcmp("int", type))
			if(t->type>0)
				temp=lookupPrimitive("int", 1);
			else
				temp=lookupPrimitive("int", 0);
	return temp;
}

/*
 * Inserts a variable into the symbol table with no defined value
 */
void insertNotInstantiatedVariable(char* t, char* n)
{
	if(!lookupWithScope(n))
	{
		newVariable(t, n);
		return;
	}
	yyerror(strcat(n, " has been already declared within the scope!"));
	exit(EXIT_FAILURE);
}

/*
 * Inserts a variable into the symbol table with a defined value
 */
void insertInstantiatedVariable(char* t, char* n, typedData* t2)
{
	if(!lookupWithScope(n))
	{
		assignment(newVariable(t, n), t2);
		return ;
	}
	yyerror(strcat(n, " has been already declared within the scope!"));
	exit(EXIT_FAILURE);
} 

/*
 * Takes as parameter an expression (of type typedData) and prints its value, depending on the type
 */
void printExpression(typedData* t)
{
	if(!t)
	{
		yyerror("Invalid expression to print!");
		exit(EXIT_FAILURE);
	}
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t->type, "bool"))
		if(t->value)
			printf("true\n");
		else
			printf("false\n");
	else
		if(!strcmp(t->type, "int"))
			printf("%d\n",t->value);
		else
			if(!strcmp(t->type, "integer"))
				printf("%d\n",t->value);
}

/*
 * Takes as parameter an expression (of type typedData) and prints its value, on the same line, depending on the type
 */
void showExpression(typedData* t)
{
	if(!t)
	{
		yyerror("invalid expression to print!");
		exit(EXIT_FAILURE);
	}
	if(!t->init)
	{
		yyerror(strcat(t->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(t->type, "bool"))	
		if(t->value)
			printf("true");
		else
			printf("false");
	else
		if(!strcmp(t->type, "int"))
			printf("%d",t->value);
		else
			if(!strcmp(t->type, "integer"))
				printf("%d",t->value);
}

/*
 * Takes as parameter the type and the name of the variable to insert into the symbol table. It updates the pointer of the stack
 */
typedData* newVariable(char* t, char* n)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->name=strdup(n);
	newvar->scope=globalCounter;
	newvar->init=0;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Takes as parameter the type, the name and the value of the variable to insert into the symbol table. It updates the pointer of the stack
 */
typedData* newValuedVariable(char* t, char* n, int v)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->name=strdup(n);
	newvar->scope=globalCounter;
	newvar->value=v;
	newvar->init=1;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Takes as parameter the type and the value of a variable to insert into the symbol table. It is used for the base/default values
 */
typedData* newAnonymous(char* t, int v)
{
	typedData* newvar=malloc(sizeof(typedData));
	newvar->type=strdup(t);
	newvar->scope=globalCounter;
	newvar->value=v;
	newvar->init=1;
	newvar->name=NULL;
	newvar->next=NULL;
	newvar->previous=topOfTheStack;
	if(topOfTheStack!=NULL)
		topOfTheStack->next=newvar;
	topOfTheStack=newvar;
	return newvar;
}

/*
 * Initializes the symbol table. The global counter is set to 0, the basic/default values are inserted into the symbol table and both the top of the stack pointer and the static stack pointer are set to the newest entry of the symbol table
 */
void initialize()
{
	ignore=0;
	globalCounter=0;
	topOfTheStack=NULL;
	staticStackValues=NULL;
// Generate default values
	newAnonymous("int", 0);
	newAnonymous("int", 1);
	newAnonymous("bool", 0);
	newAnonymous("bool", 1);
	staticStackValues=topOfTheStack; 
	globalCounter++;
}

/*
 * Increases the global counter by one, meaning that a new scope is entered
 */
void pushStack()
{
	globalCounter+=1;
}

/*
 * Removes all the variables, on top of the stack, that belong to the scope that is exited, and the global counter is decreased by one
 */
void popStack()
{
	if(topOfTheStack==NULL || topOfTheStack==staticStackValues)
		return ;
	while(topOfTheStack->scope==globalCounter)
	{
		typedData* temp=topOfTheStack;
		topOfTheStack=topOfTheStack->previous;
		topOfTheStack->next=NULL;
		temp->previous=NULL;
//		free(temp->previous);
		free(temp->name);
		free(temp->type);
		free(temp);
	}
	globalCounter-=1;
	return ;
}

/*
 * Takes as parameter the name of a variable and looks for it through the symbol table. If no variable with such a name is found, then NULL is returned, otherwise a pointer pointing to it is returned
 */
typedData* lookup(char* name)
{
	if(topOfTheStack==NULL || topOfTheStack==staticStackValues)
		return NULL;
	typedData* temp=topOfTheStack;
	while(temp!=staticStackValues)
	{
		if(temp->name && !strcmp(temp->name, name))
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Takes as parameters the type and the value of a basic/default value and looks for it into the first part of the stack
 */
typedData* lookupPrimitive(char* t, int v)
{
	if(staticStackValues==NULL)
		initialize();
	typedData* temp=staticStackValues;
	while(temp!=NULL)
	{
		if((!strcmp(temp->type,t)) && temp->value==v)
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Takes as parameter the name of a variable, uses the lookup method to get the first variable with that name, starting from the top of the stack. Then compares the scope of it with the current global counter and returns either 1 or 0 if, respectively, it has been declared within the current scope or a more external (i.e. looks that a variable with that name has not been already instantiated within the same scope).  
 */
// This method is a boolean method: 0 stands for false (i.e. the variable's declaration is not in the current scope) and 1 for true
int lookupWithScope(char* name)
{
	typedData* temp=lookup(name);
	if(temp!=NULL && temp->scope==globalCounter)
		return 1;
	else
		return 0;
}

/*
 * Returns a reference to the first element on top of the stack that is a variable (i.e. name not NULL)
 */
typedData* firstVar()
{
	typedData* temp=topOfTheStack;
	while(temp!=NULL)
	{
		if(temp->name)
			return temp;
		temp=temp->previous;
	}
	return NULL;
}

/*
 * Given the name of a variable and the result of an expression, assigns the value of the expression to the variable (after looking for it through the stack). An expression is only of type int or bool and thus there is no need to check if the type is a valid one, but it is checked if they are both of the same type
 */
void assignValue(char* n, typedData* t)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, t->type))
	{
		temp->value=t->value;
		temp->init=1;
	}
	else
	{
		if(!strcmp(temp->type, "int") && !strcmp(t->type, "integer"))
		{
			if(t->value > 0)
				temp->value=1;
			else
				temp->value=0;
			temp->init=1;
		}
		else
		{
			yyerror("Cannot assign a value that is not of the same type as the variable!");
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * Given two typedData (parameters), check that they are of the same type or at least that the right variable is of type int and the left variable of type integer and assigns the right value to the left variable
 */
void assignment(typedData* t1, typedData* t2)
{
	if(!strcmp(t1->type, t2->type))
	{
		t1->value=t2->value;
		t1->init=1;
	}
	else
	{
		if(!strcmp(t1->type, "int") && !strcmp(t2->type, "integer"))
		{
			if(t2->value > 0)
				t1->value=1;
			else
				t1->value=0;
			t1->init=1;
		}
		else
		{
			yyerror("Cannot assign a value that is not of the same type as the variable!");
			exit(EXIT_FAILURE);
		}
	}
}

/*
 * Given the name of a variable, looks for it through the stack and returns the pointer to it if it is of type integer, otherwise throws an error
 */
int getInteger(char* n)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE); 
	}
	if(!temp->init)
	{
		yyerror(strcat(temp->name, " has not value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, "integer"))
		return temp->value;
	else
	{
		yyerror(strcat(n, " is not of type integer!"));
		exit(EXIT_FAILURE);
	}
}

/*
 * Given the name of a variable, looks for it through the stack and returns the pointer to it if it is of type int or bool, otherwise throws an error
 */
typedData* getTypedData(char* n)
{
	typedData* temp=lookup(n);
	if(temp==NULL)
	{
		yyerror(strcat(n, " has not been declared yet!"));
		exit(EXIT_FAILURE);
	}
	if(!temp->init)
	{
		yyerror(strcat(temp->name, " has no value!"));
		exit(EXIT_FAILURE);
	}
	if(!strcmp(temp->type, "int") || !strcmp(temp->type, "bool") || !strcmp(temp->type, "integer"))
		return temp;
	else
	{
		yyerror(strcat(n, " is not of type int, bool or integer!\nSomething wrong happened to the stack"));
		exit(EXIT_FAILURE);
	}
}







/*
 * Part of functions reserved for debugging (aka, vip functions)
 */
void printStack()
{
	printf("***SYMBOL TABLE***\n");
	typedData* temp=topOfTheStack;
	while(temp!=NULL && temp!=staticStackValues)
	{
		printf("|");
		if(temp->name!=NULL)
			printf("%s\t", temp->name);
		else
			printf("NULL\t");
		printf("%s\t", temp->type);
		if(temp->init)
			if(!strcmp(temp->type,"int") || !strcmp(temp->type,"integer"))
				printf("%d", temp->value);
			else
				if(!strcmp(temp->type,"bool"))
					if(temp->type)
						printf("true");
					else
						printf("false");
		else
			printf("not assigned");
		temp=temp->previous;
		printf("|\n|\t\t|\n");
	}
}

#include "lex.yy.c"

// Since the parser is going to be run as a program, the main function is required and has to invoke yyparse() for starting the parser
int main()
{
	printf("***Welcome to Boo-Compiler***\n\n");
	initialize();
	// Can print anything, like a welcome string or simply execute the parsing
	// yyparse() starts the parser when called
	return yyparse();
}

// Patch for Ubuntu
int yyerror (char const *message)
{
	/* Error message of type
	 * ERROR at <line_number>:
	 * 		<error_message>	
	 */
  	return fprintf (stderr, "ERROR %s %d:\n\t%s\n", "at", yylineno, message);
  	fputs (message, stderr);
  	fputc ('\n', stderr);
  	return 0;
}
