CC = g++
CFLAGS = -std=c++11 
all : flight

flight: utils.o bfs.o astar.o tests.o floyd.o main.o
	$(CC) $(CFLAGS) utils.o bfs.o astar.o floyd.o tests.o main.o -o flight

main.o: main.cpp airport.h utils.h bfs.h astar.h tests.h
	$(CC) $(CFLAGS) -c main.cpp

utils.o: utils.h utils.cpp airport.h
	$(CC) $(CFLAGS) -c utils.cpp

bfs.o: bfs.h bfs.cpp utils.h airport.h
	$(CC) $(CFLAGS) -c bfs.cpp

astar.o: astar.h astar.cpp utils.h airport.h
	$(CC) $(CFLAGS) -c astar.cpp

floyd.o: floyd.h floyd.cpp utils.h airport.h
	$(CC) $(CFLAGS) -c floyd.cpp

tests.o: tests.h tests.cpp
	$(CC) $(CFLAGS) -c tests.cpp

clean:
	rm *.o flight