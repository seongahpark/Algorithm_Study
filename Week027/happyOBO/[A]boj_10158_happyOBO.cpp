#include <bits/stdc++.h>

using namespace std;


int getPos(int wh, int mod, int rem);


int main() {
    int w, h;
    int x, y, t;
    int modW, remW, modH, remH;
    cin >> w >> h;
    cin >> x >> y;
    cin >> t;

    modW = (t + x) / w;
    remW = (t + x) % w;
    modH = (t + y) / h;
    remH = (t + y) % h;

    
    cout << getPos(w, modW, remW) << " " << getPos(h, modH, remH);

    return 0;
}


int getPos(int wh, int mod, int rem)
{
    if (mod % 2 == 0)
        return rem;
    else
        return wh - rem;
}
   