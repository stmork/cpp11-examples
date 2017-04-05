/**
 * @file    $Id$
 * @version $Revision$
 * @date    $Date$
 * @author  $Author$
 * @brief   STL container reference behaviour.
 */

#include <stdio.h>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class element
{
	string name;
	int    a;
	int    b;

public:
	element()
	{
		a = 0;
		b = 0;
		printf("c'tor() %p\n", this);
	}

	element(const element & e)
	{
		this->name = e.name;
		this->a    = e.a;
		this->b    = e.b;
		printf("x'tor() %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
	}

	element(element && e)
	{
		this->name = std::move(e.name);
		this->a    = std::move(e.a);
		this->b    = e.b;
		e.b = 0;
		printf("m'tor() %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
	}

	element(string name, int a, int b)
	{
		this->name = name;
		this->a    = a;
		this->b    = b;
		printf("c'tor() %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
	}

	virtual ~element()
	{
		printf("d'tor() %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
	}

	element &operator=(element && other)
	{
		name = std::move(other.name);
		a = other.a;
		b = other.b;
		printf("m=op()  %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
		return *this;
	}

	inline size_t operator()(const element & x) const noexcept
	{
		return x.a;
	}

	inline bool operator()(const element& left,const element& right)
	{
		return left.a == right.a;
	}

	void print() const
	{
		printf("        %p %s: a=%d b=%d name=%p\n",
				this, name.c_str(), a, b, name.c_str());
	}
};

static set<element, element> elements;
static unordered_set<int> numbers;

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
	elements.insert(std::move(f));
	elements.insert(element("Neun", 9, 92));
	elements.emplace("Sechs (empl)", 6, 96);
	elements.emplace("Sieben (empl)", 3, 192);
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
