vpath %.h ../Status:../LinkedStack

vpath %.c .:../LinkedStack

target: main.o LinkedStack.o
	gcc -o target main.o LinkedStack.o

main.o: main.c LinkedStack.h Status.h
	gcc -c ./main.c

LinkedStack.o: LinkedStack.c LinkedStack.h Status.h
	gcc -c ../LinkedStack/LinkedStack.c

.PHONY: clean

clean:
	rm target *.o
