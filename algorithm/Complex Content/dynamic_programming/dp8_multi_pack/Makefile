CC = gcc
 
CFLAGS = -Wall -g
MAIN_O = main.o 
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
clean:
	rm -rf main $(MAIN_O)
