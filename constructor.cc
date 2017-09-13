/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   constructor behaviour.
 */

#include <stdio.h>
#include <stdlib.h>
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
