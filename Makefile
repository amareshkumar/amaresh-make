cc = g++
CXXFLAGS = -std=c++0x -std=c++11 -std=gnu++11 -std=gnu++0x -g -o2 -Wall -pedantic -DLINKED_LIST
object := $(patsubst %.cpp,%.o, $(wildcard *.cpp))

all: amaresh
amaresh: $(object)
	cc $(CXXFLAGS) -o amaresh $(object) -lstdc++ -L/usr/ -L/usr/lib -L/usr/local/bin
clean: 
	rm -f *.o amaresh amaresh.exe