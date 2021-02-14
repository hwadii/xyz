TARGET = main
OBJS = hash.o main.o
OPTS = -Wall -Wconversion
CC = gcc

main: $(OBJS)
	$(CC) $^ -o $(TARGET)

main.o: main.c
	$(CC) -c $< $(OPTS)

hash.o: hash.c
	$(CC) -c $< $(OPTS)

clean:
	rm -rf main *.o

.PHONY: clean prog
