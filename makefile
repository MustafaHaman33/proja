all: main

main: src/main.o src/BinaryTree.o src/LinkedList.o
	g++ -o bin/main src/main.o src/BinaryTree.o src/LinkedList.o

src/main.o: src/main.cpp include/BinaryTree.h include/LinkedList.h
	g++ -c src/main.cpp -o src/main.o

src/BinaryTree.o: src/BinaryTree.cpp include/BinaryTree.h
	g++ -c src/BinaryTree.cpp -o src/BinaryTree.o

src/LinkedList.o: src/LinkedList.cpp include/LinkedList.h include/BinaryTree.h
	g++ -c src/LinkedList.cpp -o src/LinkedList.o

clean:
	rm -f src/*.o bin/main
