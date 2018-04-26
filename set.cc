/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   STL container reference behavior.
 */

#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <string>

class element
{
	int         value;
	std::string name;

public:
	element(const int a, const std::string & name)
	{
		this->value = a;
		this->name = name;
	}

	element(const element & other)
	{
		this->value = other.value;
		this->name = other.name;
	}

	element(element && other)
	{
		this->value = other.value;
		this->name = std::move(other.name);
	}

	operator int() const
	{
		return value;
	}

	bool operator < (const element & other) const
	{
		return name < other.name;
	}

	operator std::string() const
	{
		return name;
	}
};

namespace std
{
	template <> struct less<element *>
	{
		bool operator () (const element * left, const element * right) const
		{
			return *left < *right;
		}
	};
}

int main()
{
	std::set<element> raw_elements;
	std::set<element *> ptr_elements;

	printf("Starting...\n");
	element d(19, "Steffen");
	element a(6, "Michael");
	element b(28, "Christian");
	element c(21, "Adrian");

	raw_elements.insert(a);
	raw_elements.insert(b);
	raw_elements.insert(c);
	raw_elements.insert(d);

	ptr_elements.insert(&a);
	ptr_elements.insert(&b);
	ptr_elements.insert(&c);
	ptr_elements.insert(&d);

	printf("Element count: %zu\n", ptr_elements.size());

	printf("Raw elements:\n");
	for (const element & e : raw_elements)
	{
		int a = e;
		std::string name = e;

		printf("%d: %s\n", a, name.data());
	}

	printf("Pointer elements:\n");
	for (element * e : ptr_elements)
	{
		int a = *e;
		std::string name = *e;

		printf("%d: %s\n", a, name.data());
	}
	return EXIT_SUCCESS;
}
