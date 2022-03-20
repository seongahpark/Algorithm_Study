#include <stdio.h>
#include <queue>

int Max( int lhs, int rhs)
{
	if (lhs > rhs)
		return lhs;

	return rhs;
}

// 무게와 끝날 라운드 기록
struct truck_info
{
	int weight = 0;
	int arrival_time = 0;

	truck_info(int _weight, int _arrival_time)
		:weight(_weight)
		,arrival_time(_arrival_time)
	{
	}
};

int main()
{
	int truck_count, bridge_length, bridge_max_weight;

	scanf("%d %d %d", &truck_count, &bridge_length, &bridge_max_weight);

	if (truck_count == 0 || bridge_length == 0)
	{
		return 0; // assertion
	}

	
	std::queue<int> waiting_truck_weights;

	for (int i = 0; i < truck_count; ++i)
	{
		int truck_weight;

		scanf("%d", &truck_weight);

		if (truck_weight > bridge_max_weight )
			return 0; // assertion

		waiting_truck_weights.push(truck_weight); // 건너갈 트럭의 무게
	}
	
	int curr_time = 0;
	int curr_briedge_weight = 0;
	std::queue<truck_info> progressing_trucks; // 다리를 건너는중인 트럭들 정보

	do
	{
		// Remove Truck
		if (progressing_trucks.empty() == false) 
		{
			auto& front_truck = progressing_trucks.front();
			if (front_truck.arrival_time <= curr_time) // 맨앞의 트럭이 도착예상시간에 도달했을때
			{
				curr_briedge_weight -= front_truck.weight;
				progressing_trucks.pop();
			}
		}

		// Add Truck
		if( waiting_truck_weights.empty()== false )
		{ 
			int waiting_truck_weight = waiting_truck_weights.front();
			if (curr_briedge_weight + waiting_truck_weight <= bridge_max_weight) // 다음 대기중인 트럭이 가중치 수용이 가능할때
			{
				curr_briedge_weight += waiting_truck_weight;
				progressing_trucks.push(truck_info(waiting_truck_weight, curr_time + bridge_length));
				waiting_truck_weights.pop();
			}
		}

		++curr_time;
	} while (progressing_trucks.empty() == false);

	printf("%d", curr_time);
	return 0;
	
}

