/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include "simple.h"

#define nbMax 100

#define MAX_DO_WHILE 100  // Taille maximale de la pile des boucles do...while

int compteurSi = 0, compteurTest = 0, compteurWhile = 0, compteurFor = 0 ,topDoWhile = 0;
extern FILE *yyout;

// Stack to handle nested for loop labels
int forLabelStack[nbMax];
int top = -1;

int doWhileLabels[MAX_DO_WHILE];  // Tableau pour stocker les étiquettes de boucle do...while


char *header = "extern printf,scanf \nsection .data\n; declaration des variables en memoire\na:  dd  0\nb:  dd  0\nc:  dd  0\nd:  dd  0\nfmt:db \"%d\", 10, 0 \nfmtlec:db \"%d\",0\nsection .text\nglobal _start\n\n_start:\n\n";
char *trailer = "mov eax,1 ; sys_exit \nmov ebx,0; Exit with return code of 0 (no error)\nint 80h";
char *add = " ; addition\npop eax\npop ebx\nadd eax,ebx\npush eax\n\n";
char *mul = " ;multiplication\npop eax\npop ebx\nmul ebx\npush eax\n\n";
char *affec = " ;affectation\npop eax\nmov";
char *take = " ;recuperation en memoire\nmov eax,";
char *affec1 = ";affectation\n";
char *afficher1 = ";afficher\nmov eax,";
char *afficher2 = "\npush eax\npush dword fmt\ncall printf\n\n";
char *lire1 = ";lire\npush ";
char *lire2 = "\npush dword fmtlec\ncall scanf\n\n";
char *cmp = "pop ebx\npop eax\ncmp eax, ebx\n\n";
char *cmpEgal;
char *testGene;
char *cmpDifferent;
char *cmpSuperieur;
char *cmpInferieur;
char *tmp1, *tmp2;
int sinonVu = 0;

int yylex();
int yyerror(char *str);

void pushDoWhile(int label) {
    if (topDoWhile < MAX_DO_WHILE) {
        doWhileLabels[topDoWhile++] = label;
    } else {
        fprintf(stderr, "Erreur : Dépassement de capacité de la pile des boucles do...while.\n");
        
    }
}

int popDoWhile() {
    if (topDoWhile > 0) {
        return doWhileLabels[--topDoWhile];
    } else {
        fprintf(stderr, "Erreur : Tentative de dépiler depuis une pile des boucles do...while vide.\n");
    }
}

void push(int label) {
    if (top < nbMax - 1) {
        forLabelStack[++top] = label;
    }
}

int pop() {
    if (top >= 0) {
        return forLabelStack[top--];
    }
    return -1; // Stack is empty
}


