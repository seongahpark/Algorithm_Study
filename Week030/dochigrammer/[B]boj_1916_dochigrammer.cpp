#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Bus
{
	int src;
	int dst;
	int cost;

};

struct RoadCost
{
	int cost = 0;
	int pos = 0;

	bool operator<(const RoadCost& other) const
	{
		return cost > other.cost;
	}

	RoadCost()
	{

	}

	RoadCost(int _cost, int _pos)
		:cost(_cost)
		, pos(_pos)
	{

	}
};

class CostCalculator
{
	const static unsigned int MAX_SIZE = 1000;
	const static unsigned int MAX_INT = 2147483647;

protected:
	int costs[MAX_SIZE][MAX_SIZE];

public:
	CostCalculator()
	{
		for (int i = 0; i < MAX_SIZE * MAX_SIZE; ++i)
			costs[0][i] = MAX_INT;
	}

	void AddRoad(const Bus& bus)
	{
		costs[bus.src - 1][bus.dst - 1] = std::min(costs[bus.src - 1][bus.dst - 1], bus.cost);
	}

	int CalcMinimumCost(int src, int dst)
	{
		--src;
		--dst;

		int min_costs[MAX_SIZE];

		for (int i = 0; i < MAX_SIZE; ++i)
			min_costs[i] = MAX_INT;

		min_costs[src] = 0;

		std::priority_queue<RoadCost> queue;

		queue.push(RoadCost(0, src));

		while (queue.empty() == false)
		{
			int curr_cost = queue.top().cost;
			int curr_pos = queue.top().pos;

			queue.pop();

			for (int i = 0; i < MAX_SIZE; ++i)
			{
				int bus_cost = costs[curr_pos][i];

				// IsInvalid
				if (bus_cost == MAX_INT) continue;

				int cost = bus_cost + curr_cost;

				if (cost < min_costs[i]) {
					min_costs[i] = cost;
					queue.push(RoadCost(cost, i));
				}
			}
		}

		return min_costs[dst];
	}
};

int main()
{
	int city_count, bus_count;

	std::cin >> city_count >> bus_count;

	CostCalculator calculator;
	Bus bus;

	for (int i = 0; i < bus_count; ++i) {
		std::cin >> bus.src >> bus.dst >> bus.cost;

		calculator.AddRoad(bus);
	}

	int src, dst;
	std::cin >> src >> dst;

	int result = calculator.CalcMinimumCost(src, dst);

	std::cout << result;

	return 0;
}