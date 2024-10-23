LIB = liby2b.a
LFLAG = -ly2b

all: main.c $(LIB)
	$(CC) $< -L. $(LFLAG)

liby2b.a: error.o string.o
	ar -rcs $@ $^

error.o: error.c liby2b.h
	$(CC) $(CFLAGS) -c -o $@ $<

string.o: string.c liby2b.h
	$(CC) $(CFLAGS) -c -o $@ $<
