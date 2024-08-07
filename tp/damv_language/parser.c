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

int compteurSi = 0, compteurTest = 0, compteurWhile = 0, compteurFor = 0 ,topDoWhile = 0, compteurSwitch = 0;
extern FILE *yyout;

// Stack to handle nested for loop labels
int forLabelStack[nbMax];
int top = -1;

int doWhileLabels[MAX_DO_WHILE];  // Tableau pour stocker les étiquettes de boucle do...while


char *header = "extern printf,scanf \nsection .data\n; declaration des variables en memoire\na:  dd  0\nb:  dd  0\nc:  dd  0\nd:  dd  0\nfmt:db \"%d\", 10, 0 \nfmtlec:db \"%d\",0\nsection .text\nglobal _start\n\n_start:\n\n";
char *trailer = "mov eax,1 ; sys_exit \nmov ebx,0; Exit with return code of 0 (no error)\nint 80h";
char *add = " ; addition\npop eax\npop ebx\nadd eax,ebx\npush eax\n\n";
char *sub = " ; soustraction\npop eax\npop ebx\nsub eax,ebx\npush eax\n\n";
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


#line 145 "parser.c"

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
  YYSYMBOL_ABAH = 4,                       /* ABAH  */
  YYSYMBOL_VARIABLE = 5,                   /* VARIABLE  */
  YYSYMBOL_NGE = 6,                        /* NGE  */
  YYSYMBOL_NDO = 7,                        /* NDO  */
  YYSYMBOL_NDEYA = 8,                      /* NDEYA  */
  YYSYMBOL_AMANNGE = 9,                    /* AMANNGE  */
  YYSYMBOL_LAN = 10,                       /* LAN  */
  YYSYMBOL_NTIETE = 11,                    /* NTIETE  */
  YYSYMBOL_AMAN = 12,                      /* AMAN  */
  YYSYMBOL_BO = 13,                        /* BO  */
  YYSYMBOL_ASU = 14,                       /* ASU  */
  YYSYMBOL_DOUBLEMARK = 15,                /* DOUBLEMARK  */
  YYSYMBOL_YA = 16,                        /* YA  */
  YYSYMBOL_ITIE = 17,                      /* ITIE  */
  YYSYMBOL_AMANASU = 18,                   /* AMANASU  */
  YYSYMBOL_AKOK_LO = 19,                   /* AKOK_LO  */
  YYSYMBOL_A_POULI = 20,                   /* A_POULI  */
  YYSYMBOL_ANOAN = 21,                     /* ANOAN  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_DZAM_DEUH = 23,                 /* DZAM_DEUH  */
  YYSYMBOL_ASSEULEN = 24,                  /* ASSEULEN  */
  YYSYMBOL_ABOITE = 25,                    /* ABOITE  */
  YYSYMBOL_ABUI = 26,                      /* ABUI  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_SWITCH = 29,                    /* SWITCH  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_ENDSWITCH = 31,                 /* ENDSWITCH  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_FINCASE = 33,                   /* FINCASE  */
  YYSYMBOL_AVAH = 34,                      /* AVAH  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_Program = 36,                   /* Program  */
  YYSYMBOL_program_body = 37,              /* program_body  */
  YYSYMBOL_stat = 38,                      /* stat  */
  YYSYMBOL_bloc = 39,                      /* bloc  */
  YYSYMBOL_instr = 40,                     /* instr  */
  YYSYMBOL_blocSwitch = 41,                /* blocSwitch  */
  YYSYMBOL_debutSwitch = 42,               /* debutSwitch  */
  YYSYMBOL_listeCase = 43,                 /* listeCase  */
  YYSYMBOL_case_break = 44,                /* case_break  */
  YYSYMBOL_stat_list = 45,                 /* stat_list  */
  YYSYMBOL_exp = 46,                       /* exp  */
  YYSYMBOL_blocFor = 47,                   /* blocFor  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_blocIntFor = 49,                /* blocIntFor  */
  YYSYMBOL_blocDoWhile = 50,               /* blocDoWhile  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_blocIntDoWhile = 52,            /* blocIntDoWhile  */
  YYSYMBOL_blocWhile = 53,                 /* blocWhile  */
  YYSYMBOL_blocIntWhile = 54,              /* blocIntWhile  */
  YYSYMBOL_etiquetWhile = 55,              /* etiquetWhile  */
  YYSYMBOL_LOOP = 56,                      /* LOOP  */
  YYSYMBOL_exp_bool = 57,                  /* exp_bool  */
  YYSYMBOL_ENDWHILE = 58,                  /* ENDWHILE  */
  YYSYMBOL_blocSi = 59,                    /* blocSi  */
  YYSYMBOL_finSi = 60,                     /* finSi  */
  YYSYMBOL_alo = 61,                       /* alo  */
  YYSYMBOL_sino = 62,                      /* sino  */
  YYSYMBOL_cond = 63,                      /* cond  */
  YYSYMBOL_E = 64,                         /* E  */
  YYSYMBOL_T = 65,                         /* T  */
  YYSYMBOL_F = 66                          /* F  */
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
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  117

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   113,   114,   117,   118,   119,   120,   121,
     122,   125,   126,   129,   130,   131,   132,   135,   138,   144,
     145,   146,   149,   150,   153,   154,   157,   158,   163,   162,
     179,   180,   181,   182,   183,   184,   185,   190,   189,   199,
     200,   201,   202,   203,   207,   210,   211,   212,   213,   216,
     223,   226,   233,   240,   241,   244,   260,   268,   276,   282,
     288,   294,   302,   303,   304,   307,   308,   311,   312
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "ABAH",
  "VARIABLE", "NGE", "NDO", "NDEYA", "AMANNGE", "LAN", "NTIETE", "AMAN",
  "BO", "ASU", "DOUBLEMARK", "YA", "ITIE", "AMANASU", "AKOK_LO", "A_POULI",
  "ANOAN", "SEMI", "DZAM_DEUH", "ASSEULEN", "ABOITE", "ABUI", "LPAREN",
  "RPAREN", "SWITCH", "BREAK", "ENDSWITCH", "CASE", "FINCASE", "AVAH",
  "$accept", "Program", "program_body", "stat", "bloc", "instr",
  "blocSwitch", "debutSwitch", "listeCase", "case_break", "stat_list",
  "exp", "blocFor", "$@1", "blocIntFor", "blocDoWhile", "$@2",
  "blocIntDoWhile", "blocWhile", "blocIntWhile", "etiquetWhile", "LOOP",
  "exp_bool", "ENDWHILE", "blocSi", "finSi", "alo", "sino", "cond", "E",
  "T", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    20,    21,     1,    52,   -75,   -75,    62,    44,    35,
     -75,     7,   -75,    32,   -75,   -75,   -75,   -75,   -75,   -75,
       2,    71,    63,   -75,     1,    55,    58,   -75,    19,   -75,
      -4,    89,   -75,   -75,   -75,    90,   -75,   -75,    -4,    81,
     -75,    90,    98,   -75,   -75,   -75,   -75,    64,   -75,   -75,
      71,    80,    71,    71,    71,   -75,    71,    71,    71,    71,
      54,   -75,    93,     1,   -15,   110,    83,    89,    89,   -75,
      87,    88,    91,    92,   -75,   -75,   -75,    90,    93,   105,
      93,   105,    71,   103,   -75,   -75,   -75,   -75,   -75,   112,
     -75,   -75,   -75,   -75,   -75,     5,     7,   -75,    71,     7,
      94,    14,   -75,   -75,    80,   -75,   -75,    67,    67,    90,
     104,   -75,    67,   -75,   -75,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    49,    37,     0,     0,     0,
       2,     3,     5,     0,    10,     8,     9,     7,     6,    14,
       0,     0,     0,    15,     0,     0,     0,    67,    68,    18,
      26,    62,    65,     1,     4,    11,    68,    16,    13,     0,
      56,     0,     0,    51,    39,    41,    43,     0,    42,    40,
       0,    21,     0,     0,     0,    12,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,     0,    63,    64,    66,
       0,     0,     0,     0,    57,    55,    53,     0,    45,     0,
      46,     0,     0,     0,    17,    58,    59,    60,    61,     0,
      48,    52,    44,    47,    38,     0,     0,    54,     0,    24,
      23,     0,    25,    22,    20,    28,    19,     0,    30,    33,
       0,    32,    31,    36,    34,    29,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   114,   -73,   -25,   -75,   -75,   -75,    22,   -75,
      24,   -75,   -19,   -75,   -74,   102,   -75,   -75,   -16,    30,
     -75,   -75,    65,    48,   -22,    41,   -75,   -75,    11,   -18,
      49,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    51,    66,   104,
     100,    29,    15,   107,   110,    16,    25,    47,    17,    79,
      24,    62,    42,    92,    18,    76,    41,    77,    43,    30,
      31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    82,    38,    49,    52,    27,    45,    36,    39,    48,
      55,     1,     2,     3,    22,    52,    60,     4,     5,    53,
       6,     7,    98,    99,    52,    19,    99,   105,    21,    21,
      53,    37,    64,    52,   113,    33,     8,    78,   116,    53,
      80,    69,    20,    70,    71,    72,    73,    27,    53,    28,
     -27,   -27,    89,    78,    35,    78,    80,    23,    80,     1,
       2,     3,    74,    75,    95,     4,     5,    26,     6,     7,
      40,     1,     2,     3,    27,    63,    36,     4,     5,    50,
     101,     7,   108,   108,   114,   112,   112,   108,   109,   109,
     112,   111,   111,   109,     1,     2,   111,     1,     2,     3,
       4,    67,    68,     4,    56,    57,    58,    59,    90,    54,
      93,    61,    65,    83,    84,    85,    86,    91,    96,    87,
      88,    75,   115,   102,   103,    34,   106,    46,    81,    94,
      97
};

