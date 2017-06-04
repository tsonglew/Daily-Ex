.PHONY: clean

prog: main.o p1.o p2.o
	gcc -o $@ $^

main.o: main.c p1.h p2.h
	gcc -c -o $@ main.c

p1.o: p1.c p1.h p2.h
	gcc -c -o $@ p1.c

p2.o: p2.c p1.h p2.h
	gcc -c -o $@ p2.c

clean:
	rm -rf ./*.o
