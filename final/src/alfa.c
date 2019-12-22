#include <stdio.h>

extern int yyparse();

FILE* out; //Fichero de sal
extern FILE* yyin;
extern FILE* yyout; //Fichero de salida sintáctica


int main(int argc, char **argv) {
  if (argc != 3) { //Comprobación del número de argumentos
    puts("Número de parámetros inválido.");
    puts("\tModo de ejecución: ./a.out <nombre del fichero alfa de entrada> <nombre del fichero nasm de salida>");
    return -1;
  }

  yyin = fopen(argv[1], "r"); //Abrir el fichero de entrada para lectura
  if (yyin == NULL) {
    puts("Error al abrir el fichero de entrada");
    return -1;
  }
  yyout = fopen(argv[2], "w"); //Abrir el fichero de salida para generación de código
  if (yyout == NULL) {
    puts("Error al crear el fichero de salida para generación de código");
    return -1;
  }
  out = fopen("sintactico.txt", "w"); //Abrir el fichero de salida sintáctica
  if (out == NULL) {
    puts("Error al crear el fichero de salida sintáctica");
    return -1;
  }

  yyparse();

  fclose(yyin); //Cerrar el fichero de entrada
  fclose(out); //Cerrar el fichero de salida
  fclose(yyout); //Cerrar el fichero de salida
  return 0;
}