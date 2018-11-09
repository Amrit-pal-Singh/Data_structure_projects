all: run

run: main.o fruit.o vegetables.o grocery_store.o node.o
	g++ main.o fruit.o vegetables.o grocery_store.o node.o -o run

main.o: main.cpp
	g++ -c main.cpp

fruit.o: fruit.cpp
	g++ -c fruit.cpp

vegetables.o: vegetables.cpp
	g++ -c vegetables.cpp

grocery_store.o: grocery_store.cpp
	g++ -c grocery_store.cpp

node.o: node.cpp
	g++ -c node.cpp

clean: 
	rm *o run
