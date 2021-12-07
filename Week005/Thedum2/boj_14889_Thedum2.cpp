#include <iostream>
#include <vector>
using namespace std;

int fsize;
int result=4500000000;
bool check[21] = { false, };
int startlist[10];
int linklist[10];
int Field[21][21];

void dfs(int cur, int cnt) {
 
    if (cnt == fsize / 2) {
        int start = 0;
        int link = 0;

        int k = 0;
        for (int i = 1; i <= fsize; i++) {
            if (!check[i]) {
                linklist[k] = i;
                k++;
            }
        }

        for (int j = 0; j < fsize / 2; j++) {
            for (int k = 1; k <= fsize; k++) {
                if (startlist[j] != k && check[k]) {
                    start += Field[startlist[j]][k];
                }
                if (linklist[j] != k && !check[k]) {
                    link += Field[linklist[j]][k];
                }
            }
        }

        result = min(result, abs(link - start));
        return;
    }
    for (int i = cur + 1; i <=fsize; i++) {
        if (!check[i]) {
            check[i] = true;
            startlist[cnt] = i;
            dfs(i, cnt + 1);
            check[i] = false;
        }
    }
}

int main() {
	cin >> fsize;

	int cmd;
	for (int j = 1; j <= fsize; j++) 
		for (int i = 1; i <= fsize; i++) 
            cin >> Field[j][i];
		
    dfs(0, 0);
    cout << result;
}
