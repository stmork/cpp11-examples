// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 Steffen A. Mork

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstdint>

static constexpr float threehalfs = 1.5F;

/*
 * https://en.wikipedia.org/wiki/Fast_inverse_square_root
 */

float Q_rsqrt( float number )
{
	long  i;
	float x2, y;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

union FloatBits
{
	float    f;
	int32_t  i;
};

float SM_rsqrt(const float number)
{
	float     x2;
	FloatBits fb{.f = number};

	x2   = number * 0.5F;
	fb.i = 0x5f3759df - (fb.i >> 1);                   // what the fuck?
	fb.f = fb.f * (threehalfs - (x2 * fb.f * fb.f));   // 1st iteration
	fb.f = fb.f * (threehalfs - (x2 * fb.f * fb.f));   // 2nd iteration, this can be removed

	return fb.f;
}

constexpr float rsqrt(const float input)
{
	return 1.0 / sqrt(input);
}

int main(int argc, char * argv [])
{
	for (int i = 1; i < argc; i++)
	{
		const float     value = atof(argv[i]);
		const FloatBits bits { .f = value };

		printf("%2.5f = 0x%08x:  %2.5f  %2.5f  %2.5f\n",
			bits.f, bits.i,
			rsqrt(value), Q_rsqrt(value), SM_rsqrt(value));
	}
	return EXIT_SUCCESS;
}
