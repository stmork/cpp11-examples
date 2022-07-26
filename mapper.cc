// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 Steffen A. Mork

#include <unordered_map>
#include <iostream>

class FlagMapper : protected std::unordered_map<uint32_t, std::string>
{
public:
	FlagMapper(std::initializer_list<std::pair<const uint32_t, std::string> > list) : std::unordered_map<uint32_t, std::string>(list)
	{

	}

	inline const std::string get(const uint32_t key)
	{
		std::unordered_map<uint32_t, std::string>::const_iterator it = find(key);

		return it != end() ? it->second : "Blah!";
	}
};

typedef FlagMapper flag_map;

flag_map mapper =
{
	{ 18, "Isabella" },
	{ 19, "Steffen" },
	{ 29, "Marion" }
};

using std::cout;
using std::endl;

int main()
{
	cout << mapper.get(18) << endl;
	cout << mapper.get(19) << endl;
	cout << mapper.get(29) << endl;
	cout << mapper.get(13) << endl;
}
