// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2025 Steffen A. Mork

#include <cstdlib>
#include <format>
#include <string>
#include <iostream>

int main()
{
	const std::string fmt = std::format("Format: u:{} f:{} s:{}", 8u, 3.5f, "Hello!");

	std::cout << fmt << std::endl;

	return EXIT_SUCCESS;
}
