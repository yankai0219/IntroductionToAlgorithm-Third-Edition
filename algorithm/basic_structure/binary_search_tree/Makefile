CC = gcc
FILE = binary_search_tree 
CFLAGS = -Wall -g
MAIN_O = main.o binary_search_tree.o

MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
$(FILE).o:$(FILE).c
	$(CC) $(CFLAGS) -c binary_search_tree.c
clean:
	rm -rf main $(MAIN_O) 
