CC = g++
CFLAGS = -c -std=c++17 -lstdc++fs

all: program

program: calculate_variance.o
	$(CC) calculate_variance.o -o program

calculate_variance.o: calculate_variance.cpp
	$(CC) $(CFLAGS) -c calculate_variance.cpp 

run: program
	./program 1 100 1000000 500000000

run_and_save: program
	./program save 1 100 1000000 500000000

clean:
	rm *.o program