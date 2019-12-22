/* PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablaHash.h"

INFO_SIMBOLO *crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2) {
	INFO_SIMBOLO *p_info = NULL;
	if(!lexema) return NULL;
	p_info = (INFO_SIMBOLO *) malloc(sizeof(INFO_SIMBOLO));
	if (!p_info) return NULL;
	p_info->lexema = strdup(lexema);
	p_info->categoria = categ;
	p_info->tipo = tipo;
	p_info->clase = clase;
	p_info->adicional1 = adic1;
	p_info->adicional2 = adic2;
	return p_info;
}

void liberar_info_simbolo(INFO_SIMBOLO *p_info) {
	if (!p_info) return;
    if (p_info->lexema) free(p_info->lexema);
    free(p_info);
}

NODO_HASH *crear_nodo(INFO_SIMBOLO *p_info) {
    NODO_HASH *nodo = NULL;
	if (!p_info) return NULL;
	nodo = (NODO_HASH *) malloc(sizeof(NODO_HASH));
	if(!nodo) return NULL;
    nodo->info = p_info;
    nodo->siguiente = NULL;
    return nodo;
}

void liberar_nodo(NODO_HASH *nodo) {
    if (!nodo) return;
    liberar_info_simbolo(nodo->info);
    free(nodo);
}

TABLA_HASH *crear_tabla(int tam) {
    TABLA_HASH *p_tabla = NULL;
	p_tabla = (TABLA_HASH *) malloc(sizeof(TABLA_HASH));
	if (!p_tabla) return NULL;
    p_tabla->tabla = (NODO_HASH **) calloc(tam, sizeof(NODO_HASH *));
	if (!p_tabla->tabla) {
		free(p_tabla);
		return NULL;
	}
    p_tabla->tam = tam;
    return p_tabla;
}

void liberar_tabla(TABLA_HASH *p_tabla) {
    int i;
    NODO_HASH *nodo = NULL, *siguiente = NULL;
	if (!p_tabla) return;
    if (p_tabla->tabla) {
        for (i = 0; i < p_tabla->tam; i++) {
            nodo = p_tabla->tabla[i];
            while (nodo) {
                siguiente = nodo->siguiente;
                liberar_nodo(nodo);
                nodo = siguiente;
            }
        }
        free(p_tabla->tabla);
    }
    free(p_tabla);
}

unsigned long hash(const char *str) {
    unsigned long h = HASH_INI;
    unsigned char *uchar = NULL;
	if (!str) return ERR;
	uchar = (unsigned char *) str;
    while (*uchar != '\0') {
		h = h * HASH_FACTOR + *uchar;
		uchar++;
	}
    return h;
}

INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *p_tabla, const char *lexema) {
    int index;
    NODO_HASH *nodo = NULL;

    index = hash(lexema) % p_tabla->tam;
    nodo = p_tabla->tabla[index];
    while (nodo && (!nodo->info || strcmp(nodo->info->lexema, lexema))) {
        nodo = nodo->siguiente;
	}
	if (!nodo) return NULL;
	return nodo->info;
}

STATUS insertar_simbolo(TABLA_HASH *p_tabla, const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2) {
    int index;
    INFO_SIMBOLO *p_info = NULL;
    NODO_HASH *nodo = NULL;

    if (!p_tabla || !lexema || buscar_simbolo(p_tabla, lexema)) return ERR;
    index = hash(lexema) % p_tabla->tam;
    p_info = crear_info_simbolo(lexema, categ, tipo, clase, adic1, adic2);
    nodo = crear_nodo(p_info);
    if (!nodo) {
        liberar_info_simbolo(p_info);
        return ERR;
    }
    nodo->siguiente = p_tabla->tabla[index];
    p_tabla->tabla[index] = nodo;
    return OK;
}

void borrar_simbolo(TABLA_HASH *p_tabla, const char *lexema) {
    int index;
    NODO_HASH *nodo = NULL, *prev = NULL;

	if (!p_tabla || !lexema) return;
    index = hash(lexema) % p_tabla->tam;
    nodo = p_tabla->tabla[index];
    while (nodo && (!nodo->info || strcmp(nodo->info->lexema, lexema))) {
        prev = nodo;
        nodo = nodo->siguiente;
    }
    if (!nodo) return;
	if (!prev) p_tabla->tabla[index] = nodo->siguiente;
    else prev->siguiente = nodo->siguiente;
    liberar_nodo(nodo);
    return;
}
