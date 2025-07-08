// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdio>
#include <iostream>
#include <set>
#include <stdexcept>
#include <cstdarg>
#include <cstring>
#include <fcntl.h>

class TestException : public std::runtime_error
{
public:
	explicit TestException(const std::string & text) : std::runtime_error(text)
	{
	}

};

static const std::string format(const char * message, ...)
{
	char buffer[1024];

	std::va_list args;

	va_start(args, message);
	std::vsnprintf(buffer, sizeof(buffer), message, args);
	va_end(args);

	std::string error(buffer);

	if (errno != 0)
	{
		const char * result = std::strerror(errno);

		if (result == nullptr)
		{
			std::perror("Unknown error while retrieving another error text");
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
	::open("asdfsdsdf", 0);
	throw TestException("Example 1");
}

void second()
{
	::open("asdfsdsdf", 0);
	throw TestException(format("Example %d", 2));
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
		std::fprintf(stderr, "Error: %s\n", e.what());
	}
	return 0;
}
