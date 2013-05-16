CC = gcc
#FILE = queue 
CFLAGS = -Wall -g
MAIN_O = main.o queue.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
queue.o:queue.c
	$(CC) $(CFLAGS) -c queue.c
clean:
	rm -rf main $(MAIN_O)
