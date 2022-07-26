// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 Steffen A. Mork

#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <memory>

class A
{
public:
	A()
	{
		printf("A()\n");
	}

	virtual ~A()
	{
		printf("~A()\n");
	}
};

class B
{
	std::shared_ptr<A> a;

public:
	B(const std::shared_ptr<A> & ptr)
	{
		printf("B a=%ld\n", a.use_count());
		printf("B ptr=%ld\n", ptr.use_count());
		a = ptr;
		printf("B a=%ld\n", a.use_count());
		printf("B ptr=%ld\n", ptr.use_count());
		printf("B()\n");
	}

	virtual ~B()
	{
		printf("B a=%ld\n", a.use_count());
		printf("~B()\n");
	}
};

class C
{
	std::shared_ptr<B> b;
	std::shared_ptr<A> a;

public:
	C()
	{
		a = std::make_shared<A>();
		b = std::make_shared<B>(a);

		printf("C()\n");
	}

	virtual ~C()
	{
		printf("C a=%ld\n", a.use_count());
		printf("C b=%ld\n", b.use_count());
		printf("~C()\n");
	}
};

int main()
{
	C c;

	return EXIT_SUCCESS;
}
