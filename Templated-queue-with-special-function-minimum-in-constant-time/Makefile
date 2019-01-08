all: run

run: main.o fruit.o vegetables.o n_store.o
	g++ main.o fruit.o vegetables.o n_store.o -o run

main.o: main.cpp
	g++ -c main.cpp

n_store.o: n_store.cpp
	g++ -c n_store.cpp

fruit.o: fruit.cpp
	g++ -c fruit.cpp 

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

clean:
	rm *o run
