CFLAGS= -Wall -Wextra
INCFLAGS= -I include/
OBJPATH=obj/
CC = gcc
vpath %.c src/
vpath %.h include/
vpath %.o obj/

main: $(addprefix $(OBJPATH),$(addsuffix .o,$(basename $(notdir $(wildcard src/*.c)))))
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)`$$PWD/install_dir/bin/sdl2-config --cflags --libs`
$(OBJPATH)%.o : %.c $(OBJPATH) 
	$(CC) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

$(OBJPATH):
	mkdir $@

doc:
	doxygen

compilSDL:
	cd SDL2/ && ./configure --prefix="$$PWD/../install_dir" && make install -j6


clean: 
	rm -rf doc main vgcore.* FRA* $(OBJPATH) install_dir/

archive:
	tar -cf FRANZ_Axel.tar.gz include/ src/ Makefile README.md Doxyfile level?.txt 
