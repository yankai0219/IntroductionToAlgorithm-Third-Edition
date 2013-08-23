CC = g++
#FILE = hash 
CFLAGS = -Wall -g
MAIN_O = main.o fibonacci.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp
fibonacci.o:fibonacci.cpp
	$(CC) $(CFLAGS) -c fibonacci.cpp
clean:
	rm -rf main $(MAIN_O)
