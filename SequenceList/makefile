vpath %.c SequenceList:../Status
vpath %.h SequenceList:../Status

sequencelist:main.o SqList.o Status.o
	gcc -o sequencelist main.o SqList.o Status.o

main.o:main.c SqList.h Status.h
	gcc -c main.c

SqList.o:SqList.c SqList.h Status.h
	gcc -c SqList.c

Status.o:Status.c Status.h
	gcc -c ../Status/Status.c

.PHONY:clean

clean:
	rm sequencelist *.o
