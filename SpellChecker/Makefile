all: run

run: main.o managing_dict.o operations.o entry.o
	g++ -g main.o managing_dict.o operations.o entry.o -o run

main.o: main.cpp
	g++ -g -c main.cpp

managing.o: managing_dict.cpp
	g++ -g -c managing_dict.cpp

operation.o: operations.cpp
	g++ -g -c operations.cpp

entry.o: entry.cpp
	g++ -g -c entry.cpp

clean:
	rm -f *o run