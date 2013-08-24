CC = gcc
MAIN = main.o
FLAG = -g -Wall

main: $(MAIN)
	$(CC) $(FLAG) -o main $(MAIN)
main.o: main.c
	$(CC) $(FLAG) -c main.c 
clean: 
	rm -rf main $(MAIN)
