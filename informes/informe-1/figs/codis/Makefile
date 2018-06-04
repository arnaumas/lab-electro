OPT=-g -Wall -pedantic
EXECS=condensador fils lliure

all : $(EXECS)

# Executables
condensador : simulacio-condensador.o
	gcc -o condensador simulacio-condensador.o -lm

fils : simulacio-fils.o
	gcc -o fils simulacio-fils.o -lm

lliure : simulacio-lliure.o
	gcc -o lliure simulacio-lliure.o -lm

# Objectes
simulacio-condensador.o : simulacio-condensador.c
	gcc -c $(OPT) simulacio-condensador.c 

simulacio-fils.o : simulacio-fils.c
	gcc -c $(OPT) simulacio-fils.c 

simulacio-lliure.o : simulacio-lliure.c
	gcc -c $(OPT) simulacio-lliure.c 

# Neteja
clean :
	rm -f *.o
	rm -rf *.dSYM

realclean : clean
	rm -f $(EXECS)
