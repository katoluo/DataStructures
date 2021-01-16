vpath %.h ./../Status
vpath %.c ./../Status

LinkedQueue: main.o LinkedQueue.o Status.o
	gcc -o LinkedQueue main.o LinkedQueue.o Status.o

main.o: main.c LinkedQueue.h Status.h
	gcc -c ./main.c

LinkedQueue.o: LinkedQueue.c LinkedQueue.h Status.h
	gcc -c ./LinkedQueue.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm LinkedQueue *.o
