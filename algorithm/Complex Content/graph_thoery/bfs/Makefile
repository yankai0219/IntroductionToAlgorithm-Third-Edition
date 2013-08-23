CC = gcc
#FILE = hash 
CFLAGS = -Wall -g
MAIN_O = main.o bfs.o queue.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
queue.o:queue.c
	$(CC) $(CFLAGS) -c queue.c
bfs.o:bfs.c
	$(CC) $(CFLAGS) -c bfs.c
clean:
	rm -rf main $(MAIN_O)
