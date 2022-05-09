#include <iostream>
#include <iomanip>
#include <algorithm>

struct Point
{
	int x;
	int y;

	Point()
		:x(0)
		, y(0)
	{

	}

	Point(int _x, int _y)
		:x(_x)
		, y(_y)
	{

	}

	Point operator-(const Point& other) const
	{
		Point pt;
		pt.x = this->x - other.x;
		pt.y = this->y - other.y;

		return pt;
	}

	Point operator*(const Point& other) const
	{
		Point pt;

		pt.x = this->x * other.x;
		pt.y = this->y * other.y;

		return pt;
	}
};
struct Vector
{
	int x;
	int y;
	int z;

	Vector()
		:x(0)
		, y(0)
		, z(0)
	{


	}
	Vector(int _x, int _y, int _z)
		:x(_x)
		, y(_y)
		, z(_z)
	{
	}

	Vector operator-(const Vector& other)
	{
		Vector v;
		v.x = this->x - other.x;
		v.y = this->y - other.y;
		v.z = this->z - other.z;

		return v;
	}

	static Vector CrossProduct(const Vector& a, const Vector& b)
	{
		return Vector
		(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}
};

int CCW(const Point& pt_1, const Point& pt_2, const Point& pt_3)
{
	Point pt_dir_1 = pt_1 - pt_2;
	Point pt_dir_2 = pt_2 - pt_3;

	Vector v_dir_1(pt_dir_1.x, pt_dir_1.y, 0);
	Vector v_dir_2(pt_dir_2.x, pt_dir_2.y, 0);

	// 외적
	return Vector::CrossProduct(v_dir_1, v_dir_2).z;

	// ( 외적의 z값만 땐 방식 )
	// return (pt_2.x - pt_1.x) * (pt_3.y - pt_1.y) - (pt_3.x - pt_1.x) * (pt_2.y - pt_1.y);
}

int main()
{
	Point pt[3];

	for (int i = 0; i < 3; ++i)
	{
		std::cin >> pt[i].x >> pt[i].y;
	}

	int result = CCW(pt[0], pt[1], pt[2]);

	if (result > 0)
	{
		std::cout << 1;
	}
	else if (result < 0)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << 0;
	}

	return 0;
}