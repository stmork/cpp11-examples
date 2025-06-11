// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2025 Steffen A. Mork

#include <iostream>
#include <queue>

class Example
{
	std::string text;

public:
	explicit Example(const std::string & input) : text(input)
	{
		std::cout << "c'tor() " << text << std::endl;
	}

	virtual ~Example()
	{
		std::cout << "d'tor() " << text << std::endl;
	}
};

int main()
{
	std::queue<Example> queue;

	queue.emplace("a");
	queue.emplace("b");
	queue.emplace("c");
	queue.emplace("d");

	std::cout << "-----" << std::endl;
	queue.pop();
	std::cout << "-----" << std::endl;
	queue.pop();
	std::cout << "=====" << std::endl;

	return EXIT_SUCCESS;
}
