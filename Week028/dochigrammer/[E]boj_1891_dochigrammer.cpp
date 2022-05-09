#include <iostream>
#include <iomanip>
#include <algorithm>

template <typename T>
struct Point
{
	T x;
	T y;

	Point()
		:x(0)
		, y(0)
	{

	}

	Point(T _x, T _y)
		:x(_x)
		, y(_y)
	{

	}

	Point<T> operator-(const Point<T>& other) const
	{
		Point<T> pt;
		pt.x = this->x - other.x;
		pt.y = this->y - other.y;

		return pt;
	}
	Point<T>& operator+=(const Point<T>& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}

	Point<T> operator*(const Point<T>& other) const
	{
		Point<T> pt;

		pt.x = this->x * other.x;
		pt.y = this->y * other.y;

		return pt;
	}
};

void CalcPos(Point<int64_t>& pos, std::string& number, int digit, int depth)
{
	int64_t divided_dist = ((int64_t)1 << depth);
	++depth;

	if (depth > digit)
	{
		return;
	}

	int idx = digit - depth;

	if (number[idx] == '1')
	{
		pos.x += divided_dist;
	}
	else if (number[idx] == '3')
	{
		pos.y -= divided_dist;
	}
	else if (number[idx] == '4')
	{
		pos.x += divided_dist;
		pos.y -= divided_dist;
	}

	CalcPos(pos, number, digit, depth);
}

// 8 / 2 -> 4
// 4,4 -> 4 
// x,y
// 2,2 -> 1, -1
// 1,1 -> 1, -1
// 1 2 -> 3 + 2 -> 5
// 2 4 -> -6 + 1 -> 5

void GetBounds(std::string& out_name, Point<int64_t>& pos, int digit, int depth)
{
	++depth;
	if (depth > digit)
	{
		return;
	}

	int64_t divided_dist = ((int64_t)1ll << (digit - depth));

	if (pos.x >= divided_dist && pos.y <= -divided_dist)
	{
		pos.x -= divided_dist;
		pos.y += divided_dist;

		out_name += "4";
	}
	else if (pos.x >= divided_dist)
	{
		pos.x -= divided_dist;

		out_name += "1";
	}
	else if (pos.y <= -divided_dist)
	{
		pos.y += divided_dist;

		out_name += "3";
	}
	else
	{
		out_name += "2";
	}

	GetBounds(out_name, pos, digit, depth);
}

int main()
{
	int digit;
	std::string number;

	std::cin >> digit >> number;

	Point<int64_t> move;
	std::cin >> move.x >> move.y;

	Point<int64_t> pos;
	// 사분면 나눈거 위치로 계산
	CalcPos(pos, number, digit, 0);

	// 위치에 더해서
	pos += move;

	int64_t max_dist = ((int64_t)1ll << digit);

	// 아웃오브 레인지면 땡
	if (pos.x < 0 || pos.x >= max_dist ||
		pos.y > 0 || pos.y <= -max_dist)
	{
		std::cout << -1;
		return 0;
	}

	std::string result;
	// 해당 위치에 해당하는 바운드들 추려내기
	GetBounds(result, pos, digit, 0);

	std::cout << result;

	return 0;
}