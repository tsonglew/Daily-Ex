# script makefile
OBJS=main.o app.o mod.o lib.o

appexam: $(OBJS)
	gcc -o appexam $(OBJS)

main.o: main.c app.h
	gcc -c main.c

app.o: app.c app.h
	gcc -c app.c

mod.o: mod.c
	gcc -c mod.c

lib.o: lib.c lib.h
	gcc -c lib.c

clean:
	rm -f *.o
