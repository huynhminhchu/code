# justify: justify.o word.o line.o
# 	gcc -o justify justify.o word.o line.o

# justify.o: justify.c word.h line.h
# 	gcc -c justify.c

# word.o: word.c word.h
# 	gcc -c word.c

# line.o: line.c line.h
# 	gcc -c line.c

demo: main.o f1.o f2.o
	gcc -o demo main.o f1.o f2.o

main.o: main.c f1.h
	gcc -c main.c

f1.o: f1.c f1.h f2.h
	gcc -c f1.c

f2.o: f2.c f2.h f1.h
	gcc -c f2.c
