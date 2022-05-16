#include <bits/stdc++.h>

using namespace std;

struct Puzzle;

void bfs(Puzzle start);

const int SIZE = 3;

pair<int, int> Directions[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };


struct Puzzle
{
    char board[SIZE][SIZE] = {};
    static set<int> visited;
   
    pair<int, int> zero;

    int moved = 0;

    void input()
    {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
            {
                cin >> board[i][j];
                if (board[i][j] == '0')
                    zero = { i,j };
            }

        isVisited(this);

    }

    bool Move(pair<int,int>& dir)
    {
        pair<int, int> to = { zero.first + dir.first , zero.second + dir.second };
        if (to.first < 0 || SIZE <= to.first)
            return false;
        if (to.second < 0 || SIZE <= to.second)
            return false;
        swap(board[zero.first][zero.second], board[to.first][to.second]);
        zero = to;
        moved++;
        return true;
    }

    void unMove(pair<int, int>& dir)
    {
        pair<int, int> to = { zero.first + dir.first * -1 , zero.second + dir.second * -1};
        swap(board[zero.first][zero.second], board[to.first][to.second]);
        zero = to;
        moved--;
    }

    static bool isVisited(Puzzle* pz)
    {
        int r, c, key = 0;
        int multiple = 1;
        for (int i = 0; i < SIZE * SIZE; i++)
        {
            r = i / SIZE;
            c = i % SIZE;
            key += (pz->board[r][c] - '0') * multiple;
            multiple *= 10;
        }

        if (visited.find(key) == visited.end())
        {
            visited.insert(key);
            return false;
        }
        else
        {
            return true;
        }

    }

    static bool isSorted(Puzzle* pz)
    {
        int r, c = 0;

        for (int i = 0; i < SIZE * SIZE -1; i++)
        {
            r = i / SIZE;
            c = i % SIZE;
            if ((pz->board[r][c] - '0') != i + 1)
                return false;
        }

        return true;
    }

};

set<int> Puzzle::visited;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Puzzle pz;
    pz.input();

    bfs(pz);

    return 0;
}

void bfs(Puzzle start)
{
    queue<Puzzle> q;

    if (Puzzle::isSorted(&start))
    {
        cout << start.moved;
        return;
    }
    q.push(start);

    Puzzle curr;
    pair<int, int> to;
    while (!q.empty())
    {
        curr = q.front(); q.pop();

        
        for (auto& dir : Directions)
        {
            if (curr.Move(dir))
            {
                if (Puzzle::isSorted(&curr))
                {
                    cout << curr.moved;
                    return;
                }

                if (!Puzzle::isVisited(&curr))
                {
                    q.push(curr);
                }
                curr.unMove(dir);
            }
        }
    }

    cout << -1;
}