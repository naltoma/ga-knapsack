
CC			= gcc

CFLAGS			= -c -Wall
OPTION			= -DSELECTION -DCROSSOVER -DMUTATION
#ADDOPTION		= -DCHECK_POP -DSTEPBYSTEP

PROGRAMOO		= kp.exe

OBJSOO			= ga.o initialize_gene_binary.o random2.o calc_fitness.o KP.o roulette_selection.o singlepoint_crossover.o mutation_binary.o

LIBS			= -lm

$(PROGRAMOO)		: $(OBJSOO)
	$(CC) $(OBJSOO) -o $(PROGRAMOO) $(LIBS) 

ga.o	:	ga.c	parameter.h	KP.h
	$(CC) $(CFLAGS) $(OPTION) $(ADDOPTION) ga.c

initialize_gene_binary.o	:	initialize_gene_binary.c	parameter.h
	$(CC) $(CFLAGS) initialize_gene_binary.c

KP.o	:	KP.c
	$(CC) $(CFLAGS) KP.c

calc_fitness.o	:	calc_fitness.c	KP.h	parameter.h
	$(CC) $(CFLAGS) calc_fitness.c

random2.o	:	random2.c
	$(CC) $(CFLAGS) random2.c

roulette_selection.o	:	roulette_selection.c	parameter.h
	$(CC) $(CFLAGS) roulette_selection.c

singlepoint_crossover.o	:	singlepoint_crossover.c	parameter.h
	$(CC) $(CFLAGS) singlepoint_crossover.c

mutation_binary.o	:	mutation_binary.c	parameter.h
	$(CC) $(CFLAGS) mutation_binary.c

clean	:	
	rm -f *.o a.out a.out.core kp.exe kp.exe.core
