# Compiler settings
CC = gcc
BASE_CFLAGS = -Wall -Werror -g
CFLAGS += $(BASE_CFLAGS)

# Object files variable that contains a list of 
# the object files that will be built
# add the required .o files below and delete blah.o
OBJS = # add data.o

# Default target all runs the compilation for main and test
# by default it will create both files
all: main test

# Main program target
main: $(OBJS)
	$(CC) $(CFLAGS) -o main.bin main.c $(OBJS)

# Test program target
test: $(OBJS)
	$(CC) $(CFLAGS) -o test.bin test.c $(OBJS)

# Generic rule for building object files
# using the list of files below, it will build 
# them in order, the %.o looks for all the .o targets
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Dependencies
# ADD XXX.o: XXX.h


# Clean target
clean:
	rm -f main.bin test.bin *.o

# .PHONY will cause the Makefile to the target
# all and then the target clean by default
.PHONY: all clean