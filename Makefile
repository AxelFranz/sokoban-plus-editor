CFLAGS= -Wall -Wextra
INCFLAGS= -I include/
OBJPATH=obj/
LDFLAGS = -lSDL2
CSTD = -std=c11
CC = gcc
EXEC = main
vpath %.c src/
vpath %.h include/
vpath %.o obj/


all: doc main# On vérfie l'existence lib car dans les autres dossiers SDL il y a des fichiers de log qui s'updatent et referont compiler alors que lib est statique

	

$(EXEC): $(addprefix $(OBJPATH),$(addsuffix .o,$(basename $(notdir $(wildcard src/*.c)))))
	$(CC) $(CSTD) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJPATH)%.o : %.c $(OBJPATH) 
	$(CC) $(CSTD) $(CFLAGS) $(INCFLAGS) -c -o $@ $<

debug: $(addprefix $(OBJPATH),$(addsuffix .o,$(basename $(notdir $(wildcard src/*.c)))))
	$(CC) $(CSTD) $(CFLAGS) -g -o $(EXEC) $^ $(LDFLAGS)


$(OBJPATH):
	mkdir $@

# Les wrappers de tests
doc/: doc

doc:
	doxygen

clean: 
	rm -rf doc main vgcore.* FRA* $(OBJPATH) install_dir/

archive:
	tar -cf FRANZ_Axel.tar.gz include/ src/ Makefile README.md Doxyfile level?.txt
