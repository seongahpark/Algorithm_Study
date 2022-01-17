#include <iostream>  
#include <string.h>
using namespace std;

int N;
const int INTM = 9999999;
int map[102][102];

void Floyd_Warshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main() {

    cin >> N;
    fill(&map[0][0], &map[100][101], INTM);

    int input;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> input;
            if (input != 0) map[i][j] = input;
        }
    }

   Floyd_Warshall();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == INTM) 
                cout << 0 << " ";
            else 
                cout << 1 << " ";      
        }
        cout << "\n";
    }
}
