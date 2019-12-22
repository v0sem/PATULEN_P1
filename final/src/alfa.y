%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "../include/y.tab.h"
	#include "../include/tablaSimbolos.h"
	#include "../include/tablaHash.h"
	#include "../include/generacion.h"

	extern FILE* out;
	extern FILE* yyout;
	extern int row;
	extern int col;
	extern int yyleng;
	extern int yylex();
	extern int morferr;

	int declar = TRUE, declar_f = TRUE;
	int cur_type, cur_class, cur_cat = VARIABLE;
	int tam = 1;
	int pos_local=1;
	int pos_param=1;
	int etiqueta = 0;
	INFO_SIMBOLO *elem;

	TABLA_SIMBOLOS * t_simb;

	int yyerror(char* s){
		if(morferr!=1)
			fprintf(stderr, "****Error sintactico en [lin %d col %d]\n%s\n", row, col-yyleng, s);
		return -1;
	}
%}

%code requires {
	/* Atributos */
	struct s_tipo_atributos{
		char lexema[101];
		int tipo;
		int valor;
    	int es_var;
	}tipo_atributos;
}

%union
{
	struct s_tipo_atributos atributos;
}


%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_ENTERA

%token TOK_MAIN TOK_TRUE TOK_FALSE
%token TOK_ARRAY 
%token TOK_IGUAL 
%token TOK_MAS TOK_MAYOR TOK_MENOR
%token TOK_LLAVEIZQUIERDA 
%token TOK_CORCHETEIZQUIERDO 
%token TOK_MAYORIGUAL 
%token TOK_MENORIGUAL
%token TOK_LLAVEDERECHA TOK_CORCHETEDERECHO TOK_FUNCTION TOK_IF
%token TOK_INT TOK_BOOLEAN TOK_AND TOK_ASTERISCO TOK_COMA
%token TOK_DISTINTO TOK_DIVISION TOK_ELSE TOK_ASIGNACION
%token TOK_MENOS TOK_NOT TOK_OR TOK_PARENTESISDERECHO TOK_PARENTESISIZQUIERDO
%token TOK_PRINTF TOK_PUNTOYCOMA TOK_SCANF TOK_RETURN TOK_WHILE TOK_ERROR

%type <atributos> exp
%type <atributos> comparacion
%type <atributos> constante
%type <atributos> constante_logica
%type <atributos> constante_entera
%type <atributos> identificador
%type <atributos> condicional
%type <atributos> if_exp

%start program
%left TOK_RETURN
%left TOK_ASIGNACION
%left TOK_AND TOK_OR
%left TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL TOK_MENOR TOK_MAYOR
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION
%right MENOSU TOK_NOT

%%
program: iniciar TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones post_dec funciones post_func sentencias TOK_LLAVEDERECHA {
	fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
	TS_liberar(t_simb);
	escribir_fin(yyout);
	}
;
iniciar: {
	if (!(t_simb = TS_crear()))
       return yyerror("Error al crear la tabla de simbolos\n");
	escribir_subseccion_data(yyout);
	escribir_cabecera_bss(yyout);
}
;

post_dec: {
	escribir_segmento_codigo(yyout);
	declar = FALSE;
}
;

post_func: {
	escribir_inicio_main(yyout);
	declar_f = FALSE;
}
;

