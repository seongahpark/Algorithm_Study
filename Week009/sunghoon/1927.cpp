#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> heap;

void MinHeap(unsigned int input)
{
	/// 1) 입력값이 0이 아니라면 값을 push
	if (input != 0)
	{
		/// 1. 배열의 마지막에 넣음
		heap.push_back(input);

		/// 2. 자신의 위치를 찾아감
		int curIndex = heap.size() - 1;
		int parent = curIndex / 2;

		/// 3. 부모 노드가 있는지 체크
		while (parent > 0)
		{
			/// 부모 노드와 크기 비교
			// 부모가 더 크다면
			if (heap[parent] > heap[curIndex])
			{
				// 값을 바꿈
				swap(heap[parent], heap[curIndex]);
				curIndex = parent;
				parent = curIndex / 2;
			}
			/// 교체할 필요 없음
			else
			{
				// 중단
				break;
			}
		}
	}
	/// 2) 입력값이 0이라면 pop
	else
	{
		/// 1. heap에 데이터가 있다면
		if (heap.size() > 1)
		{
			/// 2. 맨위 제거
			cout << heap[1] << "\n";
			// 마지막 요소를 첫번째로 가져옴
			heap[1] = heap[heap.size() - 1];
			// 마지막 요소 진짜로 지움.
			heap.erase(heap.end() - 1);
			// 인덱스 
			int curIndex = 1;
			int child = curIndex * 2;
			/// 3. 자식이 존재하지 않을때까지 반복
			while (heap.size() > child)
			{
				// 자식의 오른쪽까지 모두 있다면
				if (heap.size() > child + 1)
				{
					// 자식의 더 작은것을 찾음
					child = (heap[child] < heap[child + 1]) ? child : child + 1;
					// 자식이 더 작다면 교체
					if (heap[curIndex] > heap[child])
					{
						swap(heap[curIndex], heap[child]);
						curIndex = child;
						child = curIndex * 2;
					}
					else
					{
						// 중단!
						break;
					}
				}
				// 자식의 왼쪽만 있다면
				else
				{
					// 자식이 더 작다면 교체
					if (heap[curIndex] > heap[child])
					{
						swap(heap[curIndex], heap[child]);
					}
					// 중단
					break;
				}
			}
		}
		// heap에 데이터가 없음
		else
		{
			cout << "0\n";
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int size = 0;
	cin >> size;

	heap.reserve(size);
	heap.push_back(0); // [0] 인덱스는 사용안함

	unsigned int input;

	for (int i = 0; i < size; ++i)
	{
		cin >> input;
		MinHeap(input);
	}
	return 0;
}
