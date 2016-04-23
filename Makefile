CXXFLAGS=-std=c++11 -g3

all:	container exception regex

clean:
	rm -rf *.o container exception

container.o:	container.cc

exception.o:	exception.cc

regex.o:	regex.cc

container:	container.o
	$(LINK.cc) -o $@ $^

exception:	exception.o
	$(LINK.cc) -o $@ $^

regex:	regex.o
	$(LINK.cc) -o $@ $^
