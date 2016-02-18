/*
 * $Id$
 * $Author$
 */

#include <stdio.h>
#include <iostream>
#include <set>
#include <stdexcept>
#include <cstdarg>
#include <string.h>
#include <fcntl.h>

using namespace std;

class TestException : public std::runtime_error
{
	char    error[1024];

public:
	explicit TestException(const char* message, ...) : std::runtime_error(error)
	{
		va_list args;

		va_start(args, message);
		vsnprintf(error, sizeof(error), message, args);
		va_end(args);

		if (errno != 0)
		{
			char    buffer[1024];

			const char *result = strerror_r(errno, buffer, sizeof(buffer));

			if (result == nullptr)
			{
				perror("Unknown error while retrieving another error text");
			}
			else
			{
				strncat (error, ": ", sizeof(error));
				strncat (error, result, sizeof(error));
			}
		}
	}

	virtual const char *what() const throw()
	{
		return error;
	}
};

void first()
{
	open("asdfsdsdf", 0);
	throw TestException("Beispiel");
}

void intermediate()
{
	first();
}

int main()
{
	try
	{
		intermediate();
	}
	catch(std::runtime_error &e)
	{
		fprintf(stderr, "Fehler: %s\n", e.what());
	}
	return 0;
}
