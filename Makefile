CFLAGS= -Wall -Wextra -g
INCFLAGS= -I include/
OBJPATH=obj/
CSTD = -std=c11
CC = gcc
vpath %.c src/
vpath %.h include/
vpath %.o obj/


all: install_dir/lib doc main# On vérfie l'existence lib car dans les autres dossiers SDL il y a des fichiers de log qui s'updatent et referont compiler alors que lib est statique

main: $(addprefix $(OBJPATH),$(addsuffix .o,$(basename $(notdir $(wildcard src/*.c)))))
	$(CC) $(CSTD) $(CFLAGS) -o $@ $^ $(LDFLAGS)`$$PWD/install_dir/bin/sdl2-config --cflags --libs`

$(OBJPATH)%.o : %.c $(OBJPATH) 
	$(CC) $(CSTD) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

$(OBJPATH):
	mkdir $@

# Les wrappers de tests
install_dir/lib: 
	make compilSDL
doc/: doc

doc:
	doxygen

compilSDL:
	cd SDL2/ && ./configure --prefix="$$PWD/../install_dir" && make install -j6


clean: 
	rm -rf doc main vgcore.* FRA* $(OBJPATH) install_dir/

archive:
	tar -cf FRANZ_Axel.tar.gz include/ src/ Makefile README.md Doxyfile level?.txt
