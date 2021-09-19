#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cin >> a >> b;
    
    int ra = 0, rb = 0;
    
    while (a) {
        ra *= 10;
        ra += a % 10;
        a /= 10;
        
        
        rb *= 10;
        rb += b % 10;
        b /= 10;
    }
    
    int min = ra < rb ? rb : ra;
    
    cout << min << '\n';
    
    return 0;
}
