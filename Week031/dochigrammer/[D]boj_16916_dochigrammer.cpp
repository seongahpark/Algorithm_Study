#include <iostream>
#include <string>
#include <vector>

class StringComparator
{
protected:
	std::vector<int> _string_pi;

public:
	bool IsSubString( const std::string& str, const std::string& sub_string)
	{
		CalcString_PI(str);

		int j = 0;
		for (int i = 0; i < str.length(); i++) 
		{
			while ((j > 0) && (str[i] != sub_string[j])) 
			{
				j = _string_pi[j - 1];
			}
			if (str[i] == sub_string[j]) 
			{
				if (j == sub_string.length() - 1) 
				{
					return true;
				}
				else
				{
					j++;
				}
			}
		}
		return false;
	}

	void CalcString_PI(const std::string& string)
	{
		int len = string.length();
		_string_pi.resize(len, 0);

		int j = 0;
		for (int i = 1; i < len; i++) 
		{
			while (string[i] != string[j] && j > 0)
			{
				j = _string_pi[j - 1];
			}

			if (string[i] == string[j])
			{
				++j;
				_string_pi[i] = j;
			}
		}
	}

};

int main()
{
	std::string str;
	std::string sub_str;

	std::cin >> str >> sub_str;

	StringComparator comparator;

	std::cout << comparator.IsSubString(str, sub_str);

	return 0;
}