static const yytype_int8 yycheck[] =
{
      25,    16,    20,    25,    19,     3,    25,     5,    21,    25,
      35,     4,     5,     6,     3,    19,    41,    10,    11,    34,
      13,    14,    17,    96,    19,     5,    99,    13,    27,    27,
      34,    20,    50,    19,   108,     0,    29,    62,   112,    34,
      62,    54,    21,    56,    57,    58,    59,     3,    34,     5,
      31,    32,    77,    78,    22,    80,    78,     5,    80,     4,
       5,     6,     8,     9,    82,    10,    11,     5,    13,    14,
       7,     4,     5,     6,     3,    11,     5,    10,    11,    21,
      98,    14,   107,   108,   109,   107,   108,   112,   107,   108,
     112,   107,   108,   112,     4,     5,   112,     4,     5,     6,
      10,    52,    53,    10,    23,    24,    25,    26,    78,    20,
      80,    13,    32,     3,    31,    28,    28,    12,    15,    28,
      28,     9,    18,    99,    30,    11,   104,    25,    63,    81,
      89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     5,     6,    10,    11,    13,    14,    29,    36,
      37,    38,    39,    40,    41,    47,    50,    53,    59,     5,
      21,    27,    63,     5,    55,    51,     5,     3,     5,    46,
      64,    65,    66,     0,    37,    22,     5,    63,    64,    66,
       7,    61,    57,    63,    39,    47,    50,    52,    53,    59,
      21,    42,    19,    34,    20,    39,    23,    24,    25,    26,
      39,    13,    56,    11,    64,    32,    43,    65,    65,    66,
      66,    66,    66,    66,     8,     9,    60,    62,    39,    54,
      59,    57,    16,     3,    31,    28,    28,    28,    28,    39,
      54,    12,    58,    54,    58,    64,    15,    60,    17,    38,
      45,    64,    45,    30,    44,    13,    43,    48,    39,    47,
      49,    53,    59,    49,    39,    18,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    38,    38,
      38,    39,    39,    40,    40,    40,    40,    41,    42,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    48,    47,
      49,    49,    49,    49,    49,    49,    49,    51,    50,    52,
      52,    52,    52,    52,    53,    54,    54,    54,    54,    55,
      56,    57,    58,    59,    59,    60,    61,    62,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     2,     3,     5,     0,     6,
       5,     0,     1,     0,     1,     2,     1,     1,     0,    12,
       1,     1,     1,     1,     2,     2,     2,     0,     6,     1,
       1,     1,     1,     1,     6,     1,     1,     2,     2,     0,
       1,     1,     1,     5,     7,     1,     1,     1,     5,     5,
       5,     5,     1,     3,     3,     1,     3,     1,     1
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
#line 110 "parser.y"
                 { printf("Aucune erreur de syntaxe détectée \n"); }
#line 1279 "parser.c"
    break;

  case 13: /* instr: VARIABLE ANOAN E  */
#line 129 "parser.y"
                     { fprintf(yyout, "%s [%c], eax\n\n", affec, yyvsp[-2]); }
#line 1285 "parser.c"
    break;

  case 14: /* instr: ABAH VARIABLE  */
#line 130 "parser.y"
                    { fprintf(yyout, "%s [%c] %s", afficher1, yyvsp[0], afficher2); }
#line 1291 "parser.c"
    break;

  case 15: /* instr: LAN VARIABLE  */
#line 131 "parser.y"
                   { fprintf(yyout, "%s %c %s", lire1, yyvsp[0], lire2); }
#line 1297 "parser.c"
    break;

  case 16: /* instr: VARIABLE ANOAN cond  */
#line 132 "parser.y"
                          { fprintf(yyout, "%s [%c], eax\n\n", affec, yyvsp[-2]); }
#line 1303 "parser.c"
    break;

  case 17: /* blocSwitch: SWITCH exp debutSwitch listeCase ENDSWITCH  */
#line 135 "parser.y"
                                               { fprintf(yyout, "finSwitch%d:\n", compteurSwitch); compteurSwitch++; }
#line 1309 "parser.c"
    break;

  case 18: /* debutSwitch: %empty  */
#line 138 "parser.y"
    { 
        compteurSwitch++;
        fprintf(yyout, "debutSwitch%d:\n", compteurSwitch); 
    }
#line 1318 "parser.c"
    break;

  case 22: /* case_break: BREAK  */
#line 149 "parser.y"
          { fprintf(yyout, "jmp finSwitch%d\n", compteurSwitch); }
#line 1324 "parser.c"
    break;

  case 26: /* exp: E  */
#line 157 "parser.y"
      { fprintf(yyout, "pop eax\n"); }
#line 1330 "parser.c"
    break;

  case 27: /* exp: VARIABLE  */
#line 158 "parser.y"
               { fprintf(yyout, "mov eax, [%c]\n", yyvsp[0]); }
#line 1336 "parser.c"
    break;

  case 28: /* $@1: %empty  */
#line 163 "parser.y"
    {
        compteurFor++;
		fprintf(yyout, ";*************** Boucle for***** ****\n");
		fprintf(yyout, "mov dword [%c], %d\n", yyvsp[-7], yyvsp[-5]); // initialisation
        fprintf(yyout, "debutFor%d:\n", compteurFor); // étiquette début
        fprintf(yyout, "mov eax, [%c]\ncmp eax, %d\njg finFor%d\n", yyvsp[-7], yyvsp[-3], compteurFor); // condition
        fprintf(yyout, "; code du bloc\n");
        push(compteurFor);
    }
#line 1350 "parser.c"
    break;

  case 29: /* blocFor: ASU VARIABLE ANOAN E YA E ITIE E BO $@1 blocIntFor AMANASU  */
#line 173 "parser.y"
    {
        int forLabel = pop();
        fprintf(yyout, "add dword [%c], %d\njmp debutFor%d\nfinFor%d:\n", yyvsp[-10], yyvsp[-4], forLabel, forLabel); // incrémentation et fin
    }
#line 1359 "parser.c"
    break;

  case 37: /* $@2: %empty  */
#line 190 "parser.y"
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }
#line 1369 "parser.c"
    break;

  case 44: /* blocWhile: NTIETE etiquetWhile exp_bool LOOP blocIntWhile ENDWHILE  */
