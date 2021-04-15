adjacency_matrix : main.o adjacency_matrix.o
	g++ -o adjacency_matrix main.o adjacency_matrix.o -Wall -std=c++11

main.o : adjacency_matrix.h
	g++ -c main.cpp -Wall -std=c++11

adjacency_matrix.o : adjacency_matrix.h
	g++ -c adjacency_matrix.cpp -Wall -std=c++11

.PHONY : clean
clean :
	-rm -f adjacency_matrix main.o adjacency_matrix.o

