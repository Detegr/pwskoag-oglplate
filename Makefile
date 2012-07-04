CC=g++ -g3
CFLAGS=-I/usr/local/include/GL -I/usr/local/include -L /usr/local/lib
LIBS=-lGL -lGLU -lglfw -lXrandr
SOURCES=main.cpp singleton.cpp renderer.cpp
HEADERS=$(SOURCES:.cpp=.h)
OBJECTS=$(SOURCES:.cpp=.o)
EXE=main

all: $(OBJECTS)
	g++ $(CFLAGS) $(OBJECTS) -o $(EXE) $(LIBS)

$(EXE): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES) $(LIBS)

clean:
	-rm $(EXE)
	-rm *.o

.PHONY: all clean
