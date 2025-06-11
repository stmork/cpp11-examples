// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdio>
#include <cstdlib>
#include <string>

int main()
{
	std::string text("Abbbcde");

	printf("%p\n", &text);
	printf("%s %p\n",  text.c_str(),  text.c_str());
	printf("%s %p\n",  text.data(),   text.data());
	printf("%s %p\n", &text.front(), &text.front());

	return EXIT_SUCCESS;
}
