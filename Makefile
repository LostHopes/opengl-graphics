CC=gcc
DEPS=transform.h
CFLAGS=-lGL -lGLU -lglut
SRCDIR=src
BINDIR=build

main: build
	$(CC) $(CFLAGS) -o $(BINDIR)/main $(SRCDIR)/$(DEPS) $(SRCDIR)/main.cpp

build:
	mkdir $(BINDIR)