declaraciones: declaracion {fprintf(out, ";R2:\t<declaraciones> ::= <declaracion>\n");}
    | declaracion declaraciones {fprintf(out, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
;
declaracion: clase identificadores TOK_PUNTOYCOMA {fprintf(out, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");

}
;
clase: clase_escalar {fprintf(out, ";R5:\t<clase> ::= <clase_escalar>\n"); cur_class = ESCALAR;}
    | clase_vector {fprintf(out, ";R7:\t<clase> ::= <clase_vector>\n"); cur_class = VECTOR;}
;
clase_escalar: tipo {fprintf(out, ";R9:\t<clase_escalar> ::= <tipo>\n");}
;
tipo: TOK_INT {fprintf(out, ";R10:\t<tipo> ::= int\n"); cur_type = ENTERO;}
    | TOK_BOOLEAN {fprintf(out, ";R11:\t<tipo> ::= boolean\n"); cur_type = BOOLEANO;}
;
clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO constante_entera TOK_CORCHETEDERECHO 
{
	fprintf(out, ";R15:\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");
	if($4.valor > MAX_V || $4.valor <= 0){
		return yyerror("Vector fuera de límites (1, 64)");
	}
	tam = $4.valor;
}
;
identificadores: identificador {fprintf(out, ";R18:\t<identificadores> ::= <identificador>\n");}
    | identificador TOK_COMA identificadores {fprintf(out, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
;
funciones: funcion funciones {fprintf(out, ";R:20:\t<funciones> ::= <funcion> <funciones>\n");
}
    | {fprintf(out, ";R21:\t<funciones> ::= \n");}
;
funcion: TOK_FUNCTION tipo identificador TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion sentencias TOK_LLAVEDERECHA {fprintf(out, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n"); TS_cerrarAmbito(t_simb);}
;
parametros_funcion: parametro_funcion resto_parametros_funcion {fprintf(out, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
	| {fprintf(out, ";R24:\t<parametros_funcion> ::=\n");}
;
resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion {fprintf(out, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
	| {fprintf(out, ";R26:\t<resto_parametros_funcion> ::=\n");}
;
parametro_funcion: tipo identificador {fprintf(out, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
;
declaraciones_funcion: declaraciones {fprintf(out, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
	| {fprintf(out, ";R29:\t<declaraciones_funcion> ::=\n");}
;
sentencias: sentencia {fprintf(out, ";R30:\t<sentencias> ::= <sentencia>\n");}
	| sentencia sentencias{fprintf(out, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
;
sentencia: sentencia_simple TOK_PUNTOYCOMA {fprintf(out, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
	| bloque {fprintf(out, ";R33:\t<sentencia_simple> ::= <bloque>\n");}
;
sentencia_simple: asignacion {fprintf(out, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
	| lectura {fprintf(out, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
	| escritura {fprintf(out, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
	| retorno_funcion {fprintf(out, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
;
bloque: condicional {fprintf(out, ";R40:\t<bloque> ::= <condicional>\n");}
	| bucle {fprintf(out, ";R41:\t<bloque> ::= <bucle>\n");}
;
asignacion: identificador TOK_ASIGNACION exp 
{
	fprintf(out, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
	if($1.tipo != $3.tipo){
		return yyerror("Asignacion no permitida\n");
	}
	asignar(yyout, $1.lexema, $3.es_var);
}
	| elemento_vector TOK_ASIGNACION exp {fprintf(out, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
;
elemento_vector: identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {fprintf(out, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
;
condicional: TOK_IF TOK_PARENTESISIZQUIERDO if_exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA 
{
	fprintf(out, ";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
	ifthen_fin(yyout, $3.valor);
}
	| TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA 
	{
		fprintf(out, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
	}
;
if_exp: comparacion 
{
	if($1.tipo != BOOLEANO) {
		return yyerror("Condicional sin booleano");
	}
	$$.valor = etiqueta;
	etiqueta++;
	ifthen_inicio(yyout, $1.es_var, $$.valor);
}
;
bucle: TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA {fprintf(out, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
;
lectura: TOK_SCANF identificador 
{
	fprintf(out, ";R54:\t<lectura> ::= scanf <identificador>\n");
	leer(yyout, $2.lexema, $2.tipo);
}
;
escritura: TOK_PRINTF exp 
{
	fprintf(out, ";R56:\t<escritura> ::= printf <exp>\n");
	escribir(yyout, $2.es_var, $2.tipo);
}
;
retorno_funcion: TOK_RETURN exp 
{
	fprintf(out, ";R61:\t<retorno_funcion> ::= return <exp>\n");
	retornarFuncion(yyout, $2.es_var);
}
;
exp: exp TOK_MAS exp 
{
	fprintf(out, ";R72:\t<exp> ::= <exp> + <exp>\n");
	if($1.tipo != ENTERO && $3.tipo != ENTERO){
		return yyerror("Operacion aritmetica con booleanos\n");
	}

	sumar(yyout, $1.es_var, $3.es_var);
	$$.tipo = ENTERO;
	$$.es_var = FALSE;
}
	| exp TOK_MENOS exp 
	{
		fprintf(out, ";R73:\t<exp> ::= <exp> - <exp>\n");
		if($1.tipo != ENTERO && $3.tipo != ENTERO){
			return yyerror("Operacion aritmetica con 	booleanos\n");
		}

		restar(yyout, $1.es_var, $3.es_var);
		$$.tipo = ENTERO;
		$$.es_var = FALSE;
	}
	| exp TOK_DIVISION exp 
	{
		fprintf(out, ";R74:\t<exp> ::= <exp> / <exp>\n");
		if($1.tipo != ENTERO && $3.tipo != ENTERO){
			return yyerror("Operacion aritmetica con 	booleanos\n");
		}
	
		dividir(yyout, $1.es_var, $3.es_var);
		$$.tipo = ENTERO;
		$$.es_var = FALSE;
	}
	| exp TOK_ASTERISCO exp 
	{
		fprintf(out, ";R75:\t<exp> ::= <exp> * <exp>\n");
		if($1.tipo != ENTERO && $3.tipo != ENTERO){
			return yyerror("Operacion aritmetica con 	booleanos\n");
		}
	
		multiplicar(yyout, $1.es_var, $3.es_var);
		$$.tipo = ENTERO;
		$$.es_var = FALSE;
	}
	| TOK_MENOS exp 
	{
		fprintf(out, ";R76:\t<exp> ::= - <exp>\n");
		if($2.tipo != ENTERO){
			return yyerror("Operacion aritmetica con 	booleanos\n");
		}
	
		cambiar_signo(yyout, $2.es_var);
		$$.tipo = ENTERO;
	}
	| exp TOK_AND exp 
	{
		fprintf(out, ";R77:\t<exp> ::= <exp> && <exp>\n");
		if($1.tipo != BOOLEANO && $3.tipo != BOOLEANO){
			return yyerror("Operacion logica con 	enteros\n");
		}
	
		y(yyout, $1.es_var, $3.es_var);
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| exp TOK_OR exp 
	{
		fprintf(out, ";R78:\t<exp> ::= <exp> || <exp>\n");
		if($1.tipo != BOOLEANO && $3.tipo != BOOLEANO){
			return yyerror("Operacion logica con 	enteros\n");
		}
	
		o(yyout, $1.es_var, $3.es_var);
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| TOK_NOT exp %prec MENOSU 
	{
		fprintf(out, ";R79:\t<exp> ::= ! <exp>\n");
		if($2.tipo != BOOLEANO){
			return yyerror("Operacion logica con 	enteros\n");
		}
	
		no(yyout, $2.es_var, 1);
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| identificador 
	{
		fprintf(out, ";R80:\t<exp> ::= <identificador>\n");
		$$.tipo = $1.tipo;
		$$.es_var = TRUE;
		escribir_operando(yyout, $1.lexema, TRUE);
	}
	| constante 
	{
		fprintf(out, ";R81:\t<exp> ::= <constante>\n");
		$$.tipo = $1.tipo;
		$$.es_var = FALSE;
		escribir_operando(yyout, $1.lexema, FALSE);
	}
	| TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {fprintf(out, ";R82:\t<exp> ::= ( <exp> )\n");$$.tipo = $2.tipo; $$.es_var = $2.es_var;}
	| TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO 
	{
		fprintf(out, ";R83:\t<exp> ::= ( <comparacion> )\n");
		$$.tipo = BOOLEANO;
		$2.es_var = FALSE;
	}
	| elemento_vector {fprintf(out, ";R85:\t<exp> ::= <elemento_vector>\n");}
	| identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {fprintf(out, ";R88:\t<exp> ::= <identificaor> ( <lista_expresiones> )\n");}
;
lista_expresiones: exp resto_lista_expresiones {fprintf(out, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
	| {fprintf(out, ";R90:\t<lista_expresiones> ::=\n");}
;
resto_lista_expresiones: TOK_COMA exp resto_lista_expresiones {fprintf(out, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
	| {fprintf(out, ";R92:\t<resto_lista_expresiones> ::= \n");}
;
comparacion: exp TOK_IGUAL exp {
	fprintf(out, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
	if($1.tipo != ENTERO || $3.tipo != ENTERO){
		return yyerror("No se puede comparar  con booleanos\n");
	}
	igual(yyout, $1.es_var, $3.es_var, etiqueta);
	etiqueta++;
	$$.tipo = BOOLEANO;
	$$.es_var = FALSE;
	}
	| exp TOK_DISTINTO exp {
		fprintf(out, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
		if($1.tipo != ENTERO || $3.tipo != ENTERO){
			return yyerror("No se puede comparar  con booleanos\n");
		}
		distinto(yyout, $1.es_var, $3.es_var, etiqueta);
		etiqueta++;
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
		}
	| exp TOK_MENORIGUAL exp 
	{
		fprintf(out, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
		if($1.tipo != ENTERO || $3.tipo != ENTERO){
			return yyerror("No se puede comparar  con booleanos\n");
		}
		menor_igual(yyout, $1.es_var, $3.es_var, etiqueta);
		etiqueta++;
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| exp TOK_MAYORIGUAL exp {
		fprintf(out, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
		if($1.tipo != ENTERO || $3.tipo != ENTERO){
			return yyerror("No se puede comparar  con booleanos\n");
		}
		mayor_igual(yyout, $1.es_var, $3.es_var, etiqueta);
		etiqueta++;
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| exp TOK_MENOR exp {
		fprintf(out, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
		if($1.tipo != ENTERO || $3.tipo != ENTERO){
			return yyerror("No se puede comparar  con booleanos\n");
		}
		menor(yyout, $1.es_var, $3.es_var, etiqueta);
		etiqueta++;
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
	| exp TOK_MAYOR exp {
		fprintf(out, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
		if($1.tipo != ENTERO || $3.tipo != ENTERO){
			return yyerror("No se puede comparar  con booleanos\n");
		}
		mayor(yyout, $1.es_var, $3.es_var, etiqueta);
		etiqueta++;
		$$.tipo = BOOLEANO;
		$$.es_var = FALSE;
	}
;
constante: constante_logica {fprintf(out, ";R99:\t<constante> ::= <constante_logica>\n");$$.valor = $1.valor; $$.tipo = BOOLEANO; $$.es_var = FALSE;}
	| constante_entera {fprintf(out, ";R100:\t<constante> ::= <constante_entera>\n");$$.valor = $1.valor; $$.tipo = ENTERO;$$.es_var = FALSE;}
;
constante_logica: TOK_TRUE 
	{
		fprintf(out, ";R102:\t<constante_logica> ::= true\n");
		$$.valor = TRUE;
		strcpy($$.lexema, "true");
	}
	| TOK_FALSE 
	{
		fprintf(out, ";R103:\t<constante_logica> ::= false\n");
		$$.valor = FALSE;
		strcpy($$.lexema, "false");
		}
;
constante_entera: TOK_CONSTANTE_ENTERA 
{
	fprintf(out, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
	$$.valor = $1.valor;
	strcpy($$.lexema, $1.lexema);
}
;
identificador: TOK_IDENTIFICADOR 
{
	fprintf(out, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");

	if(declar == TRUE){
		if(TS_insertarElemento(t_simb, $1.lexema, 0, cur_cat, 	cur_type, cur_class) == ERR){
			return yyerror("Error al insertar un simbolo variable global");
		}

		declarar_variable(yyout, $1.lexema, cur_type, tam);
		tam = 1;
	}
	else if (declar_f == TRUE && cur_cat == VARIABLE){
		if(TS_insertarElemento(t_simb, $1.lexema, 0, cur_cat, cur_type, cur_class) == ERR){
			return yyerror("Error al insertar un simbolo variable local\n");
		}

		pos_local++;
	}
	else if (declar_f == TRUE && cur_cat == FUNCION){
		if(TS_abrirAmbito(t_simb, $1.lexema, -1) == ERR){
			return yyerror("Error al insertar un simbolo funcion");
		}

	}
	else if (declar_f == TRUE && cur_cat == PARAMETRO){
		if(TS_insertarElemento(t_simb, $1.lexema, 0, cur_cat, cur_type, cur_class) == ERR){
			return yyerror("Error al insertar un simbolo parametro\n");
		}

		pos_param++;
	}
	else{
		elem = TS_buscarElemento(t_simb, $1.lexema);
		if(elem == NULL)
			return yyerror("Elemento no declarado\n");
		$$.tipo = elem->tipo;
		$$.es_var = TRUE;
	}
	
}
;
%%