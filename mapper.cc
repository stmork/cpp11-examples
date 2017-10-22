/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   STL container reference behaviour.
 */

#include <unordered_map>
#include <iostream>

class FlagMapper
{
	std::unordered_map<uint32_t, std::string> map;

public:
	FlagMapper(std::initializer_list<std::pair<const uint32_t, std::string> > list) : map(list)
	{

	}

	inline const std::string get(uint32_t key)
	{
		std::unordered_map<uint32_t, std::string>::const_iterator it = map.find(key);

		return it != map.end() ? it->second : "Blah!";
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
