CC = gcc
#FILE = stack 
CFLAGS = -Wall -g
MAIN_O = main.o stack.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
stack.o:stack.c
	$(CC) $(CFLAGS) -c stack.c
clean:
	rm -rf main $(MAIN_O)
