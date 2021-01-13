vpath %.h ..

vpath %.c .:..

target: main.o LinkedList.o
	gcc -o target main.o LinkedList.o

main.o: main.c LinkedList.h Status.h
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h Status.h
	gcc -c ../LinkedList.c

.PHONY: clean

clean:
	rm target *.o
