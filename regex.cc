// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: Copyright (C) 2022 Steffen A. Mork

#include <iostream>
#include <regex>

using namespace std;

class Parser
{
	std::regex regex;

public:
	Parser(const string & pattern) : regex(pattern, regex_constants::ECMAScript)
	{
	}

	void Search(const string & input) const
	{
		smatch matcher;

		if (regex_search(input, matcher, regex))
		{
			cout << "Found:     " << input << endl;
		}
		else
		{
			cout << "Not found: " << input << endl;
		}
	}

	void Match(const string & input) const
	{
		smatch matcher;

		if (regex_match(input, matcher, regex))
		{
			cout << "Found " << matcher.size() << " matches." << endl;
			for(size_t i = 0; i < matcher.size(); i++)
			{
				cout << "   " << matcher[i] << endl;
			}
		}
		else
		{
			cout << "No match: " << input << endl;
		}
	}

	void SearchMatch(const string & input) const
	{
		cout << "========= Input: " << input << endl;
		Search(input);
		Match(input);
	}
};

#if 0
const string REGEX(":[0..9a..fA..F]{2}");
#else
const string REGEX(":[[:xdigit:]]{2}$");
#endif

int main()
{
	try
	{
		Parser parser(REGEX);

		parser.Search("BB");
		parser.Search(":AA");
		parser.Search(":aa");
		parser.Search(":AX");
		parser.Search(":12");
		parser.Search(":11 22 33 AB XX");
		parser.Search(":11 cd 33 AB f8");
		parser.Search(":11 22 33\n");

		// https://regex101.com/
		Parser rtpmap(R"(^(\d{1,3})\s+(\w+)\/(\d+))");
	
		rtpmap.SearchMatch("123 PCMU/8000");
 		rtpmap.SearchMatch("123 PCMU/80x00");
 		rtpmap.SearchMatch("123 2PCMU/8000");
	}
	catch (const regex_error & e)
	{
		cout << "regex_error caught: " << e.what() << endl;

		if (e.code() == std::regex_constants::error_brack)
		{
			cout << "The code was error_brack\n";
		}
	}
	return 0;
}
