#include <bits/stdc++.h>


using namespace std;

struct Vector;
void solution(Vector v1, Vector v2);
Vector crossProduct(Vector v1, Vector v2);

struct Vector
{
	Vector(int x, int y, int z)
	{
		X = x;
		Y = y;
		Z = z;
	}
	int X;
	int Y;
	int Z;
};

int main()
{
	pair<int, int> p1, p2, p3;
	cin >> p1.first >> p1.second;
	cin >> p2.first >> p2.second;
	cin >> p3.first >> p3.second;

	Vector v1 = Vector(p2.first - p1.first, p2.second - p1.second, 0);
	Vector v2 = Vector(p2.first - p3.first, p2.second - p3.second, 0);

	solution(v1, v2);
}


void solution(Vector v1, Vector v2)
{
	Vector result = crossProduct(v1, v2);
	if (result.Z > 0) cout << -1;
	else if (result.Z < 0) cout << 1;
	else cout << 0;
}

Vector crossProduct(Vector v1, Vector v2)
{
	return Vector(
		v1.Y * v2.Z - v2.Y * v1.Z,
		v1.Z * v2.X - v2.Z * v1.X,
		v1.X * v2.Y - v2.X * v1.Y
	);

}
