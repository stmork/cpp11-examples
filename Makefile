# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

CFLAGS   += -Wall -Wextra -fstack-protector-strong -O3

CXXFLAGS += $(CFLAGS) -std=c++20

SRC       = cast.cc container.cc set.cc exception.cc regex.cc constructor.cc hash.cc queue.cc\
	lut.cc mapper.cc sharedptr.cc units.cc singleton.cc string.cc enum.cc rsqrt.cc\
	trampoline.cc cv.cc format.cc transform.cc
PRGS      = cast container set exception regex constructor hash mapper queue\
	lut sharedptr units singleton string enum rsqrt trampoline cv format transform

all:	$(PRGS)

depend:
	$(CPP) -std=c++20 -E -M  $(SRC) $(CPPFLAGS) >.dep

clean:
	rm -rf *.o $(PRGS)

cast:	cast.o
	$(LINK.cc) -o $@ $^

container:	container.o
	$(LINK.cc) -o $@ $^

format:	format.o
	$(LINK.cc) -o $@ $^

queue:	queue.o
	$(LINK.cc) -o $@ $^

set:	set.o
	$(LINK.cc) -o $@ $^

exception:	exception.o
	$(LINK.cc) -o $@ $^

regex:	regex.o
	$(LINK.cc) -o $@ $^

constructor:	constructor.o
	$(LINK.cc) -o $@ $^

lut:	lut.o
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

rsqrt:	rsqrt.o
	$(LINK.cc) -o $@ $^

trampoline:	trampoline.o
	$(LINK.cc) -o $@ $^

transform:	transform.o
	$(LINK.cc) -o $@ $^

units:	units.o
	$(LINK.cc) -o $@ $^

cv:	cv.o
	$(LINK.cc) -o $@ $^ -lpthread

hash:	hash.o
	$(LINK.c) -o $@ $^ -lpthread

-include .dep
