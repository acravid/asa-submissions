all: a.out random_k

a.out: file.cpp
	g++ -std=c++11 -O3 -Wall file.cpp -lm

random_k: random_k.cpp
	g++ -O3 -Wall -o random_k random_k.cpp -lm
	
clean:
	rm a.out random_k