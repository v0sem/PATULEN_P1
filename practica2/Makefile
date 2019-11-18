CC = gcc
CFLAGS = -g

all: lex.yy.c
	@echo "--> Compiling $^ and main.c"
	$(CC) $(CFLAGS) -o pruebaMorfo lex.yy.c main.c
lex.yy.c: alfa.l
	@echo "--> Compiling $^"
	flex alfa.l

test: test1 test2 test3

test1:
	@echo "Prueba 1:"
	./pruebaMorfo entrada1.txt misalida1.txt
	diff -bB salida1.txt misalida1.txt
test2:
	@echo "Prueba 2: DA ERROR"
	./pruebaMorfo entrada2.txt misalida2.txt
test3:
	@echo "Prueba 3: DA ERROR"
	./pruebaMorfo entrada3.txt misalida3.txt
	