#line 144 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "simple.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_VARIABLE = 5,                   /* VARIABLE  */
  YYSYMBOL_SI = 6,                         /* SI  */
  YYSYMBOL_ALORS = 7,                      /* ALORS  */
  YYSYMBOL_SINON = 8,                      /* SINON  */
  YYSYMBOL_FSI = 9,                        /* FSI  */
  YYSYMBOL_FSIN = 10,                      /* FSIN  */
  YYSYMBOL_READ = 11,                      /* READ  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_DONE = 13,                      /* DONE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_TO = 16,                        /* TO  */
  YYSYMBOL_STEP = 17,                      /* STEP  */
  YYSYMBOL_ENDFOR = 18,                    /* ENDFOR  */
  YYSYMBOL_ADD = 19,                       /* ADD  */
  YYSYMBOL_MUL = 20,                       /* MUL  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_EQEQ = 23,                      /* EQEQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_LT = 25,                        /* LT  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_Program = 30,                   /* Program  */
  YYSYMBOL_program_body = 31,              /* program_body  */
  YYSYMBOL_stat = 32,                      /* stat  */
  YYSYMBOL_bloc = 33,                      /* bloc  */
  YYSYMBOL_instr = 34,                     /* instr  */
  YYSYMBOL_blocFor = 35,                   /* blocFor  */
  YYSYMBOL_36_1 = 36,                      /* $@1  */
  YYSYMBOL_blocIntFor = 37,                /* blocIntFor  */
  YYSYMBOL_blocDoWhile = 38,               /* blocDoWhile  */
  YYSYMBOL_39_2 = 39,                      /* $@2  */
  YYSYMBOL_blocIntDoWhile = 40,            /* blocIntDoWhile  */
  YYSYMBOL_blocWhile = 41,                 /* blocWhile  */
  YYSYMBOL_blocIntWhile = 42,              /* blocIntWhile  */
  YYSYMBOL_etiquetWhile = 43,              /* etiquetWhile  */
  YYSYMBOL_LOOP = 44,                      /* LOOP  */
  YYSYMBOL_exp_bool = 45,                  /* exp_bool  */
  YYSYMBOL_ENDWHILE = 46,                  /* ENDWHILE  */
  YYSYMBOL_blocSi = 47,                    /* blocSi  */
  YYSYMBOL_finSi = 48,                     /* finSi  */
  YYSYMBOL_alo = 49,                       /* alo  */
  YYSYMBOL_sino = 50,                      /* sino  */
  YYSYMBOL_cond = 51,                      /* cond  */
  YYSYMBOL_E = 52,                         /* E  */
  YYSYMBOL_T = 53,                         /* T  */
  YYSYMBOL_F = 54                          /* F  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   107

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  98

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   106,   107,   110,   111,   112,   113,   114,
     117,   118,   121,   122,   123,   124,   128,   127,   144,   145,
     146,   147,   148,   149,   150,   154,   153,   163,   164,   165,
     166,   167,   171,   174,   175,   176,   177,   180,   187,   190,
     197,   204,   205,   208,   224,   232,   240,   246,   252,   258,
     266,   267,   270,   271,   274,   275
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "PRINT",
  "VARIABLE", "SI", "ALORS", "SINON", "FSI", "FSIN", "READ", "WHILE",
  "DONE", "DO", "FOR", "TO", "STEP", "ENDFOR", "ADD", "MUL", "EQUAL",
  "SEMI", "EQEQ", "NEQ", "LT", "GT", "LPAREN", "RPAREN", "$accept",
  "Program", "program_body", "stat", "bloc", "instr", "blocFor", "$@1",
  "blocIntFor", "blocDoWhile", "$@2", "blocIntDoWhile", "blocWhile",
  "blocIntWhile", "etiquetWhile", "LOOP", "exp_bool", "ENDWHILE", "blocSi",
  "finSi", "alo", "sino", "cond", "E", "T", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      38,    12,   -13,    20,    25,   -74,   -74,    34,    51,   -74,
      38,   -74,    41,   -74,   -74,   -74,   -74,   -74,     2,    43,
      59,   -74,    20,    38,    39,   -74,   -74,     7,   -74,   -74,
     -74,    57,    58,   -74,    45,   -74,     7,    63,   -74,   -74,
     -74,   -74,    67,   -74,   -74,    43,   -74,    43,    43,    43,
      43,    43,    43,    13,   -74,    53,    20,   -10,    58,   -74,
      52,    54,    56,    66,   -74,   -74,   -74,     7,    53,    68,
      53,    68,    43,   -74,   -74,   -74,   -74,    74,   -74,   -74,
     -74,   -74,   -74,    55,   -74,    43,    26,   -74,    50,    50,
       7,    69,   -74,    50,   -74,   -74,   -74,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    37,    25,     0,     0,     2,
       3,     5,     0,     8,     9,     7,     6,    13,     0,     0,
       0,    14,     0,     0,     0,     1,     4,    10,    54,    55,
      15,    12,    50,    52,     0,    44,     0,     0,    39,    27,
      29,    31,     0,    30,    28,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,    51,    53,
       0,     0,     0,     0,    45,    43,    41,     0,    33,     0,
      34,     0,     0,    46,    47,    48,    49,     0,    36,    40,
      32,    35,    26,     0,    42,     0,     0,    16,     0,    18,
      21,     0,    20,    19,    24,    22,    17,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,    75,   -74,     0,   -74,    14,   -74,   -73,    72,
     -74,   -74,    15,     5,   -74,   -74,    30,    27,     3,    22,
     -74,   -74,     1,   -44,    60,   -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    68,    12,    90,    88,    91,    14,
      23,    42,    92,    69,    22,    55,    37,    80,    70,    66,
      36,    67,    38,    31,    32,    33
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    57,    34,    16,    20,    28,    72,    29,    18,    47,
      11,     1,     2,    16,    13,    15,    94,    17,     4,    30,
      97,    64,    65,    39,    13,    15,    44,    46,    83,    19,
      21,    59,    60,    61,    62,    63,    53,    40,    43,    24,
      87,    86,     1,     2,     3,    47,    28,    19,    29,     4,
       5,    25,     6,     7,     1,     2,     3,     1,     2,     3,
      45,     4,     5,    27,     4,     7,    35,    77,    49,    50,
      51,    52,    85,    78,    47,    81,    47,    54,    48,    56,
      73,    79,    74,    65,    75,    26,    71,    96,    89,    89,
      95,    93,    93,    89,    76,    41,    93,     0,    82,    84,
       0,     0,     0,     0,     0,     0,     0,    58
};

static const yytype_int8 yycheck[] =
{
       0,    45,    19,     0,     3,     3,    16,     5,    21,    19,
      10,     4,     5,    10,     0,     0,    89,     5,    11,    18,
      93,     8,     9,    23,    10,    10,    23,    27,    72,    27,
       5,    48,    49,    50,    51,    52,    36,    23,    23,     5,
      14,    85,     4,     5,     6,    19,     3,    27,     5,    11,
      12,     0,    14,    15,     4,     5,     6,     4,     5,     6,
      21,    11,    12,    22,    11,    15,     7,    67,    23,    24,
      25,    26,    17,    68,    19,    70,    19,    14,    20,    12,
      28,    13,    28,     9,    28,    10,    56,    18,    88,    89,
      90,    88,    89,    93,    28,    23,    93,    -1,    71,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    11,    12,    14,    15,    30,    31,
      32,    33,    34,    35,    38,    41,    47,     5,    21,    27,
      51,     5,    43,    39,     5,     0,    31,    22,     3,     5,
      51,    52,    53,    54,    54,     7,    49,    45,    51,    33,
      35,    38,    40,    41,    47,    21,    33,    19,    20,    23,
      24,    25,    26,    33,    14,    44,    12,    52,    53,    54,
      54,    54,    54,    54,     8,     9,    48,    50,    33,    42,
      47,    45,    16,    28,    28,    28,    28,    33,    42,    13,
      46,    42,    46,    52,    48,    17,    52,    14,    36,    33,
      35,    37,    41,    47,    37,    33,    18,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    31,    31,    32,    32,    32,    32,    32,
      33,    33,    34,    34,    34,    34,    36,    35,    37,    37,
      37,    37,    37,    37,    37,    39,    38,    40,    40,    40,
      40,    40,    41,    42,    42,    42,    42,    43,    44,    45,
      46,    47,    47,    48,    49,    50,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     3,     3,     2,     2,     3,     0,    12,     1,     1,
       1,     1,     2,     2,     2,     0,     6,     1,     1,     1,
       1,     1,     6,     1,     1,     2,     2,     0,     1,     1,
       1,     5,     7,     1,     1,     1,     5,     5,     5,     5,
       1,     3,     1,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: program_body  */
