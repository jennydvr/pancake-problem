all: clean pancakes generador

pancakes: main.out

main.out: main.o Node.o IDA.o
	g++ -o pancake.out main.o Node.o IDA.o

main.o: main.cpp
	g++ -c -O6 main.cpp

Node.o: Node.h Node.cpp
	g++ -c -O6 Node.h Node.cpp

IDA.o:  Node.h IDA.h IDA.cpp
	g++ -c -O6 Node.h IDA.h IDA.cpp


generador: generador.o
	g++ -o Generador.out generador.o

generador.o: generador.cpp
	g++ -c -O6 generador.cpp

clean:
	rm -f *.o; rm -f pancake.out
