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


all: doc main

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