#line 207 "parser.y"
                                                            { fprintf(yyout, ";*************** ***** ****Réduction du bloc while\n"); }
#line 1375 "parser.c"
    break;

  case 49: /* etiquetWhile: %empty  */
#line 216 "parser.y"
    {
        compteurWhile++;
        fprintf(yyout, ";********Lieu de l'étiquete\n");
        fprintf(yyout, "debutWhile%d:\n", compteurWhile);
    }
#line 1385 "parser.c"
    break;

  case 50: /* LOOP: BO  */
#line 223 "parser.y"
       { fprintf(yyout, ";*************** ***** ****Réduction du do\n"); }
#line 1391 "parser.c"
    break;

  case 51: /* exp_bool: cond  */
#line 227 "parser.y"
    {
        fprintf(yyout, ";*************** ***** ****Réduction de la condition\n");
        fprintf(yyout, "pop eax\ncmp eax,1\njne finWhile%d\n", compteurWhile);
    }
#line 1400 "parser.c"
    break;

  case 52: /* ENDWHILE: AMAN  */
#line 234 "parser.y"
    {
        fprintf(yyout, ";*************** ***** ****Réduction du done\n");
        fprintf(yyout, "jmp debutWhile%d\nfinWhile%d:\n", compteurWhile, compteurWhile);
    }
