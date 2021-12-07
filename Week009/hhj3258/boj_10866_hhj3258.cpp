#include <iostream>
#include <string>

using namespace std;

#define SIZE 10001

class Deque
{
private:
    int *deque = new int[SIZE];
    int f = 0;    // 시작 인덱스
    int rear = 0; // 끝 인덱스
public:
    void push_front(int n);
    void push_back(int n);
    int pop_front();
    int pop_back();
    int size();
    bool empty();
    int front();
    int back();
};

void Deque::push_front(int n)
{
    if (size() == SIZE - 1) // 꽉 찼다면 return
        return;
    else
    {
        deque[f] = n;
        f = (f - 1 + SIZE) % SIZE; // 0,10000,9999 ...
    }
}

void Deque::push_back(int n)
{
    if (size() == SIZE - 1)
        return;
    else
    {
        rear = (rear + 1) % SIZE; // 1,2,3 ... 10000
        deque[rear] = n;
    }
}

int Deque::pop_front()
{
    if (empty())
        return -1;
    else
    {
        f = (f + 1) % SIZE; // front는 다음 빈 공간을 가리키고 있으므로 먼저 인덱스를 되돌린다.
        return deque[f];
    }
}

int Deque::pop_back()
{
    if (empty())
        return -1;
    else
    {
        int rear_temp = deque[rear]; // rear는 현재 값을 넣었던 공간을 가리키고 있으므로 일단 temp로 저장해준다.
        rear = (rear - 1 + SIZE) % SIZE;
        return rear_temp;
    }
}

int Deque::size()
{
    return (rear - f + SIZE) % SIZE;
}

bool Deque::empty()
{
    if (f == rear)
        return true;
    else
        return false;
}

int Deque::front()
{
    if (empty())
        return -1;
    else
        return deque[(f + 1) % SIZE]; // f 는 다음 빈 공간을 가리키고 있으므로...
}

int Deque::back()
{
    if (empty())
        return -1;
    else
        return deque[rear];
}

int main()
{
    Deque deque;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string cmd;
        int num;
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> num;
            deque.push_front(num);
        }
        else if (cmd == "push_back")
        {
            cin >> num;
            deque.push_back(num);
        }
        else if (cmd == "pop_front")
            cout << deque.pop_front() << '\n';
        else if (cmd == "pop_back")
            cout << deque.pop_back() << '\n';
        else if (cmd == "size")
            cout << deque.size() << '\n';
        else if (cmd == "empty")
            cout << deque.empty() << '\n';
        else if (cmd == "front")
            cout << deque.front() << '\n';
        else if (cmd == "back")
            cout << deque.back() << '\n';
    }
}