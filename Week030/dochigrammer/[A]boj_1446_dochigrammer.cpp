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

		// 길이 아니라면 스킵
		if (road.dst > road_dist || road.dst < 0 ||
			road.src > road_dist || road.src < 0)
			continue;

		// 지름길이 아니라면 스킵
		if (road.dst - road.src < road.len)
			continue;

		// 지름길들을 시작 지점기준으로 정렬 & 담기
		roads.push(road);
	}

	std::map<int, int> road_map;
	int min_dist = road_dist;

	while (roads.empty() == false)
	{
		road = roads.top();
		roads.pop();

		int min_src_dist = road.src;

		// 현재 길에 시작 위치 기준으로 최소 길이를 구하기
		for (auto iter : road_map)
		{
			if (iter.first > road.src)
				break;

			min_src_dist = std::min(min_src_dist, iter.second + (road.src - iter.first));
		}

		// 해당 지름길의 목표치만큼 짧은 거리 계산
		int dist = min_src_dist + road.len;

		auto iter = road_map.find(road.dst);
		if (iter == road_map.end())
		{
			road_map[road.dst] = dist;
		}
		else
		{
			// 같은 길이 존재한다면 짧은 길로 변경
			road_map[road.dst] = std::min(road_map[road.dst], dist);
		}

		// 도착지점까지의 최소 거리를 계산
		min_dist = std::min(dist + (road_dist - road.dst), min_dist);
	}

	std::cout << min_dist;

	return 0;
}