CFLAGS+= -Wall -Wextra
LDFLAGS+= -lm

main: main.o grid.o
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o : %.c 
	gcc -c $< -o $@

%.c: grid.h

clean: 
	rm -rf $(wildcard *.o) html/ main vgcore.* FRA*

doc:
	doxygen

archive:
	tar -cf FRANZ_Axel.tar.gz *.h *.c Makefile level?.txt README.md Doxyfile 
