#demonstracja kompilacji na prostym programie

#kompilator
CC = gcc

#flaga
LFLAGS = -o
CFLAGS = -std=c99 -Wall

#linker
LINKER = gcc

#optymalizacja
OPT = -g

hello: hello.o
	$(LINKER) $(LFLAGS) hello hello.o
hello: hello.c
	$(CC) $(CFLAGS) $(OPT) hello.c
clean:
	rm -f *.o
run: hello
	./hello