#line 103 "parser.y"
                 { printf("Aucune erreur de syntaxe détectée \n"); }
#line 1246 "parser.c"
    break;

  case 12: /* instr: VARIABLE EQUAL E  */
#line 121 "parser.y"
                     { fprintf(yyout, "%s [%c], eax\n\n", affec, yyvsp[-2]); }
#line 1252 "parser.c"
    break;

  case 13: /* instr: PRINT VARIABLE  */
#line 122 "parser.y"
                     { fprintf(yyout, "%s [%c] %s", afficher1, yyvsp[0], afficher2); }
#line 1258 "parser.c"
    break;

  case 14: /* instr: READ VARIABLE  */
#line 123 "parser.y"
                    { fprintf(yyout, "%s %c %s", lire1, yyvsp[0], lire2); }
#line 1264 "parser.c"
    break;

  case 15: /* instr: VARIABLE EQUAL cond  */
#line 124 "parser.y"
                          { fprintf(yyout, "%s [%c], eax\n\n", affec, yyvsp[-2]); }
#line 1270 "parser.c"
    break;

  case 16: /* $@1: %empty  */
#line 128 "parser.y"
    {
        compteurFor++;
		fprintf(yyout, ";*************** Boucle for***** ****\n");
		fprintf(yyout, "mov dword [%c], %d\n", yyvsp[-7], yyvsp[-5]); // initialisation
        fprintf(yyout, "debutFor%d:\n", compteurFor); // étiquette début
        fprintf(yyout, "mov eax, [%c]\ncmp eax, %d\njg finFor%d\n", yyvsp[-7], yyvsp[-3], compteurFor); // condition
        fprintf(yyout, "; code du bloc\n");
        push(compteurFor);
    }
#line 1284 "parser.c"
    break;

  case 17: /* blocFor: FOR VARIABLE EQUAL E TO E STEP E DO $@1 blocIntFor ENDFOR  */
#line 138 "parser.y"
    {
        int forLabel = pop();
        fprintf(yyout, "add dword [%c], %d\njmp debutFor%d\nfinFor%d:\n", yyvsp[-10], yyvsp[-4], forLabel, forLabel); // incrémentation et fin
    }
#line 1293 "parser.c"
    break;

  case 25: /* $@2: %empty  */
#line 154 "parser.y"
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }
#line 1303 "parser.c"
    break;

  case 32: /* blocWhile: WHILE etiquetWhile exp_bool LOOP blocIntWhile ENDWHILE  */
#line 171 "parser.y"
                                                           { fprintf(yyout, ";*************** ***** ****Réduction du bloc while\n"); }
