// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 Steffen A. Mork

#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

/**
 * This base class shows if the constructor or destructor was called.
 */
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

/**
 * This class show what happens if an exeption is thrown inside
 * the constructor.
 */
class Derived : public Base
{
public:
	explicit Derived(const bool throw_it = false)
	{
		printf("c'tor() Derived\n");
		if (throw_it)
		{
			throw std::runtime_error("Exception absichtig geworfen!");
		}
	}

	virtual ~Derived()
	{
		printf("d'tor() Derived\n");
	}
};

int main()
{
	Derived object;
	Derived thrower(true);

	printf("Live time...\n");

	return EXIT_SUCCESS;
}
