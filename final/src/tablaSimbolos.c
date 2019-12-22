/* PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tablaSimbolos.h"

TABLA_SIMBOLOS *TS_crear() {
    TABLA_SIMBOLOS *p_tabla = NULL;
    p_tabla = (TABLA_SIMBOLOS *) malloc(sizeof(TABLA_SIMBOLOS));
    if (!p_tabla) return NULL;
    p_tabla->contexto_global = crear_tabla(TH_SIZE);
    if (!p_tabla->contexto_global) {
        free(p_tabla);
        return NULL;
    }
    p_tabla->contexto_local = NULL;
    return p_tabla;
}

void TS_liberar(TABLA_SIMBOLOS *p_tabla) {
    if (!p_tabla) return;
    liberar_tabla(p_tabla->contexto_global);
    if (!p_tabla->contexto_local) liberar_tabla(p_tabla->contexto_local);
    free(p_tabla);
}

STATUS TS_insertarElemento(TABLA_SIMBOLOS *p_tabla, const char *id, int n, CATEGORIA categoria, TIPO tipo, CLASE clase) {
	TABLA_HASH *th_insertar = NULL;
	if (!p_tabla || !id || n < 0){
		return ERR;
	} 
	if (p_tabla->contexto_local) th_insertar = p_tabla->contexto_local;
	else th_insertar = p_tabla->contexto_global;
	return insertar_simbolo(th_insertar, id, categoria, tipo, clase, n, 0);
}

INFO_SIMBOLO* TS_buscarElemento(TABLA_SIMBOLOS *p_tabla, const char *id) {
	INFO_SIMBOLO *ret = NULL;
	if (!p_tabla || !id) return ERR;
    if (p_tabla->contexto_local) {
		ret = buscar_simbolo(p_tabla->contexto_local, id);
		if (ret) return ret;
	}
	return buscar_simbolo(p_tabla->contexto_global, id);
}

STATUS TS_abrirAmbito(TABLA_SIMBOLOS *p_tabla, const char *id, int n) {
	if (!p_tabla || !id || n >= -1) return ERR;
	if (p_tabla->contexto_local) return ERR;
	p_tabla->contexto_local = crear_tabla(TH_SIZE);
    if (!p_tabla->contexto_local) return ERR;
	if (insertar_simbolo(p_tabla->contexto_global, id, FUNCION, ENTERO, ESCALAR, n, 0) == ERR) {
		liberar_tabla(p_tabla->contexto_local);
		p_tabla->contexto_local = NULL;
		return ERR;
	}
	if (insertar_simbolo(p_tabla->contexto_local, id, FUNCION, ENTERO, ESCALAR, n, 0)  == ERR) {
		liberar_tabla(p_tabla->contexto_local);
		p_tabla->contexto_local = NULL;
		return ERR;
	}
	return OK;
}

STATUS TS_cerrarAmbito(TABLA_SIMBOLOS *p_tabla) {
	if (!p_tabla) return ERR;
	if (!p_tabla->contexto_local) return ERR;
	liberar_tabla(p_tabla->contexto_local);
	p_tabla->contexto_local = NULL;
	return OK;
}
