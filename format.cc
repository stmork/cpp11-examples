// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2025 Steffen A. Mork

#include <cstdlib>
#include <format>
#include <string>
#include <iostream>

struct Example
{
	int x = 19;
	int y = 12;
};

#if defined(__cpp_lib_format)
template <>
struct std::formatter<Example> : std::formatter<std::string>
{
	auto format(const Example & input, format_context & context) const
	{
		return formatter<string>::format(
				std::format("({}, {})", input.x, input.y), context);
	}
};
#endif

int main()
{
#if defined(__cpp_lib_format)
	Example example;

	const std::string fmt = std::format("Format: u:{} f:{} s:{} Ex:{}", 8u, 3.5f, "Hello!", example);

	std::cout << fmt << std::endl;
#else
#warning "No std::format available."
#endif

	return EXIT_SUCCESS;
}
