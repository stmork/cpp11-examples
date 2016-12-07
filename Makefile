CXXFLAGS	+=-std=c++11 -g
SRC		 = container.cc exception.cc regex.cc constructor.cc hash.cc
PRGS		 = container exception regex  constructor hash

all:	$(PRGS)

depend:
	$(CXX) -std=c++11 -E -M  $(SRC) $(CPPFLAGS) >.dep

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

-include .dep
