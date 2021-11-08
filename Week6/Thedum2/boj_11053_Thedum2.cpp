#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> Array;
    vector<int> DpArray;
    Array.push_back(0);
    DpArray.push_back(0);

    int size;
    cin >> size;

    int cmd;
    for (int i = 0; i < size; i++) {
        cin >> cmd;
        Array.push_back(cmd);
        DpArray.push_back(0);
    }
    int min = 0, max = 0;
    for (int i =1; i <= size; i++) {
        min = 0;
        for (int j = 0; j < i; j++) {
            if (Array[i] > Array[j]) {
                if (min < DpArray[j])
                    min = DpArray[j];
            }
            DpArray[i] = min + 1;
            if (max < DpArray[i])
                max = DpArray[i];
        }
    }
    cout << max << endl;
}