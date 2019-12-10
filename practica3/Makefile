all: alfa

bison:
	bison -dyv alfa.y

lex: 
	flex alfa.l

alfa: bison lex
	gcc -c pruebaSint.c y.tab.c lex.yy.c
	gcc -o alfa *.o

clean:
	rm alfa alfa.tab.c lex.yy.c alfa.tab.h