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

#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
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
    TOK_ERROR = 295
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

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */
