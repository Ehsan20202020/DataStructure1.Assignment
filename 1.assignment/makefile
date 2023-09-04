all: compile run

compile:
	g++ -I ./include/ -o ./lib/linkedList.o -c ./src/linkedList.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/UpwardList.o -c ./src/UpwardList.cpp
	g++ -I ./include/ -o ./lib/DownwardList.o -c ./src/DownwardList.cpp
	
	
	g++ -I ./include/ -o ./bin/main ./lib/linkedList.o ./lib/Node.o ./lib/UpwardList.o ./lib/DownwardList.o ./src/main.cpp
	
run:
	./bin/main



