#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

extern FILE * yyin;
extern FILE * yyout;
extern int yyleng;
extern char *yytext;
extern int line_count;
extern int col_count;
FILE* out;

int main(int argc, char const *argv[])
{
    if(argc != 3){
        printf("Uso: %s fich-entrada fich-salida\n", argv[0]);
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL){
        printf("Fichero de entrada invalido\n");
        return -1;
    }

    out = fopen(argv[2], "w");
    if(out == NULL){
        printf("Fichero de salida inválido\n");
        return -1;
    }

    yyout = fopen("residuo.txt", "w");
    if(yyout == NULL){
        printf("Fichero de salida inválido\n");
        return -1;
    }

    yyparse();
    fclose(yyin);
    fclose(yyout);
    fclose(out);
    return 0;
}
