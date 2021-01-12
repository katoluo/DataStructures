vpath %.h LinkedList:../Status
vpath %.c LinkedList:../Status

target: main.o LinkedList.o Status.o
	gcc -o target main.o LinkedList.o Status.o

main.o: main.c LinkedList.h Status.h
	gcc -c main.c

LinkedList.o: LinkedList.c LinkedList.h Status.h
	gcc -c LinkedList.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm target *.o
