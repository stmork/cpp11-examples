#include <stdlib.h>
#include <stdio.h>
#include <memory>

class S
{
public:
	static S & getInstance()
	{
		// Guaranteed to be destroyed.
		// Instantiated on first use.
		static S instance;

		printf("getInstance()\n");
		return instance;
	}

	inline S * getAddress()
	{
		return this;
	}

private:
	S()
	{
		printf("c'tor\n");
		// Constructor? (the {} brackets) are needed here.
	}

	virtual ~S()
	{
		printf("d'tor\n");
	}

public:
	// C++ 11
	// =======
	// We can use the better technique of deleting the methods
	// we don't want.
	S(S const&) = delete;
	void operator=(S const&) = delete;

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};

int main(
		[[gnu::unused]] int argc,
		[[gnu::unused]] char * argv [] )
{
	S & s1 = S::getInstance();
	S & s2 = S::getInstance();

	printf("s1: %p\n", s1.getAddress());
	printf("s2: %p\n", s2.getAddress());

	return EXIT_SUCCESS;
}
