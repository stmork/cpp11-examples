/**
 * $Id$
 * $Revision$
 * $Date$
 * $Author$
 * @brief   STL regular expression example.
 */

#include <iostream>
#include <regex>

using namespace std;

class Parser
{
	static const string REGEX;

public:
	void Parse(const string input) const
	{
		regex  pattern(REGEX, regex_constants::ECMAScript);
		smatch matcher;

		if (regex_search(input, matcher, pattern))
		{
			cout << "Match:    " << input << endl;
		}
		else
		{
			cout << "No match: " << input << endl;
		}
	}
};

const string Parser::REGEX(":[0..9a..fA..F]{2}");

int main()
{
	try
	{
		Parser parser;

		parser.Parse("BB");
		parser.Parse(":AA");
		parser.Parse(":11 22 33 AB XX");
		parser.Parse(":11 cd 33 AB f8");
		parser.Parse(":11 22 33\n");
	}
	catch (const regex_error &e)
	{
		cout << "regex_error caught: " << e.what() << endl;

		if (e.code() == std::regex_constants::error_brack)
		{
			cout << "The code was error_brack\n";
		}
	}
	return 0;
}
