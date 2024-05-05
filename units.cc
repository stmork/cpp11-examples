// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2024 Steffen A. Mork

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Frequency
{
	double value;

public:
	explicit constexpr Frequency(long double hz) : value(hz)
	{
	}

	void Print() const
	{
		cout << value << "Hz\n";
	}

	operator std::string () const
	{
		std::ostringstream strs;

		strs << value;
		return strs.str() + "Hz";
	}

	constexpr operator long double() const
	{
		return value;
	}
};

constexpr Frequency operator"" _Hz(unsigned long long hz)
{
	return Frequency{(long double)hz};
}

constexpr Frequency operator"" _Hz(long double hz)
{
	return Frequency{hz};
}

constexpr Frequency operator"" _kHz(unsigned long long khz)
{
	return Frequency{khz * 1000.0};
}

constexpr Frequency operator"" _kHz(long double khz)
{
	return Frequency{khz * 1000_Hz};
}

constexpr Frequency operator"" _MHz(long double mhz)
{
	return Frequency{mhz * 1000_kHz};
}

int main()
{
	Frequency(44100_Hz).Print();
	Frequency(44.1_kHz).Print();
	Frequency(0.0441_MHz).Print();

	const std::string & out = Frequency(48.0_kHz);

	cout << out << std::endl;
	return EXIT_SUCCESS;
}
