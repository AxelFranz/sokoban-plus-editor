CFLAGS+= -Wall -Wextra
LDFLAGS+= -lm

main: main.o grid.o
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o : %.c 
	gcc -c $< -o $@

main.c: grid.h
grid.c: grid.h

clean: 
	rm $(wildcard *.o)
