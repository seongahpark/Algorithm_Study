#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> heap;

void MinHeap(unsigned int input)
{
	/// 1) �Է°��� 0�� �ƴ϶�� ���� push
	if (input != 0)
	{
		/// 1. �迭�� �������� ����
		heap.push_back(input);

		/// 2. �ڽ��� ��ġ�� ã�ư�
		int curIndex = heap.size() - 1;
		int parent = curIndex / 2;

		/// 3. �θ� ��尡 �ִ��� üũ
		while (parent > 0)
		{
			/// �θ� ���� ũ�� ��
			// �θ� �� ũ�ٸ�
			if (heap[parent] > heap[curIndex])
			{
				// ���� �ٲ�
				swap(heap[parent], heap[curIndex]);
				curIndex = parent;
				parent = curIndex / 2;
			}
			/// ��ü�� �ʿ� ����
			else
			{
				// �ߴ�
				break;
			}
		}
	}
	/// 2) �Է°��� 0�̶�� pop
	else
	{
		/// 1. heap�� �����Ͱ� �ִٸ�
		if (heap.size() > 1)
		{
			/// 2. ���� ����
			cout << heap[1] << "\n";
			// ������ ��Ҹ� ù��°�� ������
			heap[1] = heap[heap.size() - 1];
			// ������ ��� ��¥�� ����.
			heap.erase(heap.end() - 1);
			// �ε��� 
			int curIndex = 1;
			int child = curIndex * 2;
			/// 3. �ڽ��� �������� ���������� �ݺ�
			while (heap.size() > child)
			{
				// �ڽ��� �����ʱ��� ��� �ִٸ�
				if (heap.size() > child + 1)
				{
					// �ڽ��� �� �������� ã��
					child = (heap[child] < heap[child + 1]) ? child : child + 1;
					// �ڽ��� �� �۴ٸ� ��ü
					if (heap[curIndex] > heap[child])
					{
						swap(heap[curIndex], heap[child]);
						curIndex = child;
						child = curIndex * 2;
					}
					else
					{
						// �ߴ�!
						break;
					}
				}
				// �ڽ��� ���ʸ� �ִٸ�
				else
				{
					// �ڽ��� �� �۴ٸ� ��ü
					if (heap[curIndex] > heap[child])
					{
						swap(heap[curIndex], heap[child]);
					}
					// �ߴ�
					break;
				}
			}
		}
		// heap�� �����Ͱ� ����
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
	heap.push_back(0); // [0] �ε����� ������

	unsigned int input;

	for (int i = 0; i < size; ++i)
	{
		cin >> input;
		MinHeap(input);
	}
	return 0;
}
