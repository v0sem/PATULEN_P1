/**
 * Autores: David Palomo, Pablo Sánchez.
 * 
 * 1361_G3 PAUTLEN
 **/
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern char *yytext; 
extern int row;
extern int col;
extern int yyleng;


int main(int argc, char **argv)
{
    int ret;

    if(argc < 3){
        printf("Formato: %s in.file out.file\n", argv[0]);
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if(!yyin){
        printf("Fichero de entrada no valido");
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if(!yyout){
        printf("Fichero de salida no valido");
        return -1;
    }

    ret = yylex();

    while(ret) {
        switch(ret){
            case TOK_MAIN:
                fprintf(yyout, "TOK_MAIN\t%d\t%s\n", TOK_MAIN, yytext);
                break;
            
            case TOK_INT:
                fprintf(yyout, "TOK_INT\t%d\t%s\n", TOK_INT, yytext);
                break;
            
            case TOK_BOOLEAN:
                fprintf(yyout, "TOK_BOOLEAN\t%d\t%s\n", TOK_BOOLEAN, yytext);
                break;

            case TOK_ARRAY:
                fprintf(yyout, "TOK_ARRAY\t%d\t%s\n", TOK_ARRAY, yytext);
                break;

            case TOK_FUNCTION:
                fprintf(yyout, "TOK_FUNCTION\t%d\t%s\n", TOK_FUNCTION, yytext);
                break;

            case TOK_IF:
                fprintf(yyout, "TOK_IF\t%d\t%s\n", TOK_IF, yytext);
                break;

            case TOK_ELSE:
                fprintf(yyout, "TOK_ELSE\t%d\t%s\n", TOK_ELSE, yytext);
                break;

            case TOK_WHILE:
                fprintf(yyout, "TOK_WHILE\t%d\t%s\n", TOK_WHILE, yytext);
                break;
            
            case TOK_SCANF:
                fprintf(yyout, "TOK_SCANF\t%d\t%s\n", TOK_SCANF, yytext);
                break;

            case TOK_PRINTF:
                fprintf(yyout, "TOK_PRINTF\t%d\t%s\n", TOK_PRINTF, yytext);
                break;

            case TOK_RETURN:
                fprintf(yyout, "TOK_RETURN\t%d\t%s\n", TOK_RETURN, yytext);
                break;

            case TOK_PUNTOYCOMA:
                fprintf(yyout, "TOK_PUNTOYCOMA\t%d\t%s\n", TOK_PUNTOYCOMA, yytext);
                break;

            case TOK_COMA:
                fprintf(yyout, "TOK_COMA\t%d\t%s\n", TOK_COMA, yytext);
                break;

            case TOK_PARENTESISIZQUIERDO:
                fprintf(yyout, "TOK_PARENTESISIZQUIERDO\t%d\t%s\n", TOK_PARENTESISIZQUIERDO, yytext);
                break;

            case TOK_PARENTESISDERECHO:
                fprintf(yyout, "TOK_PARENTESISDERECHO\t%d\t%s\n", TOK_PARENTESISDERECHO, yytext);
                break;

            case TOK_CORCHETEIZQUIERDO:
                fprintf(yyout, "TOK_CORCHETEIZQUIERDO\t%d\t%s\n", TOK_CORCHETEIZQUIERDO, yytext);
                break;

            case TOK_CORCHETEDERECHO:
                fprintf(yyout, "TOK_CORCHETEDERECHO\t%d\t%s\n", TOK_CORCHETEDERECHO, yytext);
                break;

            case TOK_LLAVEIZQUIERDA:
                fprintf(yyout, "TOK_LLAVEIZQUIERDA\t%d\t%s\n", TOK_LLAVEIZQUIERDA, yytext);
                break;

            case TOK_LLAVEDERECHA:
                fprintf(yyout, "TOK_LLAVEDERECHA\t%d\t%s\n", TOK_LLAVEDERECHA, yytext);
                break;

            case TOK_ASIGNACION:
                fprintf(yyout, "TOK_ASIGNACION\t%d\t%s\n", TOK_ASIGNACION, yytext);
                break;

            case TOK_MAS:
                fprintf(yyout, "TOK_MAS\t%d\t%s\n", TOK_MAS, yytext);
                break;

            case TOK_MENOS:
                fprintf(yyout, "TOK_MENOS\t%d\t%s\n", TOK_MENOS, yytext);
                break;

            case TOK_DIVISION:
                fprintf(yyout, "TOK_DIVISION\t%d\t%s\n", TOK_DIVISION, yytext);
                break;

            case TOK_ASTERISCO:
                fprintf(yyout, "TOK_ASTERISCO\t%d\t%s\n", TOK_ASTERISCO, yytext);
                break;

            case TOK_AND:
                fprintf(yyout, "TOK_AND\t%d\t%s\n", TOK_AND, yytext);
                break;

            case TOK_OR:
                fprintf(yyout, "TOK_OR\t%d\t%s\n", TOK_OR, yytext);
                break;

            case TOK_NOT:
                fprintf(yyout, "TOK_NOT\t%d\t%s\n", TOK_NOT, yytext);
                break;

            case TOK_IGUAL:
                fprintf(yyout, "TOK_IGUAL\t%d\t%s\n", TOK_IGUAL, yytext);
                break;

            case TOK_DISTINTO:
                fprintf(yyout, "TOK_DISTINTO\t%d\t%s\n", TOK_DISTINTO, yytext);
                break;

            case TOK_MENORIGUAL:
                fprintf(yyout, "TOK_MENORIGUAL\t%d\t%s\n", TOK_MENORIGUAL, yytext);
                break;

            case TOK_MAYORIGUAL:
                fprintf(yyout, "TOK_MAYORIGUAL\t%d\t%s\n", TOK_MAYORIGUAL, yytext);
                break;

            case TOK_MENOR:
                fprintf(yyout, "TOK_MENOR\t%d\t%s\n", TOK_MENOR, yytext);
                break;

            case TOK_MAYOR:
                fprintf(yyout, "TOK_MAYOR\t%d\t%s\n", TOK_MAYOR, yytext);
                break;

            case TOK_IDENTIFICADOR:
                if(yyleng > 100){
                    fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",row, col-yyleng, yytext);
                    return -1;
                }else{
                    fprintf(yyout, "TOK_IDENTIFICADOR\t%d\t%s\n", TOK_IDENTIFICADOR, yytext);
                }
                break;

            case TOK_CONSTANTE_ENTERA:
                fprintf(yyout, "TOK_CONSTANTE_ENTERA\t%d\t%s\n", TOK_CONSTANTE_ENTERA, yytext);
                break;

            case TOK_TRUE:
                fprintf(yyout, "TOK_TRUE\t%d\t%s\n", TOK_TRUE, yytext);
                break;

            case TOK_FALSE:
                fprintf(yyout, "TOK_FALSE\t%d\t%s\n", TOK_FALSE, yytext);
                break;

            case TOK_ERROR:
                fprintf(stderr, "****Error en [lin %d col %d]: simbolo no permitido (%s)\n",row, col-yyleng, yytext);
                return -1;
            
            default:
                break;
        }
        ret = yylex();
    }

    fclose(yyin);
    fclose(yyout);

    return 0;
}