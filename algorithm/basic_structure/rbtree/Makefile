CC = gcc
#FILE = rbtree 
CFLAGS = -Wall -g
MAIN_O = main.o rbtree.o

MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
rbtree.o:rbtree.c
	$(CC) $(CFLAGS) -c rbtree.c
clean:
	rm -rf main $(MAIN_O) 
