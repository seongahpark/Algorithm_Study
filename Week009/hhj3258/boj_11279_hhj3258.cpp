#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 100001

class Heap
{
public:
    int *heap_arr = new int[MAX_SIZE];
    int heap_size = 0;

public:
    void push(int num);
    int top();
    void pop();
    int size();
};

void Heap::push(int num)
{
    int idx = ++heap_size; // 원소가 들어왔으니 size + 1
    heap_arr[idx] = num;   // 마지막 노드 다음 자리에 넣는다

    // 현재 루트노드가 아니고,
    // 부모 노드가 현재 노드보다 작은 값이라면
    while (idx != 1 && heap_arr[idx / 2] < num)
    {
        // 부모 노드와 현재 노드(자식 노드)를 바꿔준다.
        swap(heap_arr[idx / 2], heap_arr[idx]);
        // 현재 idx도 부모 노드의 idx로 바꿔준다.
        idx = idx / 2;
    }
}

void Heap::pop()
{
    // 루트 노드와 마지막 노드를 swap
    swap(heap_arr[1], heap_arr[heap_size]);
    // 삭제했으니 size - 1
    heap_size -= 1;

    int parent = 1; // 루트 노드
    int child;      // 자식 노드
    while (true)
    {
        // 자식 노드 idx = 부모 노드 idx * 2
        child = parent * 2;

        // 오른쪽 자식이 존재하고,
        // 왼쪽 자식 < 오른쪽 자식 이라면
        if ((child + 1 <= heap_size) && heap_arr[child] < heap_arr[child + 1])
        {
            // 오른쪽 자식과 부모를 바꿔주기 위해 child + 1
            child += 1;
        }

        // 자식의 idx가 힙의 사이즈보다 크거나,
        // 자식 노드 <= 부모 노드라면
        if ((child > heap_size) || heap_arr[child] <= heap_arr[parent])
            break; // 힙의 조건을 충족했으므로 종료한다.

        // 힙의 조건을 충족하지 못했다면,
        // 부모 노드와 자식노드의 값을 swap
        swap(heap_arr[parent], heap_arr[child]);

        // 부모 노드 idx(현재 노드 idx) 를 자식 노드 idx로 바꿔주고 반복.
        parent = child;
    }
}

int Heap::top()
{
    if (heap_size == 0)
        return 0;
    // 루트 노드를 반환한다.
    return heap_arr[1];
}

int Heap::size() { return heap_size; }

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Heap heap;

    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (num != 0)
        {
            heap.push(num);
        }
        else if (num == 0)
        {
            if (heap.size() == 0)
            {
                cout << heap.top() << '\n';
            }
            else
            {
                cout << heap.top() << '\n';
                heap.pop();
            }
        }
    }
}