#line 1409 "parser.c"
    break;

  case 54: /* blocSi: NGE cond alo bloc sino bloc finSi  */
#line 241 "parser.y"
                                        { fprintf(yyout, ";Condition detectée 2\n"); }
#line 1415 "parser.c"
    break;

  case 55: /* finSi: AMANNGE  */
#line 245 "parser.y"
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
#line 1433 "parser.c"
    break;

  case 56: /* alo: NDO  */
#line 261 "parser.y"
    {
        compteurSi++;
        fprintf(yyout, ";Réduction du alors%d\n", compteurSi);
        fprintf(yyout, "pop eax\ncmp eax,1\njne sinon%d\n", compteurSi);
    }
#line 1443 "parser.c"
    break;

  case 57: /* sino: NDEYA  */
#line 269 "parser.y"
    {
        fprintf(yyout, "jmp suite%d\nsinon%d:\n", compteurSi, compteurSi);
        fprintf(yyout, ";Réduction du sinon%d\n", compteurSi);
        sinonVu = 1;
    }
#line 1453 "parser.c"
    break;

  case 58: /* cond: LPAREN F DZAM_DEUH F RPAREN  */
#line 277 "parser.y"
    {
        compteurTest++;
        cmpEgal = ";Teste d'égalité\n";
        fprintf(yyout, "%s%sjne test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpEgal, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1463 "parser.c"
    break;

  case 59: /* cond: LPAREN F ASSEULEN F RPAREN  */
#line 283 "parser.y"
    {
        compteurTest++;
        cmpDifferent = ";Teste de différence\n";
        fprintf(yyout, "%s%sjne test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpDifferent, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1473 "parser.c"
    break;

  case 60: /* cond: LPAREN F ABOITE F RPAREN  */
#line 289 "parser.y"
    {
        compteurTest++;
        cmpInferieur = ";Teste d'infériorité\n";
        fprintf(yyout, "%s%sjge test%d\npush 1\njmp fintest%d \ntest%d:\npush 0\nfintest%d:\n\n\n", cmpInferieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1483 "parser.c"
    break;

  case 61: /* cond: LPAREN F ABUI F RPAREN  */
#line 295 "parser.y"
    {
        compteurTest++;
        cmpSuperieur = ";Teste de superiorité\n";
        fprintf(yyout, "%s%sjg test%d\npush 0\njmp fintest%d \ntest%d:\npush 1\nfintest%d:\n\n\n", cmpSuperieur, cmp, compteurTest, compteurTest, compteurTest, compteurTest);
    }
#line 1493 "parser.c"
    break;

  case 63: /* E: E AKOK_LO T  */
#line 303 "parser.y"
                  { fprintf(yyout, "%s ", add); }
#line 1499 "parser.c"
    break;

  case 64: /* E: E AVAH T  */
#line 304 "parser.y"
               { fprintf(yyout, "%s ", sub); }
#line 1505 "parser.c"
    break;

  case 66: /* T: T A_POULI F  */
#line 308 "parser.y"
                  { fprintf(yyout, "%s ", mul); }
#line 1511 "parser.c"
    break;

  case 67: /* F: INTEGER  */
#line 311 "parser.y"
            { fprintf(yyout, "push %d\n", yyvsp[0]); }
#line 1517 "parser.c"
    break;

  case 68: /* F: VARIABLE  */
#line 312 "parser.y"
               { fprintf(yyout, "%s [%c] \npush eax\n", take, yyvsp[0]); }
#line 1523 "parser.c"
    break;


#line 1527 "parser.c"

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

#line 314 "parser.y"


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
