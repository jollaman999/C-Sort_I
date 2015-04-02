CC=gcc
CFLAGS=-Wall

all:
	$(CC) $(CFLAGS) -o Sort_I *.c
clean:
	rm -rf *.o *.out Sort_I
