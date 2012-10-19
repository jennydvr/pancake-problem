CXX = g++
CXXFLAGS = -O4

build-exec = $(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: all clean

all: pancakes generador
clean: ; rm -f ./*.o ./*.gch pancakes generador

%.o: %.cpp ; $(CXX) $(CXXFLAGS) -c $<

pancakes: main.o Node.o IDA.o Astar.o ; $(build-exec)
generador: generador.o ; $(build-exec)
	
main.o: main.cpp Node.h IDA.h Astar.h
Node.o: Node.cpp Node.h
IDA.o: IDA.cpp  Node.h IDA.h
Astar.o: Astar.cpp Node.h Astar.h
generador.o: generador.cpp

