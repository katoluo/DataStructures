vpath %.h ./../Status
vpath %.c ./../Status

SequenceQueue: main.o SqQueue.o Status.o
	gcc -o SequenceQueue main.o SqQueue.o Status.o

mian.o: main.c SqQueue.h Status.h
	gcc -c ./main.c

SqQueue.o: SqQueue.c SqQueue.h Status.h
	gcc -c ./SqQueue.c

Status.o: Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY: clean

clean:
	rm SequenceQueue *.o
