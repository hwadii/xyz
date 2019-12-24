TARGET = main
OBJS = hash.o main.o
OPTS = -Wall
CC = gcc

main.o: main.c
	$(CC) -c $< $(OPTS)

hash.o: hash.c
	$(CC) -c $< $(OPTS)

prog: $(OBJS)
	$(CC) $^ -o $(TARGET)

clean:
	rm -rf main *.o

.PHONY: clean prog
