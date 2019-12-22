/*Autores: David Palomo, Pablo Sánchez. 1361_G3 PAUTLEN */
%{ 
    #include <stdio.h>
    #include "../include/y.tab.h"
    #include "../include/tablaSimbolos.h"

    int row=1, col=1, morferr=0;
    extern FILE* out;
%} 

%option noyywrap

/* Rules Section */
INTEGER [0-9]+
PALABRA "-"?[a-zA-Z][a-zA-Z0-9]*
ENDLINE \n
TAB \t
COMMENT "//".*\n
%%
{COMMENT}   {row++; col=1;}
{ENDLINE}   {row++; col=1;}
{TAB}       {col+=yyleng;}

" "         {col+=yyleng;}
main        {col+=yyleng; fprintf(out, ";D:\tmain\n"); return TOK_MAIN;}
int         {col+=yyleng; fprintf(out, ";D:\tint\n"); return TOK_INT;}
boolean     {col+=yyleng; fprintf(out, ";D:\tboolean\n"); return TOK_BOOLEAN;}
array       {col+=yyleng; fprintf(out, ";D:\tarray\n"); return TOK_ARRAY;}
function    {col+=yyleng; fprintf(out, ";D:\tfunction\n"); return TOK_FUNCTION;}
if          {col+=yyleng; fprintf(out, ";D:\tif\n"); return TOK_IF;}
else        {col+=yyleng; fprintf(out, ";D:\telse\n"); return TOK_ELSE;}
while       {col+=yyleng; fprintf(out, ";D:\twhile\n"); return TOK_WHILE;}
scanf       {col+=yyleng; fprintf(out, ";D:\tscanf\n"); return TOK_SCANF;}
printf      {col+=yyleng; fprintf(out, ";D:\tprintf\n"); return TOK_PRINTF;}
return      {col+=yyleng; fprintf(out, ";D:\treturn\n"); return TOK_RETURN;}
true        {col+=yyleng; fprintf(out, ";D:\ttrue\n"); return TOK_TRUE;}
false        {col+=yyleng; fprintf(out, ";D:\tfalse\n"); return TOK_FALSE;}


";"         {col+=yyleng; fprintf(out, ";D:\t;\n"); return TOK_PUNTOYCOMA;}
","         {col+=yyleng; fprintf(out, ";D:\t,\n"); return TOK_COMA;}
"("         {col+=yyleng; fprintf(out, ";D:\t(\n"); return TOK_PARENTESISIZQUIERDO;}
")"         {col+=yyleng; fprintf(out, ";D:\t)\n"); return TOK_PARENTESISDERECHO;}
"["         {col+=yyleng; fprintf(out, ";D:\t[\n"); return TOK_CORCHETEIZQUIERDO;}
"]"         {col+=yyleng; fprintf(out, ";D:\t]\n"); return TOK_CORCHETEDERECHO;}
"{"         {col+=yyleng; fprintf(out, ";D:\t{\n"); return TOK_LLAVEIZQUIERDA;}
"}"         {col+=yyleng; fprintf(out, ";D:\t}\n"); return TOK_LLAVEDERECHA;}
"="         {col+=yyleng; fprintf(out, ";D:\t=\n"); return TOK_ASIGNACION;}
"+"         {col+=yyleng; fprintf(out, ";D:\t+\n"); return TOK_MAS;}
"-"         {col+=yyleng; fprintf(out, ";D:\t-\n"); return TOK_MENOS;}
"/"         {col+=yyleng; fprintf(out, ";D:\t/\n"); return TOK_DIVISION;}
"*"         {col+=yyleng; fprintf(out, ";D:\t*\n"); return TOK_ASTERISCO;}
"&&"        {col+=yyleng; fprintf(out, ";D:\t&&\n"); return TOK_AND;}
"||"        {col+=yyleng; fprintf(out, ";D:\t||\n"); return TOK_OR;}
"!"         {col+=yyleng; fprintf(out, ";D:\t!\n"); return TOK_NOT;}
"=="        {col+=yyleng; fprintf(out, ";D:\t==\n"); return TOK_IGUAL;}
"!="        {col+=yyleng; fprintf(out, ";D:\t!=\n"); return TOK_DISTINTO;}
"<="        {col+=yyleng; fprintf(out, ";D:\t<=\n"); return TOK_MENORIGUAL;}
">="        {col+=yyleng; fprintf(out, ";D:\t>=\n"); return TOK_MAYORIGUAL;}
"<"         {col+=yyleng; fprintf(out, ";D:\t<\n"); return TOK_MENOR;}
">"         {col+=yyleng; fprintf(out, ";D:\t>\n"); return TOK_MAYOR;}

{PALABRA}   {
            
            if (yyleng > 100) {
		        fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n", row, col, yytext);
		        morferr = -1;
		        return -1;
		    }
            
            strcpy(yylval.atributos.lexema, yytext);
	        col+=yyleng; 
            fprintf(out, ";D:\t%s\n",yytext);
            return TOK_IDENTIFICADOR;
}
{INTEGER} {
            strcpy(yylval.atributos.lexema, yytext);
            yylval.atributos.tipo = ENTERO;
            yylval.atributos.valor = atoi(yytext);

            col+=yyleng;
            fprintf(out, ";D:\t%s\n", yytext); 
            return TOK_CONSTANTE_ENTERA;
}
.                   {fprintf(stderr, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n", row, col, yytext);morferr=1;return -1;}
%%