#line 1309 "parser.c"
    break;

  case 37: /* etiquetWhile: %empty  */
#line 180 "parser.y"
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }
#line 1319 "parser.c"
    break;

  case 38: /* LOOP: DO  */
#line 187 "parser.y"
       { fprintf(yyout, ";*************** ***** ****Réduction du do\n"); }
#line 1325 "parser.c"
    break;

  case 39: /* exp_bool: cond  */
#line 191 "parser.y"
    {
        fprintf(yyout, ";*************** ***** ****Réduction de la condition\n");
        fprintf(yyout, "pop eax\ncmp eax,1\njne finWhile%d\n", compteurWhile);
    }
#line 1334 "parser.c"
    break;

  case 40: /* ENDWHILE: DONE  */
#line 198 "parser.y"
    {
        fprintf(yyout, ";*************** ***** ****Réduction du done\n");
        fprintf(yyout, "jmp debutWhile%d\nfinWhile%d:\n", compteurWhile, compteurWhile);
    }
#line 1343 "parser.c"
    break;

  case 42: /* blocSi: SI cond alo bloc sino bloc finSi  */
#line 205 "parser.y"
                                       { fprintf(yyout, ";Condition detectée 2\n"); }
#line 1349 "parser.c"
    break;

  case 43: /* finSi: FSI  */
#line 209 "parser.y"
    {
        if (sinonVu)
        {
            fprintf(yyout, "suite%d:\n", compteurSi);
            fprintf(yyout, ";Réduction du fsis%d\n", compteurSi);
            sinonVu = 0;
        }
        else
        {
            fprintf(yyout, "sinon%d:\n", compteurSi);
            fprintf(yyout, ";Réduction du fsi%d\n", compteurSi);
        }
    }
#line 1367 "parser.c"
    break;

  case 44: /* alo: ALORS  */
#line 225 "parser.y"
    {
        compteurSi++;
        fprintf(yyout, ";Réduction du alors%d\n", compteurSi);
        fprintf(yyout, "pop eax\ncmp eax,1\njne sinon%d\n", compteurSi);
    }
#line 1377 "parser.c"
    break;

  case 45: /* sino: SINON  */
#line 233 "parser.y"
    {
        fprintf(yyout, "jmp suite%d\nsinon%d:\n", compteurSi, compteurSi);
        fprintf(yyout, ";Réduction du sinon%d\n", compteurSi);
        sinonVu = 1;
    }
#line 1387 "parser.c"
    break;

  case 46: /* cond: LPAREN F EQEQ F RPAREN  */
#line 241 "parser.y"
    {
        compteurTest++;
        cmpEgal = ";Teste d'égalité\n";
        fprintf(yyout, "%s%sjne test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpEgal, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1397 "parser.c"
    break;

  case 47: /* cond: LPAREN F NEQ F RPAREN  */
#line 247 "parser.y"
    {
        compteurTest++;
        cmpDifferent = ";Teste de différence\n";
        fprintf(yyout, "%s%sjne test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpDifferent, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1407 "parser.c"
    break;

  case 48: /* cond: LPAREN F LT F RPAREN  */
#line 253 "parser.y"
    {
        compteurTest++;
        cmpInferieur = ";Teste d'infériorité\n";
        fprintf(yyout, "%s%sjge test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpInferieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1417 "parser.c"
    break;

  case 49: /* cond: LPAREN F GT F RPAREN  */
#line 259 "parser.y"
    {
        compteurTest++;
        cmpSuperieur = ";Teste de superiorité\n";
        fprintf(yyout, "%s%sjg test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpSuperieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1427 "parser.c"
    break;

  case 51: /* E: E ADD T  */
#line 267 "parser.y"
              { fprintf(yyout, "%s ", add); }
#line 1433 "parser.c"
    break;

  case 53: /* T: T MUL F  */
#line 271 "parser.y"
              { fprintf(yyout, "%s ", mul); }
#line 1439 "parser.c"
    break;

  case 54: /* F: INTEGER  */
#line 274 "parser.y"
            { fprintf(yyout, "push %d\n", yyvsp[0]); }
#line 1445 "parser.c"
    break;

  case 55: /* F: VARIABLE  */
#line 275 "parser.y"
               { fprintf(yyout, "%s [%c] \npush eax\n", take, yyvsp[0]); }
#line 1451 "parser.c"
    break;


#line 1455 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 277 "parser.y"


int main(void)
{
    yyout = fopen("davm.asm", "w");
    fprintf(yyout, "%s", header);
    yyparse();
    fprintf(yyout, "%s", trailer);
    fclose(yyout);
    return 0;
}

int yyerror(char *str)
{
    printf("error parsing %s\n", str);
    return 0;
}
