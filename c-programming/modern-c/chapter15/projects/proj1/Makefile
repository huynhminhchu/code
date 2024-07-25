proj1: proj1.o word.o line.o
	gcc -o proj1 proj1.o word.o line.o

proj1.o: proj1.c word.h line.h
	gcc -c proj1.c

word.o: word.c word.h
	gcc -c word.c

line.o: line.c line.h
	gcc -c line.c