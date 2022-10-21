CFLAGS+= -Wall -Wextra
LDFLAGS+= -lm

main: main.o grid.o
	gcc -o main main.o grid.o $(CFLAGS) $(LDFLAGS)

main.o: main.c grid.h
	gcc -o main.o main.c $(CFLAGS) $(LDFLAGS)

grid.o: grid.c grid.h
	gcc -o grid.o grid.c $(CFLAGS) $(LDFLAGS)

clean: 
	rm %.o
