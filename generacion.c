#include "generacion.h"
#include <stdio.h>
#include <stdlib.h>

/*
* AUX FUNCTIONS
*/

void pila_opera(FILE *fpasm, int es_variable_1, int es_variable_2){
	fprintf(fpasm, "\tpop dword ebx\n");
	fprintf(fpasm, "\tpop dword eax\n");

	if (es_variable_1 == 1) {
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	if (es_variable_2 == 1) {
		fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
	}
}

void es_variable_fun(FILE *fpasm, int es_variable){
	fprintf(fpasm, "\tpop dword eax\n");

	if (es_variable == 1) {
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}
}

/**************************************************************************/

void escribir_cabecera_bss(FILE *fpasm) {

	fprintf(fpasm, "segment .bss\n\t__esp resd 1\n");

}

void escribir_subseccion_data(FILE *fpasm) {

	fprintf(fpasm, "segment .data\n");
	fprintf(fpasm, "\terr_div0 db \"Error al dividir entre 0\",0\n");
	fprintf(fpasm, "\terr_ior db \"Indice de vector fuera de rango\", 0\n");

}

void declarar_variable(FILE *fpasm, char *nombre, int tipo, int tamano) {

	if(tipo == ENTERO)
		fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);

	if(tipo == BOOLEANO)
		fprintf(fpasm, "\t_%s resb %d\n", nombre, tamano);

}

void escribir_segmento_codigo(FILE *fpasm) {
	fprintf(fpasm, "segment .text\n\tglobal main\n\textern scan_int, "
								 "print_int, scan_float, print_float, scan_boolean, "
								 "print_boolean, print_endofline, print_blank, "
								 "print_string, alfa_malloc, alfa_free, ld_float\n");
}

void escribir_inicio_main(FILE *fpasm) {
	fprintf(fpasm, "main:\n\tmov dword [__esp], esp\n");
}

void escribir_fin(FILE *fpasm) {
	/* Sentencia necesaria si no ha habido errores en tiempo de ejecucion */
	fprintf(fpasm, "\tjmp near fin\n");

	/* Codigo necesario para gestionar el error de division entre 0 */
	fprintf(fpasm, "fin_DIV0:\n");
	fprintf(fpasm, "\tpush dword err_div0\n");
	fprintf(fpasm, "\tcall print_string\n");
	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
	fprintf(fpasm, "\tjmp near fin\n");

	/* Código necesario para gestionar el error de indice de vector fuera de rango
	 */
	fprintf(fpasm, "fin_IOR:\n");
	fprintf(fpasm, "\tpush dword err_ior\n");
	fprintf(fpasm, "\tcall print_string\n");
	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
	fprintf(fpasm, "\tjmp near fin\n");

	/* Etiqueta de fin */
	fprintf(fpasm, "fin:\n");
	fprintf(fpasm, "\tmov esp, [__esp]\n");
	fprintf(fpasm, "\tret\n");
}

void escribir_operando(FILE *fpasm, char *nombre, int es_variable) {
	if (es_variable == 1) {
		fprintf(fpasm, "\tmov eax, _%s\n", nombre);
	} else {
		fprintf(fpasm, "\tmov eax, %s\n", nombre);
	}
	fprintf(fpasm, "\tpush dword eax\n");
}

void asignar(FILE *fpasm, char *nombre, int es_variable) {
	es_variable_fun(fpasm, es_variable);
	fprintf(fpasm, "\tmov dword [_%s], eax\n", nombre);
}

