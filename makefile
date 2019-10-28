CC = gcc
CFLAGS = -Wall
EXE = ej1 ej2 ej3 ej4 ej5 ej6 ej7

.PHONY: all clean

all: $(EXE)

# genera EXE enlazados con generacion.o
$(EXE): % : %.o generacion.o
	$(CC) $(CFLAGS) -o generador_$@ $@.o generacion.o
	rm $<
	./generador_$@ asm/$@.asm
	rm generador_git$@
	nasm -g -o asm/$@.o -f elf32 asm/$@.asm
	gcc -m32 -o $@ asm/$@.o lib/alfalib.o
	rm asm/$<
	@echo "#---------------------------"

generacion.o: generacion.c generacion.h
	gcc -c generacion.c

clean:
	rm -f *.o $(EXE)
