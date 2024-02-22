CC=g++
DEPS=transforms3D.h
CFLAGS=-lGL -lGLU -lglut
SRCDIR=src
BINDIR=build

main: build
	$(CC) $(CFLAGS) -o $(BINDIR)/main $(SRCDIR)/$(DEPS) $(SRCDIR)/main.cpp

build:
	mkdir $(BINDIR)

run:
	./build/main

clean:
	rm -rv $(BINDIR)