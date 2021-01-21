vpath %.h .:../Status

vpath %.c .:../Status

sequencestack: main.o SqStack.o Status.o
	gcc -o sequencestack main.o SqStack.o Status.o

main.o: main.c SqStack.h Status.h
	gcc -c ./main.c

SqStack.o: SqStack.c SqStack.h Status.h
	gcc -c ./SqStack.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm sequencestack *.o
