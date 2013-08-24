CC = gcc
#FILE = hash 
CFLAGS = -Wall -g
MAIN_O = main.o dfs.o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
dfs.o:dfs.c
	$(CC) $(CFLAGS) -c dfs.c
clean:
	rm -rf main $(MAIN_O)
