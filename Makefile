

SRCS := $(wildcard *.cc *.hh)
SRCS := $(filter-out parser.tab.cc, $(SRCS))
SRCS := $(filter-out lex.yy.c, $(SRCS))
OBJS := $(SRCS:.cc=.o)



compiler: lex.yy.c parser.tab.o $(OBJS)
		g++ -g -w -ocompiler parser.tab.o lex.yy.c $(OBJS) -std=c++17
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++17
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.l parser.tab.cc
		flex lexer.l
tree: 
		 dot -Tpdf tree.dot -otree.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh tree.dot tree.pdf
		rm -R compiler.dSYM

sourceFiels: *.c -o 