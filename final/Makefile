IDIR=include
ODIR=${CURDIR}
SDIR=src
CC=gcc
CFLAGS= -g
prg=main

_FILES=tablaHash tablaSimbolos generacion y.tab
DEPS = $(patsubst %,$(IDIR)/%.h,$(_FILES))
OBJ = $(patsubst %,$(ODIR)/%.o,$(_FILES)) $(ODIR)/lex.yy.o

all: bisep alfa clear instr run

instr:
	cat leeme.txt

bisep:
	bison -dyv $(SDIR)/alfa.y
	lex $(SDIR)/alfa.l
	mv *.c $(SDIR)
	mv *.h $(IDIR)
	
alfa: $(OBJ) $(ODIR)/main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run:
	sh run.sh

.PHONY: clean

clean:
	-rm $(IDIR)/y.tab.h $(SDIR)/lex.yy.c $(SDIR)/y.tab.c y.output alfa sintactico.txt
	-rm compiled/* output/*

clear:
	-rm *.o
