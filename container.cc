/*
 * $Id$
 * $Author$
 */

#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

class element
{
	string name;
	int    a;
	int    b;

public:
	element()
	{
		printf("c'tor() %p\n", this);
	}

	element(const element & e)
	{
		this->name = e.name;
		this->a    = e.a;
		this->b    = e.b;
		printf("x'tor() %p %s: a=%d b=%d\n", this, name.c_str(), a, b);
	}

	element(string name, int a, int b)
	{
		this->name = name;
		this->a    = a;
		this->b    = b;
		printf("c'tor() %p %s: a=%d b=%d\n", this, name.c_str(), a, b);
	}

	virtual ~element()
	{
		printf("d'tor() %p %s: a=%d b=%d\n", this, name.c_str(), a, b);
	}

	inline bool operator()(const element& left,const element& right)
	{
		return left.a	 < right.a;
	}

	void print() const
	{
		printf("        %p %s: a=%d b=%d\n", this, name.c_str(), a, b);
	}
};

static set<element, element> elements;

static void test()
{
	printf("> test()\n");
	element a("Eins", 1,  2);
	element b("Zwei", 2,  3);
	element c("Drei", 3,  6);
	element d("Vier", 4, 12);
	element e("Eins", 1, 24);
	element f("Fünf", 5, 48);

	elements.insert(a);
	elements.insert(b);
	elements.insert(c);
	elements.insert(d);
	elements.insert(e);
	elements.insert(f);
	elements.emplace("Sechs", 6, 96);
	elements.emplace("Sieben", 3, 192);
	printf("< test()\n");
}

int main()
{
	printf(">>test()\n");
	test();
	printf("<<test()\n");

	for (const element &e : elements)
	{
		e.print();
	}

	printf(">>clear()\n");
	elements.clear();
	printf("<<clear()\n");
	return 0;
}
