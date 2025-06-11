// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <memory>

template<class T> class SharedPtrThis
{
	std::shared_ptr<T> self;

public:
	SharedPtrThis() : self((T *)this, &noop)
	{
	}

	operator const std::shared_ptr<T> & () const
	{
		return self;
	}

	static void noop(T * ptr)
	{
		(void)ptr;
	}
};

class A : public std::enable_shared_from_this<A>
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

class D : public SharedPtrThis<D>
{
public:
	D()
	{
		printf("D()\n");
	}

	virtual ~D()
	{
		printf("~D()\n");
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
	std::shared_ptr<D> d;

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

	void assign(std::shared_ptr<A> a_ptr)
	{
		printf("Assign A\n");
		a = a_ptr;
	}

	void assign(std::shared_ptr<D> d_ptr)
	{
		printf("Assign D\n");
		d = d_ptr;
	}
};

int main()
{
	A a;
	D d;
	C c;

	printf("Make shared_ptr instance...\n");
	std::shared_ptr<A> a_ptr = std::make_shared<A>();

	printf("Getting std shared this...\n");
	c.assign(a_ptr->shared_from_this());

	printf("Getting my shared this...\n");
	c.assign(d);
	return EXIT_SUCCESS;
}
