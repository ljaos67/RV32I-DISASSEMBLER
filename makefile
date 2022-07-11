#
# PROGRAM: Assignment #4
# AUTHOR:  Leonart Jaos
#
CXXFLAGS = -pedantic -Wall -Werror -Wextra -g -std=c++14

PROG ?= rv32i
OBJS = hex.o memory.o rv32i_decode.o main.o

all: $(PROG)

.cpp.o:
		g++ $(CXXFLAGS) -c -o $@ $<

$(PROG): $(OBJS)
		g++ $(CXXFLAGS) -o $@ $(OBJS)

clean:
		rm -f *. $(PROG)
			rm -f *.o
