#include <stdio.h>

struct Vector2D
{
	int x;
	int y;

	Vector2D()
		:x(0)
		, y(0)
	{
	}

	Vector2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D operator-(const Vector2D& rhs)
	{
		return Vector2D(this->x - rhs.x, this->y - rhs.y);
	}

	Vector2D operator+(const Vector2D& rhs)
	{
		return Vector2D(this->x + rhs.x, this->y + rhs.y);
	}

	Vector2D operator-=(const Vector2D& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;

		return *this;
	}

	Vector2D operator+=(const Vector2D& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;

		return *this;
	}
};

class Dice
{
public:
	enum Direction { TOP, LEFT, RIGHT, FRONT, REAR, BOTTOM, MAX };

protected:
	int dice[Direction::MAX] = { 0 };
	Vector2D pos = Vector2D(0, 0);

protected:
	void Rolling(int& lhs, int& rhs)
	{
		int temp = lhs;
		lhs = dice[Direction::TOP];
		dice[Direction::TOP] = rhs;
		rhs = dice[Direction::BOTTOM];
		dice[Direction::BOTTOM] = temp;
	}

public:
	void SetPos(const Vector2D& pos)
	{
		this->pos = pos;
	}

	Vector2D GetPos()
	{
		return pos;
	}

	int GetValue(Direction direction) const
	{
		return dice[direction];
	}

	void SetValue(Direction direction, int val)
	{
		dice[direction] = val;
	}

	void RollLeft()
	{
		Rolling(dice[Direction::LEFT], dice[Direction::RIGHT]);
	}

	void RollRight()
	{
		Rolling(dice[Direction::RIGHT], dice[Direction::LEFT]);
	}

	void RollFront()
	{
		Rolling(dice[Direction::FRONT], dice[Direction::REAR]);
	}

	void RollRear()
	{
		Rolling(dice[Direction::REAR], dice[Direction::FRONT]);
	}
};

int main()
{
	int map_size_x =0 , map_size_y = 0;
	scanf("%d %d", &map_size_y, &map_size_x);

	Vector2D start_pos;
	scanf("%d %d", &start_pos.y, &start_pos.x);

	int command_count = 0;
	scanf("%d", &command_count);

	int* map = new int[map_size_x * map_size_y];

	for (int y = 0; y < map_size_y; ++y)
	{
		for(int x =0; x < map_size_x; ++x)
		{
			scanf("%d", &map[y * map_size_x + x]);
		}
	}

	int* commands = new int[command_count];

	for (int i = 0; i < command_count; ++i)
	{
		scanf("%d", &commands[i]);
	}

	Dice dice;
	dice.SetPos(start_pos);

	for (int i = 0; i < command_count; ++i)
	{
		int command = commands[i];

		Vector2D dice_pos = dice.GetPos();

		auto func_valid_check = [&]()-> bool { return dice_pos.x >= 0 && dice_pos.x < map_size_x&& dice_pos.y >= 0 && dice_pos.y < map_size_y; };

		switch (command)
		{
		case 1:
			dice_pos += Vector2D(1, 0);

			if (func_valid_check())
			{
				dice.RollRight();
			}
			break;
		case 2:
			dice_pos -= Vector2D(1, 0);

			if (func_valid_check())
			{
				dice.RollLeft();
			}
			break;
		case 3:
			dice_pos -= Vector2D(0, 1);

			if (func_valid_check())
			{
				dice.RollFront();
			}
			break;
		case 4:
			dice_pos += Vector2D(0, 1);

			if (func_valid_check())
			{
				dice.RollRear();
			}
			break;
		}

		if (func_valid_check())
		{
			int bottom = dice.GetValue(dice.BOTTOM);

			if (map[dice_pos.x + dice_pos.y * map_size_x] == 0)
			{
				map[dice_pos.x + dice_pos.y * map_size_x] = bottom;
			}
			else
			{
				bottom = map[dice_pos.x + dice_pos.y * map_size_x];
				map[dice_pos.x + dice_pos.y * map_size_x] = 0;
			}

			dice.SetPos(dice_pos);
			dice.SetValue(dice.BOTTOM, bottom);

			printf("%d\n", dice.GetValue(Dice::Direction::TOP));
		}
	}


	delete[] map;
	delete[] commands;

	return 0;
}