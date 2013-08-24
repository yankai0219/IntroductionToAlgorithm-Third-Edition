CC = gcc
MAIN = main.o binary_heap.o
FLAG = -g -Wall

main: $(MAIN)
	$(CC) $(FLAG) -o main $(MAIN)
main.o: main.c
	$(CC) $(FLAG) -c main.c 
binary_heap.o: binary_heap.c
	$(CC) $(FLAG) -c binary_heap.c 
clean: 
	rm -rf main $(MAIN)
