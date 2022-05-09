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
int main()
{
	int test_case = 0;

	std::cin >> test_case;

	Point<int> pt[4];
	for (int i = 0; i < test_case; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cin >> pt[j].x >> pt[j].y;
		}

		float slope_1 = (float)(pt[1].y - pt[0].y) / (pt[1].x - pt[0].x);
		float slope_2 = (float)(pt[3].y - pt[2].y) / (pt[3].x - pt[2].x);

		float intercept_1 = (float)pt[0].y - slope_1 * pt[0].x;
		float intercept_2 = (float)pt[2].y - slope_2 * pt[2].x;

		if (slope_1 != slope_2)
		{
			std::cout << "POINT ";

			Vector v1(pt[0].x, pt[0].y, 1);
			Vector v2(pt[1].x, pt[1].y, 1);
			Vector v3(pt[2].x, pt[2].y, 1);
			Vector v4(pt[3].x, pt[3].y, 1);

			Vector result = Vector::CrossProduct(Vector::CrossProduct(v1, v2), Vector::CrossProduct(v3, v4));

			std::cout << std::fixed << std::setprecision(2)
				<< (float)result.x / (float)result.z << " "
				<< (float)result.y / (float)result.z
				<< '\n';


		}
		else if (intercept_1 == intercept_2)
		{
			std::cout << "LINE" << '\n';
		}
		else
		{
			std::cout << "NONE" << '\n';
		}
	}

	return 0;
}