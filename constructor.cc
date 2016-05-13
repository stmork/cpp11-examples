/*
 * $Id$
 * $Author$
 */

#include <stdio.h>
#include <stdexcept>

class Constructor
{
public:
	Constructor()
	{
		printf("c'tor()\n");
		throw std::runtime_error("Exception absichtig geworfen!");
	}

	virtual ~Constructor()
	{
		printf("d'tor()\n");
	}
};

int main()
{
	Constructor object;

	return 0;
}
