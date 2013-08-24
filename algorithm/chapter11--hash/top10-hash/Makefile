CC = gcc
#FILE = hash 
CFLAGS = -Wall -g
MAIN_O = main.o hash.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
hash.o:hash.c
	$(CC) $(CFLAGS) -c hash.c
clean:
	rm -rf main $(MAIN_O)
