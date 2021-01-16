vpath %.h ./../Status
vpath %.c ./../Status

target: main.o DblStack.o Status.o
	gcc -o target main.o DblStack.o Status.o

main.o: main.c DblStack.h Status.h
	gcc -c ./main.c

DblStack.o: DblStack.c DblStack.h Status.h
	gcc -c ./DblStack.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm target *.o
