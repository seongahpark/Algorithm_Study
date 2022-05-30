#include <iostream>
#include <queue>
#include <map>

struct Road
{
	int src;
	int dst;
	int len;

	bool operator<(const Road& other) const
	{
		return src > other.src;
	}
};


int main()
{
	int road_count, road_dist;
	std::cin >> road_count >> road_dist;
	std::priority_queue<Road> roads;

	Road road;

	for (int i = 0; i < road_count; ++i)
	{
		std::cin >> road.src >> road.dst >> road.len;

		// ���� �ƴ϶�� ��ŵ
		if (road.dst > road_dist || road.dst < 0 ||
			road.src > road_dist || road.src < 0)
			continue;

		// �������� �ƴ϶�� ��ŵ
		if (road.dst - road.src < road.len)
			continue;

		// ��������� ���� ������������ ���� & ���
		roads.push(road);
	}

	std::map<int, int> road_map;
	int min_dist = road_dist;

	while (roads.empty() == false)
	{
		road = roads.top();
		roads.pop();

		int min_src_dist = road.src;

		// ���� �濡 ���� ��ġ �������� �ּ� ���̸� ���ϱ�
		for (auto iter : road_map)
		{
			if (iter.first > road.src)
				break;

			min_src_dist = std::min(min_src_dist, iter.second + (road.src - iter.first));
		}

		// �ش� �������� ��ǥġ��ŭ ª�� �Ÿ� ���
		int dist = min_src_dist + road.len;

		auto iter = road_map.find(road.dst);
		if (iter == road_map.end())
		{
			road_map[road.dst] = dist;
		}
		else
		{
			// ���� ���� �����Ѵٸ� ª�� ��� ����
			road_map[road.dst] = std::min(road_map[road.dst], dist);
		}

		// �������������� �ּ� �Ÿ��� ���
		min_dist = std::min(dist + (road_dist - road.dst), min_dist);
	}

	std::cout << min_dist;

	return 0;
}