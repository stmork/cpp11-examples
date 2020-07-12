/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   STL excpeption example.
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
public:
	explicit TestException(const string & text) : std::runtime_error(text)
	{
	}

};

static const string format(const char * message, ...)
{
	char buffer[1024];

	va_list args;

	va_start(args, message);
	vsnprintf(buffer, sizeof(buffer), message, args);
	va_end(args);

	string error(buffer);

	if (errno != 0)
	{
		const char * result = strerror_r(errno, buffer, sizeof(buffer));

		if (result == nullptr)
		{
			perror("Unknown error while retrieving another error text");
		}
		else
		{
			error += ": ";
			error += result;
		}
	}
	return error;
}

void first()
{
	open("asdfsdsdf", 0);
	throw TestException("Beispiel 1");
}

void second()
{
	open("asdfsdsdf", 0);
	throw TestException(format("Beispiel %d", 2));
}

void intermediate1()
{
	first();
}

void intermediate2()
{
	second();
}

int main()
{
	try
	{
		intermediate2();
	}
	catch (std::runtime_error & e)
	{
		fprintf(stderr, "Fehler: %s\n", e.what());
	}
	return 0;
}
