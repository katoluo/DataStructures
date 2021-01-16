vpath %.h ../Status:../LinkedStack
vpath %.c .:../Status:../LinkedStack

target: main.o LinkedStack.o Status.o
	gcc -o target main.o LinkedStack.o Status.o

main.o: main.c LinkedStack.h Status.h
	gcc -c ./main.c

LinkedStack.o: LinkedStack.c LinkedStack.h Status.h
	gcc -c ../LinkedStack/LinkedStack.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm target *.o
