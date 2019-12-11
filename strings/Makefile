MAIN = main.cpp
HEADER = string.hpp
OBJS = string.o
COMPILER_OPTIONS = -Wall
CXX = g++

%.o: %.c
	$(CXX) $< $(COMPILER_OPTIONS) -c $@

all: $(MAIN) $(OBJS)
	$(CXX) $^ -o main

clean:
	rm -rf main *.o
