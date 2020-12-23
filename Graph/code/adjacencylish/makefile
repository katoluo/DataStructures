objects = main.o adjacency_lish.o

edit : $(objects)
	g++ -o edit $(objects) -Wall -std=c++11

main.o : adjacency_lish.h

adjacency_lish.o : adjacency_lish.h

.PHONY : clean
clean : 
	-rm edit $(objects)
