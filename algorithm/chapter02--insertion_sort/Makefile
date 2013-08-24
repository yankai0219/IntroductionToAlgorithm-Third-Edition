CC = gcc
FILE = insertion_sort
CFLAGS = -Wall -g
MAIN_O = main.o $(FILE).o
MAIN: $(MAIN_O)
	$(CC) $(CFLAGS) -o main $(MAIN_O)
main.o:main.c
	$(CC) $(CFLAGS) -c main.c
$(FILE).o:$(FILE).c
	$(CC) $(CFLAGS) -c $(FILE).c
clean:
	rm -rf main $(MAIN_O)
