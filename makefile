CC = gcc
CFLAGS = -Wall
EJS = ej1 ej2

all: $(EJS)

clean:
	rm -f *.o $(EJS)

# genera EJS enlazados con generacion.o
$(EJS): % : %.o generacion.o
	$(CC) $(CFLAGS) -o generador_$@ $@.o generacion.o
	rm $<
	./generador_$@ asm/$@.asm
	rm generador_$@
	nasm -g -o asm/$@.o -f elf32 asm/$@.asm
	gcc -m32 -o $@ asm/$@.o lib/alfalib.o
	rm asm/$<
	@echo "#---------------------------"

generacion.o: generacion.c generacion.h
	gcc -c generacion.c
