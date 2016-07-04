CXXFLAGS	+=-std=c++11 -g
PRGS		 = container exception regex  constructor

all:	$(PRGS)

clean:
	rm -rf *.o $(PRGS)

container:	container.o
	$(LINK.cc) -o $@ $^

exception:	exception.o
	$(LINK.cc) -o $@ $^

regex:	regex.o
	$(LINK.cc) -o $@ $^

constructor:	constructor.o
	$(LINK.cc) -o $@ $^
