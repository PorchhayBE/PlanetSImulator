CC = g++
CFLAGS = -Wall -Werror -pedantic --std=c++14
LIBS = -lsfml-graphics	-lsfml-window -lsfml-system
DEPS = ./Header/CelestialBody.h ./Header/Universe.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

all: Nbody

Nbody: CelestialBody.o Universe.o main.o 
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm *.o Nbody