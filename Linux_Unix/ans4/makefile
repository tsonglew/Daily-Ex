.PHONY:clean

prog: main.o p1.o p2.o
	gcc -o prog main.o p1.o p2.o

main.o: main.c p1.h p2.h
	gcc -c main.c

p1.o: p1.c p1.h p2.h
	gcc -c p1.c

p2.o: p1.h p2.c p2.h
	gcc -c p2.c

clean:
	rm -f *.o
