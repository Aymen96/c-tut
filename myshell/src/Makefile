IDIR=../include
CC=gcc
CFLAGS= -I$(IDIR) #look in directory ../include for header files

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = shell.h process_manager.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o shell.o process_manager.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_OBJ2 = user_manager.o
OBJ2 = $(patsubst %,$(ODIR)/%,$(_OBJ2))

%.o: %.c $(DEPS)
	$(CC) -o -o $@ $< $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myshell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

user_manager: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
