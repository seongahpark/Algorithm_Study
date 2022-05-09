#include <iostream>
#include <iomanip>
#include <algorithm>

struct Point
{
    int x;
    int y;

    Point()
        :x(0)
        ,y(0)
    {

    }

    Point(int _x, int _y)
        :x(_x)
        ,y(_y)
    {

    }

    Point operator-( const Point& other) const
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

int Max(int l, int r)
{
    if (l > r) return l;
    return r;
}

int GetArea(const Point& pt_1, const Point& pt_2, const Point& pt_3)
{
    //return abs((pt_1.y - pt_2.y) * (pt_3.x - pt_2.x) - (pt_1.x - pt_2.x) * (pt_3.y - pt_2.y));
    return abs(pt_1.x * pt_2.y + pt_2.x * pt_3.y + pt_3.x * pt_1.y - pt_2.x * pt_1.y - pt_3.x * pt_2.y - pt_1.x * pt_3.y);
}


int main()
{
    int count;
    std::cin >> count;

    Point* points = new Point[count];

    for (int i = 0; i < count; ++i)
    {
        std::cin >> points[i].x >> points[i].y;
    }

    int result = 0;

	// 각 삼각형들의 넓이를 전부 구해서 제일 큰값
    for (int idx = 0; idx < count; ++idx)
    {
        for (int sec_idx = idx + 1; sec_idx < count; ++sec_idx)
        {
            for (int trd_idx = sec_idx + 1; trd_idx < count; ++trd_idx)
            {
				
                int tri_area = GetArea(points[idx], points[sec_idx], points[trd_idx]);

                result = Max(result, tri_area);
            }
        }
    }

	// 인티저니까 2로 나눠도 .5
    if (result % 2)
    {
        printf("%d.5", result / 2);
    }
    else
    {
        printf("%d.0", result / 2);
    }

    delete[] points;
    
    return 0;
}
