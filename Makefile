CXXFLAGS=-std=c++11 -g3

all:	container

clean:
	rm -rf *.o container

container.o:	container.cc

container:	container.o
	$(LINK.cc) -o $@ $^
	
