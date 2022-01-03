#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, R, C;
int result = 0;

void ZSearch(int a,int b, int size) {
	if (a == R && b == C) {
		cout << result << endl;
		return;
	}

    if (R< a + size && R >= a && C< b + size && C>= b)
    {
        ZSearch(a, b, size / 2);
        ZSearch(a, b + size / 2, size / 2);
        ZSearch(a + size / 2, b, size / 2);
        ZSearch(a + size / 2, b + size / 2, size / 2);
    }
    else
        result += size * size;
    
}

int main()
{
	cin >> N >> R >> C;
    ZSearch(0, 0, pow(2,N));
}