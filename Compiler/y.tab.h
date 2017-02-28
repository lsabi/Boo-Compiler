/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 29 "boo-yacc.y" /* yacc.c:1909  */

	int integer;		//value of terminal
	char *lexeme; 		//identifier
	typedData *data;	//variable type defined in the boo-variable.h

#line 104 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
