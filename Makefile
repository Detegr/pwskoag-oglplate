CC=g++ -g3 -Wall -Wextra -Werror
CFLAGS=-I/usr/local/include/GL -I/usr/local/include -L /usr/local/lib
LIBS=-lGL -lGLU -lglfw -lXrandr
SOURCES=main.cpp singleton.cpp renderer.cpp inputhandler.cpp shadermanager.cpp filereader.cpp modelmanager.cpp
HEADERS=$(SOURCES:.cpp=.h)
OBJECTS=$(SOURCES:.cpp=.o)
EXE=main

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) gl3w.o -o $(EXE) $(LIBS)

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $(SOURCES) $(LIBS)

clean:
	-rm $(EXE)
	mv gl3w.o gl3w.o.bak
	-rm *.o
	mv gl3w.o.bak gl3w.o

.PHONY: all clean
