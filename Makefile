CC = clang

CFLAGS = -x c++ -c -std=c++11 -pedantic -Wall
LFLAGS = -lstdc++ -lm

SOURCES = timbres.cc
OBJECTS = $(SOURCES:.cc=.o)
EXECUTABLE = timbres


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
		$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cc.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -f $(EXECUTABLE) $(OBJECTS)

# TARGET = cpp11_test
#$(TARGET): $(TARGET).cpp
#		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp $(LFLAGS)

