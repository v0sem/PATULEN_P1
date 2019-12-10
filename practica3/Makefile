all: alfa

bison:
	bison -d -y -v alfa.y

lex: 
	flex alfa.l

alfa: bison lex
	gcc -o alfa pruebaSint.c y.tab.c lex.yy.c

clean:
	rm alfa alfa.tab.c lex.yy.c alfa.tab.h