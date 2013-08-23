CC = g++
#FILE = hash 
CFLAGS = -Wall -g
MAIN_O = main.o binomial_heap.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
binomial.o:binomial_heap.cpp
	$(CC) $(CFLAGS) -c binomial_heap.cpp
main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp
clean:
	rm -rf main $(MAIN_O)
