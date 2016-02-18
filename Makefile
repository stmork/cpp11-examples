CXXFLAGS=-std=c++11 -g3

all:	container exception

clean:
	rm -rf *.o container exception

container.o:	container.cc

exception.o:	exception.cc

container:	container.o
	$(LINK.cc) -o $@ $^

exception:	exception.o
	$(LINK.cc) -o $@ $^
