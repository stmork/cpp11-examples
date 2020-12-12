CXXFLAGS += -Wall -Wextra -fstack-protector-strong -std=c++17
CXXFLAGS += -O3
SRC       = container.cc set.cc exception.cc regex.cc constructor.cc hash.cc\
	mapper.cc sharedptr.cc units.cc singleton.cc string.cc enum.cc
PRGS      = container set exception regex constructor hash mapper\
	sharedptr units singleton string enum

all:	$(PRGS)

depend:
	$(CXX) -std=c++14 -E -M  $(SRC) $(CPPFLAGS) >.dep

clean:
	rm -rf *.o $(PRGS)

container:	container.o
	$(LINK.cc) -o $@ $^

set:	set.o
	$(LINK.cc) -o $@ $^

exception:	exception.o
	$(LINK.cc) -o $@ $^

regex:	regex.o
	$(LINK.cc) -o $@ $^

constructor:	constructor.o
	$(LINK.cc) -o $@ $^

units:	units.o
	$(LINK.cc) -o $@ $^

mapper:	mapper.o
	$(LINK.cc) -o $@ $^

sharedptr:	sharedptr.o
	$(LINK.cc) -o $@ $^

singleton:	singleton.o
	$(LINK.cc) -o $@ $^

string:	string.o
	$(LINK.cc) -o $@ $^

enum:	enum.o
	$(LINK.cc) -o $@ $^

-include .dep
