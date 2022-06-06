#include <iostream>
#include <string>
#include <deque>

class StringParser
{
protected:
	std::deque<int> _deque_entries;

	bool _is_reversed = false;
public:
	void Parse(std::string _input)
	{
		for (auto curr_char : _input)
		{
			if (curr_char != '[' &&
				curr_char != ',')
			{
				_deque_entries.push_back((int)curr_char);
			}
		}
	}

	void Reverse()
	{
		_is_reversed = !_is_reversed;
	}

	void Delete()
	{
		if (_is_reversed)
		{
			_deque_entries.pop_back();
		}
		else
		{
			_deque_entries.pop_front();
		}
	}

	void Finalization(std::string& _out_results)
	{
		_out_results = "[";

		while (_deque_entries.empty() == false)
		{
			int num = 0;
			if (_is_reversed)
			{
				num = _deque_entries.back();
				_deque_entries.pop_back();
			}
			else
			{
				num = _deque_entries.front();
				_deque_entries.pop_front();
			}

			_out_results += num;
			_out_results += ",";
		}

		_out_results.erase(_out_results.end()--);
		_out_results += "]";
	}

};

int main()
{
	int test_case = 0;
	std::cin >> test_case;

	for (; test_case > 0; --test_case)
	{
		std::string command;
		std::cin >> command;

		int entry_count = 0;
		std::cin >> entry_count;

		std::string entries;
		std::cin >> entries;

		StringParser parser;
		parser.Parse(entries);

		for (int i = 0; i < command.length(); ++i)
		{
			switch (command[i])
			{
			case 'R':
				parser.Reverse();
				break;

			case 'D':
				parser.Delete();
				break;
			}
		}

		std::string result;
		parser.Finalization(result);

		std::cout << result;
	}

	return 0;
}