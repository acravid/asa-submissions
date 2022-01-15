all: a.out randGeneoTree

a.out: file.cpp
	g++ -std=c++11 -O3 -Wall file.cpp -lm

randGeneoTree: randGeneoTree.cpp
	g++ -std=c++11 -O3 -Wall randGeneoTree.cpp -lm -o randGeneoTree

.PHONY : clean
clean :
	-rm a.out randGeneoTree
