#include <iostream>  
#include <string.h>
using namespace std;

int V,E;
const int INTM = 9999999;
int map[401][401];

void Floyd_Warshall() {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}

int main() {

    cin >> V>>E;
    fill(&map[0][0], &map[400][401], INTM);

    int a,b,c;
    for (int i = 0; i <E; i++) {
        cin >> a >> b >> c;
        map[a][b] = c;
    }

   Floyd_Warshall();

   int result=INTM;
   for (int i = 1; i <= V; i++)
       result = min(result, map[i][i]);
   
   if (result == INTM) result= -1;
   cout << result << endl;
}
