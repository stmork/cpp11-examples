// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdlib>
#include <cstdio>
#include <functional>

using namespace std::placeholders;

static double add(const double a, const double b)
{
	std::printf("add()\n");
	return a + b;
}

static double mul(const double a, const double b)
{
	std::printf("mul()\n");
	return a * b;
}

struct Callbacks
{
	double (*adder)(const double, const double);
	double (*multiplier)(const double, const double);
};

class Proxy
{
public:
	void registerCallbacks(Callbacks & funcs)
	{
		std::printf("register() = %p\n", this);

		static auto local_adder      = std::bind(&Proxy::add, this, _1, _2);
		static auto local_multiplier = std::bind(&Proxy::mul, this, _1, _2);

		funcs.adder = [](const double a, const double b)
		{
			return local_adder(a, b);
		};

		funcs.multiplier = [](const double a, const double b)
		{
			return local_multiplier(a, b);
		};
	}

	double add(const double a, const double b)
	{
		std::printf("Proxy::add() = %p\n", this);
		return a + b;
	}

	double mul(const double a, const double b)
	{
		std::printf("Proxy::mul() = %p\n", this);
		return a * b;
	}
};

int main()
{
	Callbacks funcs { ::add, ::mul };
	Callbacks refs;
	Proxy     proxy;

	std::printf("%lf\n", funcs.adder(1.0, 2.5));
	std::printf("%lf\n", funcs.multiplier(1.0, 2.5));

	proxy.registerCallbacks(refs);

	std::printf("%lf\n", refs.adder(-1.0, 2.5));
	std::printf("%lf\n", refs.multiplier(-1.0, 2.5));

	return EXIT_SUCCESS;
}
