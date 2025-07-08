// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 - 2025 Steffen A. Mork

#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <type_traits>

#define PASCAL_STRING_LEN 256

typedef wchar_t StringType;

struct PascalString
{
	size_t     length = 0;
	StringType data[PASCAL_STRING_LEN];
};

template<typename T>
constexpr size_t ArrayCount(const T & array)
{
	return sizeof(array) / sizeof(array[0]);
}

template<typename T>
bool Copy(T & output, const std::string & input)
{
	static_assert(std::is_array<decltype(output.data)>::value == true, "Output data must be an array!");

	if (input.length() > std::extent_v<decltype(output.data)>)
	{
		return false;
	}

	std::transform(input.begin(), input.end(), output.data, [] (std::string::value_type c)
	{
		return c;
	});
	output.length = input.length();
	return true;
}

int main()
{
	PascalString pascal;

	Copy(pascal, "Example.");

	static_assert (ArrayCount(pascal.data) == PASCAL_STRING_LEN, "Pascal data length not correct.");
	static_assert (std::extent_v<decltype(pascal.data)> == PASCAL_STRING_LEN, "Pascal data length not correct.");

	std::wstring wide_string(pascal.data, pascal.data + pascal.length);

	for (size_t i = 0; i < pascal.length; ++i)
	{
		std::wcout << pascal.data[i];
	}
	std::wcout << std::endl;
	std::wcout << wide_string << std::endl;

	const size_t size = std::extent_v<decltype(pascal.data)>;

	std::wcout << L"Size:" << size << std::endl;

	return EXIT_SUCCESS;
}
