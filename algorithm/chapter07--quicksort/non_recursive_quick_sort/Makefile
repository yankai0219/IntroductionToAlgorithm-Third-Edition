CC = gcc
MAIN = main.o quicksort.o stack.o
FLAG = -g -Wall

main: $(MAIN)
	$(CC) $(FLAG) -o main $(MAIN)
main.o: main.c
	$(CC) $(FLAG) -c main.c 
stack.o: stack.c
	$(CC) $(FLAG) -c stack.c 
quicksort.o: quicksort.c
	$(CC) $(FLAG) -c quicksort.c 
clean: 
	rm -rf main $(MAIN)
