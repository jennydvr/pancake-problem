all: clean pancakes
pancakes: main.out

main.out: main.o Node.o
	g++ -o pancake.out main.o Node.o

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.h Node.cpp
	g++ -c Node.h Node.cpp


clean:
	rm -f *.o; rm -f pancake.out
