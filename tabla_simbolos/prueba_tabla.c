/* PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaSimbolos.h"

int wordcount(char *str) {
	int i, n = 1;
	for(i = 0; str[i] != '\0'; i++) if(str[i] == ' ') n++;
	return n;
}

int main(int argc, char **argv) {
    FILE *f_input, *f_output;
    TABLA_SIMBOLOS *tabla;
    int n;
	INFO_SIMBOLO *p_info = NULL;
    char *line = NULL, id[128];
	size_t len;

    if (argc != 3) {
        printf("Introduce ./prueba_tabla <f_input> <f_output>\n");
        return -1;
    }
    if (!(f_input = fopen(argv[1], "r"))) {
        printf("Error al abrir el fichero %s\n", argv[1]);
        return -1;
    }
    if (!(f_output = fopen(argv[2], "w"))) {
        printf("Error al abrir el fichero %s\n", argv[2]);
        fclose(f_input);
        return -1;
    }
    if (!(tabla = TS_crear())) {
        printf("Error al crear la tabla de simbolos\n");
        fclose(f_output);
        fclose(f_input);
        return -1;
    }

	while (getline(&line, &len, f_input) != -1) {
		if (line[0] == '#'); /*Skips comments in input files*/
		else if (wordcount(line) == 1) {
			sscanf(line, "%s", id);
            p_info = TS_buscarElemento(tabla, id);
			if (!p_info) fprintf(f_output, "%s -1\n", id);
            else fprintf(f_output, "%s %d\n", id, p_info->adicional1);
		} else {
            sscanf(line, "%s %d", id, &n);
            if (n >= 0) {
                if (TS_insertarElemento(tabla, id, n) == ERR) fprintf(f_output, "-1 %s\n", id);
                else fprintf(f_output, "%s\n", id);
            } else {
                if (strcmp(id, "cierre") == 0 && n == -999) {
                    TS_cerrarAmbito(tabla);
                    fprintf(f_output, "cierre\n");
                } else {
					if (TS_abrirAmbito(tabla, id, n) == ERR) fprintf(f_output, "-1 %s\n", id);
					else fprintf(f_output, "%s\n", id);
                }
            }
        }
    }

    TS_liberar(tabla);
    fclose(f_output);
    fclose(f_input);
    if (line) free(line);
    return 0;
}
