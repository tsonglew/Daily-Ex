BDIR = ../bin
IDIR = ../include
CC = gcc
CFLAGS = -I $(IDIR)
ODIR = obj
LDIR = ../lib
LIBS = -lm
_DEPS = myprog.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))
_OBJ = main.o deps.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

myprog:	$(OBJ)
	gcc -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)
