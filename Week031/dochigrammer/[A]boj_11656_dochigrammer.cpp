
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string input;
	std::cin >> input;

	int len = input.length();

	std::string* suffix_names = new std::string[len];

	for( int i =0; i < len; ++i)
	{ 
		suffix_names[i] = input.substr(i, len);
	}

	std::sort(suffix_names, suffix_names + len);

	for (int i = 0; i < len; ++i)
	{
		std::cout << suffix_names[i] << "\n";
	}

	delete[] suffix_names;

	return 0;
}