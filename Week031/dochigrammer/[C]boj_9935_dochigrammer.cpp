#include <iostream>
#include <string>

class StringBomber
{
protected:
	const static int MAX_SIZE = 1000001;
	const static char READER_EOF = '\0';

	const char* EMPTY_WORD = "FRULA";

	std::string _input;
	std::string _filter_word;
	
	char _results[MAX_SIZE] = { READER_EOF };
	int _result_idx = 0;

public:
	void Read()
	{
		std::cin >> _input;
		std::cin >> _filter_word;
	}

	void Bomb()
	{
		_result_idx = 0;

		for (auto curr_char : _input)
		{
			_results[_result_idx++] = curr_char;

			if (curr_char == _filter_word.back() &&
				_result_idx >= _filter_word.length())
			{
				bool is_equals = true;
				int word_len = _filter_word.length();

				for (int i = 0; i < word_len; ++i)
				{
					if (_filter_word[i] != _results[_result_idx - word_len + i])
					{
						is_equals = false;
						break;
					}
				}

				if (is_equals)
				{
					_result_idx -= _filter_word.length();
				}
			}
		}

		_results[_result_idx] = READER_EOF;
	}

	const char* GetResult() const
	{
		if (_result_idx <= 0)
		{
			return EMPTY_WORD;
		}

		return _results;
	}

};

int main()
{
	StringBomber bomber;

	bomber.Read();
	bomber.Bomb();

	std::cout << bomber.GetResult();

	return 0;
}