void sumar(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tadd eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void restar(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tsub eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void multiplicar(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\timul ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void dividir(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tmov dword edx, 0\n");
	fprintf(fpasm, "\tcmp ebx, edx\n");
	fprintf(fpasm, "\tje near fin_DIV0\n");

	fprintf(fpasm, "\tidiv ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void o(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tor eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}
void y(FILE *fpasm, int es_variable_1, int es_variable_2) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tand eax, ebx\n");
	fprintf(fpasm, "\tpush dword eax\n");
}

void cambiar_signo(FILE *fpasm, int es_variable) {
	es_variable_fun(fpasm, es_variable);

	fprintf(fpasm, "\tneg eax\n");
	fprintf(fpasm, "\tpush dword eax\n");
}

void no(FILE *fpasm, int es_variable, int cuantos_no) {

	// TODO COMPRUEBA
	es_variable_fun(fpasm, es_variable);

	fprintf(fpasm, "\tmov dword ecx, 0\n");
	fprintf(fpasm, "\tcmp ecx, eax\n");
	fprintf(fpasm, "\tje near no%d\n", cuantos_no);

	fprintf(fpasm, "\tmov dword ecx, 0\n");
	fprintf(fpasm, "\tpush dword ecx\n");
	fprintf(fpasm, "\tjmp near next%d\n", cuantos_no);

	fprintf(fpasm, "no%d:\n", cuantos_no);
	fprintf(fpasm, "\tmov dword ecx, 1\n");
	fprintf(fpasm, "\tpush dword ecx\n");

	fprintf(fpasm, "next%d:\n", cuantos_no);
}

void igual(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {

	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjz near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void distinto(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjnz near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void menor_igual(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjle near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void mayor_igual(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjge near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void menor(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjl near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void mayor(FILE *fpasm, int es_variable_1, int es_variable_2, int etiqueta) {
	pila_opera(fpasm, es_variable_1, es_variable_2);

	fprintf(fpasm, "\tcmp eax,ebx\n");
	fprintf(fpasm, "\tjg near true%d\n", etiqueta);

	fprintf(fpasm, "\tmov dword eax, 0\n");
	fprintf(fpasm, "\tpush dword eax\n");
	fprintf(fpasm, "\tjmp near next%d\n", etiqueta);

	fprintf(fpasm, "true%d:\n", etiqueta);
	fprintf(fpasm, "\tmov dword eax,1\n");
	fprintf(fpasm, "\tpush dword eax\n");

	fprintf(fpasm, "next%d:\n", etiqueta);
}

void leer(FILE *fpasm, char *nombre, int tipo) {

	fprintf(fpasm, "\tpush dword _%s\n", nombre);

	if (tipo == ENTERO) {
		fprintf(fpasm, "\tcall scan_int\n");
	}
	if (tipo == BOOLEANO) {
		fprintf(fpasm, "\tcall scan_boolean\n");
	}

	fprintf(fpasm, "\tadd esp, 4\n");
}

void escribir(FILE *fpasm, int es_variable, int tipo) {

	if (es_variable == 1) {
		fprintf(fpasm, "\tpop dword eax\n");
		fprintf(fpasm, "\tmov dword eax, [eax]\n");
	}

	fprintf(fpasm, "\tpush dword eax\n");

	if (tipo == ENTERO) {
		fprintf(fpasm, "\tcall print_int\n");
	}

	if (tipo == BOOLEANO) {
		fprintf(fpasm, "\tcall print_boolean\n");
	}

	fprintf(fpasm, "\tadd esp, 4\n");
	fprintf(fpasm, "\tcall print_endofline\n");
}

void ifthen_inicio(FILE *fpasm, int exp_es_variable, int etiqueta) {
	es_variable_fun(fpasm, exp_es_variable);

	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near endif_simple%d\n", etiqueta);
}

void ifthenelse_inicio(FILE *fpasm, int exp_es_variable, int etiqueta) {
	es_variable_fun(fpasm, exp_es_variable);

	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near endif_simple%d\n", etiqueta);
}

void ifthen_fin(FILE *fpasm, int etiqueta) {
	fprintf(fpasm, "endif_simple%d:\n", etiqueta);
}

void ifthenelse_fin_then(FILE *fpasm, int etiqueta) {
	fprintf(fpasm, "\tjmp near endif_cplx%d\n", etiqueta);
	fprintf(fpasm, "endif_simple%d:\n", etiqueta);
}

void ifthenelse_fin(FILE *fpasm, int etiqueta) {
	fprintf(fpasm, "endif_cplx%d:\n", etiqueta);
}

void while_inicio(FILE *fpasm, int etiqueta) {
	fprintf(fpasm, "while%d:\n", etiqueta);
}

void while_exp_pila(FILE *fpasm, int exp_es_variable, int etiqueta) {
	es_variable_fun(fpasm, exp_es_variable);

	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tje near endwhile%d\n", etiqueta);
}

void while_fin(FILE *fpasm, int etiqueta) {
	fprintf(fpasm, "\tjmp near while%d\n", etiqueta);
	fprintf(fpasm, "endwhile%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE *fpasm, char *nombre_vector, int tam_max, int exp_es_direccion) {
	es_variable_fun(fpasm, exp_es_direccion);

	fprintf(fpasm, "\tcmp eax, 0\n");
	fprintf(fpasm, "\tjl near fin_IOR\n");

	fprintf(fpasm, "\tcmp eax, %d\n", tam_max - 1);
	fprintf(fpasm, "\tjg near fin_IOR\n");

	fprintf(fpasm, "\tmov dword edx, _%s\n", nombre_vector);
	fprintf(fpasm, "\tlea eax, [edx + eax*4]\n");
	fprintf(fpasm, "\tpush dword eax\n");
}

void declararFuncion(FILE *fd_asm, char *nombre_funcion, int num_var_loc) {
	fprintf(fd_asm, "%s:\n", nombre_funcion);
	fprintf(fd_asm, "\tpush dword ebp\n");
	fprintf(fd_asm, "\tmov dword ebp, esp\n");
	fprintf(fd_asm, "\tsub esp, %d\n", 4 * num_var_loc);
}

void retornarFuncion(FILE *fd_asm, int es_variable) {
	es_variable_fun(fd_asm, es_variable);

	fprintf(fd_asm, "\tmov dword esp, ebp\n");
	fprintf(fd_asm, "\tpop dword ebp\n");
	fprintf(fd_asm, "\tret\n");
}

void escribirParametro(FILE *fpasm, int pos_parametro, int num_total_parametros) {
	int aux = 0;
	aux = 4 * (1 + (num_total_parametros - pos_parametro));
	fprintf(fpasm, "\tlea eax, [ebp + %d]\n", aux);
	fprintf(fpasm, "\tpush dword eax\n");
}

void escribirVariableLocal(FILE *fpasm, int posicion_variable_local) {
	int aux = 0;
	aux = 4 * posicion_variable_local;
	fprintf(fpasm, "\tlea eax, [ebp - %d]\n", aux);
	fprintf(fpasm, "\tpush dword eax\n");
}

void asignarDestinoEnPila(FILE *fpasm, int es_variable) {
	fprintf(fpasm, "\tpop dword ebx\n"); // direccion
	es_variable_fun(fpasm, es_variable); // Valor de la cima

	fprintf(fpasm, "\tmov dword [ebx], eax\n");
}

void operandoEnPilaAArgumento(FILE *fd_asm, int es_variable) {
	if (es_variable == 1) {
		fprintf(fd_asm, "\tpop dword eax\n");
		fprintf(fd_asm, "\tmov dword eax, [eax]\n");
		fprintf(fd_asm, "\tpush dword eax\n");
	}
}

void llamarFuncion(FILE *fd_asm, char *nombre_funcion, int num_argumentos) {
	fprintf(fd_asm, "\tcall %s\n", nombre_funcion);
	fprintf(fd_asm, "\tadd esp, %d\n", 4 * num_argumentos);
	fprintf(fd_asm, "\tpush dword eax\n");
}

void limpiarPila(FILE *fd_asm, int num_argumentos) {
	fprintf(fd_asm, "\tadd esp, %d\n", 4 * num_argumentos);
}
