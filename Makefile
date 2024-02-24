CC=g++
SRCDIR=src
BINDIR=build
DEPS=$(shell find $(SRCDIR) -name "*.cpp")
CFLAGS=-lGL -lGLU -lglut

main: build
	$(CC) $(CFLAGS) -o $(BINDIR)/main $(DEPS)

build:
	mkdir $(BINDIR)

run:
	./build/main

clean:
	rm -rv $(BINDIR)