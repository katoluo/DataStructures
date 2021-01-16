vpath %.h ../Status:../SequenceStack

vpath %.c .:../Status:../SequenceStack

target: main.o SqStack.o Status.o
	gcc -o target main.o SqStack.o Status.o

main.o: main.c SqStack.h Status.h
	gcc -c ./main.c

SqStack.o : SqStack.c SqStack.h Status.h
	gcc -c ../SequenceStack/SqStack.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm target *.o
