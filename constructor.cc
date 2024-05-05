// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2024 Steffen A. Mork

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
		throw std::runtime_error("Exception absichtig geworfen!");
	}

	virtual ~Derived()
	{
		printf("d'tor() Derived\n");
	}
};

int main()
{
	Derived object;

	printf("Live time...\n");

	return EXIT_SUCCESS;
}
