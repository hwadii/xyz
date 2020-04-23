MAIN = main.cpp
HEADER = string.hpp tests.hpp
OBJS = string.o tests.o
COMPILER_OPTIONS = -Wall
CXX = g++

%.o: %.c
	$(CXX) $< $(COMPILER_OPTIONS) -c $@

main: $(MAIN) $(OBJS)
	$(CXX) $^ -o main

clean:
	rm -rf main *.o

.PHONY = clean
