// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2024 Steffen A. Mork

#include <array>
#include <cstdio>
#include <cstdlib>

// See: https://godbolt.org

constexpr int square(int num)
{
	return num * num;
}

int main()
{
	constexpr int         size = 10;
	static constexpr auto a    = []
	{
		std::array < int, size + 1 > a{};

		for (int i = 0; i <= size; ++i)
		{
			a[i] = square(i);
		}
		return a;
	}();

	constexpr int s = a[3];
	printf("%d %d\n", s, a[5]);

	return EXIT_SUCCESS;
}
