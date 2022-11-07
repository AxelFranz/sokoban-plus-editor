CFLAGS= -Wall -Wextra
INCFLAGS= -I include
OBJPATH=obj/
vpath %.c src/
vpath %.h include/
vpath %.o obj/

main: $(addprefix $(OBJPATH),main.o grid.o player.o)
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJPATH)%.o : %.c $(OBJPATH) 
	gcc $(CFLAGS) $(INCFLAGS) -c -o $@ $<

$(OBJPATH):
	mkdir $@

clean: 
	rm -rf doc main vgcore.* FRA* $(OBJPATH)

doc:
	doxygen

archive:
	tar -cf FRANZ_Axel.tar.gz include/ src/ Makefile README.md Doxyfile 
