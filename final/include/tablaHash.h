/* PAUTLEN 1361 (2019). PAREJA 3: David Palomo Marcos, Pablo Sanchez Redondo */
#ifndef TABLAHASH_H
#define TABLAHASH_H

/**************** CONSTANTES *************************************************/

#define POS_INI_PARAMS 0        /* posicion de inicio de parametros de funcion (empiezan a contar en 0) */
#define POS_INI_VARS_LOCALES 1  /* posicion de inicio de variables locales de funcion (empiezan a contar en 1) */
#define HASH_INI 5381
#define HASH_FACTOR 33


/**************** DECLARACIONES DE TIPOS *************************************/

/* Retorno de funcion error/ok */
typedef enum { ERR = 0, OK = 1 } STATUS;

/* Categoria de un simbolo: variable, parametro de funcion o funcion */
typedef enum { VARIABLE, PARAMETRO, FUNCION } CATEGORIA;

/* Tipo de un dato: solo se trabajara con enteros y booleanos */
typedef enum { ENTERO, BOOLEANO } TIPO;

/* Clase de un simbolo: pueden ser variables atomicas (escalares) o listas/arrays (vectores) */
typedef enum { ESCALAR, VECTOR } CLASE;

/* Informacion de un simbolo */
typedef struct {
    char *lexema;        /* identificador */
    CATEGORIA categoria; /* categoria */
    TIPO tipo;           /* tipo */
    CLASE clase;         /* clase */
    int adicional1;      /* valor si escalar, longitud si vector, numero de parametros si funcion */
    int adicional2;      /* posicion en llamada a funcion si parametro, posicion de declaracion si variable local de funcion, numero de variables locales si funcion */
} INFO_SIMBOLO;

/* Nodo de la tabla hash */
typedef struct nodo_hash {
    INFO_SIMBOLO *info;          /* informacion del simbolo */
    struct nodo_hash *siguiente; /* puntero al siguiente nodo (encadenamiento si colision en misma celda) */
} NODO_HASH;

/* Tabla hash */
typedef struct {
    int tam;            /* tamano de la tabla hash */
    NODO_HASH **tabla;  /* tabla en si (array de tam punteros a nodo) */
} TABLA_HASH;


/**************** FUNCIONES **************************************************/

INFO_SIMBOLO *crear_info_simbolo(const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2);
void liberar_info_simbolo(INFO_SIMBOLO *is);
NODO_HASH *crear_nodo(INFO_SIMBOLO *is);
void liberar_nodo(NODO_HASH *nh);
TABLA_HASH *crear_tabla(int tam);
void liberar_tabla(TABLA_HASH *th);
unsigned long hash(const char *str);
INFO_SIMBOLO *buscar_simbolo(const TABLA_HASH *th, const char *lexema);
STATUS insertar_simbolo(TABLA_HASH *th, const char *lexema, CATEGORIA categ, TIPO tipo, CLASE clase, int adic1, int adic2);
void borrar_simbolo(TABLA_HASH *th, const char *lexema);

#endif
