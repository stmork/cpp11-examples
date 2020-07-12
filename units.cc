#include <iostream>
#include <stdlib.h>

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

	return EXIT_SUCCESS;
}
