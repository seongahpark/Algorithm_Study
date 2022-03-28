#include <iostream>
#include <climits>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

void solution(vector<string>& ids, map<string,int>& inputs, map<string,int>& outputs);

map<string,bool> visited;

int main() {
    map<string,int> inputs, outputs;
    vector<string> ids;
    int N, counter = 0;
    cin >> N;
    for(int i = 0; i < N;i++)
    {
        string id;
        cin >> id;
        inputs[id] = i;
        visited[id] = false;
        ids.push_back(id);
    }
    for(int i = 0; i < N; i++)
    {
        string id;
        cin >> id;
        outputs[id] = i;
    }

    solution(ids, inputs, outputs);
    return 0;
}


void solution(vector<string>& ids, map<string,int>& inputs, map<string,int>& outputs)
{
    int counter = 0;
    for(auto& id : ids)
    {
        for(auto& id2 : ids)
        {
            if(id == id2) continue;
            if(visited[id2]) continue;
            if(inputs[id] < inputs[id2] && outputs[id] > outputs[id2])
            {
                visited[id2] = true;
                counter++;
            }

        }
    }

    cout << counter;
}