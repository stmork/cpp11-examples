// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdio>
#include <cstdlib>
#include <stdexcept>

class Base
{
public:
	Base()
	{
		printf("c'tor() Base\n");
	}

	virtual ~Base()
	{
		printf("d'tor() Base\n");
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		printf("c'tor() Derived\n");
		throw std::runtime_error("Exception absichtlich geworfen!");
	}

	virtual ~Derived()
	{
		printf("d'tor() Derived\n");
	}
};

int main()
{
	try
	{
		Derived object_catched;

		printf("Live time...\n");
	}
	catch (std::exception & e)
	{
		fprintf(stderr, "Error: %s\n", e.what());
	}

	printf("--------------\n");
	Derived object_terminated;

	return EXIT_SUCCESS;
}
