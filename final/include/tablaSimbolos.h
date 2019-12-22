/* PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo */
#ifndef TABLASIMB_H
#define TABLASIMB_H

#include "tablaHash.h"

/**************** CONSTANTES *************************************************/

#define TH_SIZE 128  /* tamano tablas hash de la tabla de simbolos */
#define MAX_ID 100

/**************** DECLARACIONES DE TIPOS *************************************/

/* Tabla de simbolos */
typedef struct {
	TABLA_HASH *contexto_global;
    TABLA_HASH *contexto_local;
} TABLA_SIMBOLOS;

/* Atributos */
typedef struct{
	char lexema[MAX_ID + 1];
	int tipo;
	int valor;
    int es_var;
} tipo_atributos;

/**************** FUNCIONES **************************************************/

TABLA_SIMBOLOS *TS_crear();
void TS_liberar(TABLA_SIMBOLOS *p_tabla);
STATUS TS_insertarElemento(TABLA_SIMBOLOS *p_tabla, const char *id, int n, CATEGORIA categoria, TIPO tipo, CLASE clase);
INFO_SIMBOLO* TS_buscarElemento(TABLA_SIMBOLOS *p_tabla, const char *id);
STATUS TS_abrirAmbito(TABLA_SIMBOLOS *p_tabla, const char *id, int n);
STATUS TS_cerrarAmbito(TABLA_SIMBOLOS *p_tabla);

#endif
