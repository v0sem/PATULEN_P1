########################################################
CC=gcc
CFLAGS= -g -Wall
EJS = prueba_tabla
########################################################
OBJECTS = prueba_tabla.o tablaSimbolos.o tablaHash.o
########################################################

all: $(EJS) clear

prueba_tabla: $(OBJECTS)
	$(CC) $(CFLAGS) -o prueba_tabla $(OBJECTS)

prueba_tabla.o: prueba_tabla.c tablaSimbolos.h tablaHash.h
	$(CC) $(CFLAGS) -c prueba_tabla.c

tablaHash.o: tablaHash.c tablaHash.h
	$(CC) $(CFLAGS) -c tablaHash.c

tablaSimbolos.o: tablaSimbolos.c tablaSimbolos.h tablaHash.h
	$(CC) $(CFLAGS) -c tablaSimbolos.c

clean:
	rm -rf *.o $(EJS)

clear:
	rm -rf *.o

runv:
	@echo ">>>>>>Running prueba_tabla with valgrind"
	valgrind --leak-check=full ./prueba_tabla tests/in1.txt /dev/null
