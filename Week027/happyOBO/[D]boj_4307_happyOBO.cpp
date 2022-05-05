#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 충돌 고려 X
    int T;
    cin >> T;
    int length, N;
    int dist,mxDist, mdDist, maxDistance, midDistance;
    maxDistance = INT_MIN;
    midDistance = INT_MIN;
    while (T--)
    {
        maxDistance = INT_MIN;
        midDistance = INT_MIN;
        cin >> length >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> dist;
            mxDist = max(length - dist, dist);
            mdDist = min(length - dist, dist);
            maxDistance = max(mxDist, maxDistance);
            midDistance = max(mdDist, midDistance);
        }


        cout << midDistance << " " << maxDistance << "\n";
    }

    return 0;
}
