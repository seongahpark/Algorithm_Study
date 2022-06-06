
#include <iostream>
#include <string>
#include <algorithm>


class StringReader
{
protected:
	const static int MAX_SIZE = 100001;
	const static char READER_EOF = '\0';
	const static char SPACING = ' ';
	const static char OPEN_BRACKET = '<';
	const static char CLOSE_BRACKET = '>';

	char _sz_buf[MAX_SIZE] = { READER_EOF };
	int  _word_len = 0;
public:
	void Read()
	{
		std::cin.getline(_sz_buf, sizeof(_sz_buf));
	}

	void ReverseWord()
	{
		char curr_char;
		bool is_ignored = false;
		_word_len = 0;

		for(int idx = 0; idx < MAX_SIZE; ++idx)
		{
			curr_char = _sz_buf[idx];

			switch(curr_char)
			{
			case OPEN_BRACKET:
				is_ignored = true;
				Swap(&_sz_buf[idx - _word_len]);
				break;

			case CLOSE_BRACKET:
				is_ignored = false;
				break;

			case SPACING:
				Swap(&_sz_buf[idx - _word_len]);
				break;

			case READER_EOF:
				Swap(&_sz_buf[idx - _word_len]);
				return;

			default:
				if (is_ignored == false)
				{
					++_word_len;
				}
			}

		}
	}

	const char* GetString() const
	{
		return _sz_buf;
	}

protected:
	void Swap(char* start)
	{
		int idx = 0;

		for(int idx = 0; idx * 2 < _word_len; ++idx)
		{
			int rhs_idx = _word_len - idx - 1;

			char temp = start[idx];
			start[idx] = start[rhs_idx];
			start[rhs_idx] = temp;
		}

		_word_len = 0;
	}
};


int main()
{
	StringReader Reader;

	Reader.Read();
	Reader.ReverseWord();

	std::cout << Reader.GetString();

	return 0;
}