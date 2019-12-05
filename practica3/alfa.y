%{
//Sección de definiciones
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* out;
void yyerror(const char* s);

%}

%token TOK_MAIN TOK_ARRAY
%token TOK_LLAVEIZQUIERDA TOK_CORCHETEIZQUIERDO
%token TOK_LLAVEDERECHA TOK_CORCHETEDERECHO
%token TOK_INT TOK_BOOLEAN
%token TOK_CONSTANTE_ENTERA

%%
program: TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA {fprintf(out, "R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
;
declaraciones: declaracion {fprintf(out, "R2:\t<declaraciones> ::= <declaracion>\n");}
    | declaracion declaraciones {fprintf(out, "R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
;
declaracion: clase identificadores {fprintf(out, "R4:\t<declaracion> ::= <clase> <identificadores>\n");}
;
clase: clase_escalar {fprintf(out, "R5:\t<clase> ::= <clase_escalar>\n");}
    | clase_vector {fprintf(out, "R7:\t<clase> ::= <clase_vector>\n");}
;
clase_escalar: tipo {fprintf(out, "R9:\t<clase_escalar> ::= <tipo>\n");}
;
tipo: TOK_INT {fprintf(out, "R10:\t<tipo> ::= int\n");}
    | TOK_BOOLEAN {fprintf(out, "R11:\t<tipo> ::= boolean\n");}
;
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO {fprintf(out, "R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");}
;
identificadores: identificador {fprintf(out, "R18:\t<identificadores> ::= <identificador>\n");}
    | identificador identificadores {fprintf(out, "R19:\t<identificadores> ::= <identificador> <identificadores>\n");}
;
funciones: funcion funciones {fprintf(out, "R:20\t<funciones> ::= <funcion> <funciones>\n");}
    | {fprintf(out, "R21:\t<funciones> ::= \n");}
;
%%
//Sección de funciones de usuario
int main() {
	yyin = stdin;
	do { 
		yyparse();
	} while(!feof(yyin));
	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}