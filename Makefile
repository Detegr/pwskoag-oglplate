CC=g++ -Os -Wall -Wextra -Werror -Wno-comment
CFLAGS=-I/usr/local/include/GL -I/usr/local/include -L /usr/local/lib
LIBS=-lGL -lGLU -lglfw -lXrandr -lBox2D
OSXLIBS=-framework OpenGL -framework Cocoa -lglfw -lBox2D
SOURCES=main.cpp singleton.cpp renderer.cpp inputhandler.cpp shadermanager.cpp filereader.cpp modelmanager.cpp entity.cpp model.cpp physicsmanager.cpp physicalentity.cpp timer.cpp
HEADERS=$(SOURCES:.cpp=.h)
OBJECTS=$(SOURCES:.cpp=.o)
EXE=main

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) gl3w.o -o $(EXE) $(LIBS)

osx: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) gl3w.o -o $(EXE) $(OSXLIBS)

%.o : %.cpp %.h
	$(CC) $(CFLAGS) -c $(SOURCES)

clean:
	-rm $(EXE)
	mv gl3w.o gl3w.o.bak
	-rm *.o
	mv gl3w.o.bak gl3w.o

.PHONY: all clean
