proj4: proj4.o stack.o
	gcc -o proj4 proj4.o stack.o

proj4.o: proj4.c stack.h
	gcc -c proj4.c

stack.o: stack.c stack.h
	gcc -c stack.c