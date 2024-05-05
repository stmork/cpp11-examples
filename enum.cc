// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2024 Steffen A. Mork

#include <cstdio>
#include <cstdint>
#include <string>

enum Unscoped : char
{
	ZERO, ONE, TWO, THREE, MINUS_ONE = -1
};

enum struct Scoped : unsigned
{
	ZERO, ONE, TWO, THREE
};

int main()
{
	Scoped sd0   = Scoped::ZERO;
	Scoped sd2   = Scoped::TWO;
	Unscoped ud0 = Unscoped::ZERO;
	Unscoped ud2 = Unscoped::TWO;

	unsigned uu0 = ud0;
	unsigned uu2 = ud2;
	unsigned uum = Unscoped::MINUS_ONE;
	signed   us0 = ud0;
	signed   us2 = ud2;
	signed   usm = Unscoped::MINUS_ONE;
	unsigned su0 = (unsigned) sd0;
	unsigned su2 = (unsigned) sd2;

	printf("Enums: %u %u %u\n", uu0, uu2, uum);
	printf("Enums: %d %d %d\n", us0, us2, usm);
	printf("Enums: %u %u\n", su0, su2);
}
