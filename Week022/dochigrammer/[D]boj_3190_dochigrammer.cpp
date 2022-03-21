#include <stdio.h>
#include <queue>
#include<cstring>

struct Vector2D
{
	int x;
	int y;

	Vector2D()
		:x(0)
		,y(0)
	{
	}

	Vector2D(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D operator+( const Vector2D& rhs)
	{
		return Vector2D( this->x + rhs.x, this->y + rhs.y );
	}

	void FromRowAndCol( int row, int col)
	{
		this->x = row - 1;
		this->y = col - 1;
	}

};

struct RotationCommand
{
	static const char left = 'L';
	static const char right = 'D';

	int required_time = 0;
	bool is_left = false;

	RotationCommand(int time, char rotation_input)
		:required_time(time)
		,is_left( rotation_input == left)
	{
	}
};

class Board
{
public:
	enum Space { Empty, Apple, Block };

protected:
	Space* map = nullptr;
	int size = 0;

public:

	Board(int _board_size)
	{
		size = _board_size;

		if (map != nullptr)
		{
			delete[] map;
			map = nullptr;
		}

		map = new Space[size * size];
		memset(map, 0, size* size * sizeof(Space));
	}

	~Board()
	{
		if (map != nullptr)
		{
			delete[] map;
			map = nullptr;
		}
	}

public:
	void SetBoardSpace(const Vector2D& pos, Space space_type)
	{
		map[pos.x + pos.y * size] = space_type;

	}

	Space GetBoardSpace(const Vector2D& pos)
	{
		return map[pos.x + pos.y * size];
	}
	bool IsThereApple(const Vector2D& pos) const { return map[pos.x + pos.y * size] == Space::Apple; }
	bool IsThereBlock(const Vector2D& pos) const {
		if (pos.x < 0 || pos.x >= size ||
			pos.y < 0 || pos.y >= size)
			return true;

		return map[pos.x + pos.y * size] == Space::Block; 
	}
};

class Snake
{
protected:
	std::queue<Vector2D> visited_pos_queue;
	Vector2D curr_dir;
	Vector2D curr_pos;

public:
	Snake( const Vector2D&& start_pos, const Vector2D&& start_dir)
	{
		curr_dir = start_dir;
		curr_pos = start_pos;
	}


public:
	bool Move( Board& board)
	{
		Vector2D next_pos = curr_pos + curr_dir;

		// 이동 가능 여부
		if (board.IsThereBlock(next_pos))
		{
			return false;
		}

		visited_pos_queue.push(curr_pos);// 지나온 지점 등록
		curr_pos = next_pos;

		bool is_there_apple = board.IsThereApple(curr_pos);
		board.SetBoardSpace(curr_pos, Board::Space::Block); // 머리 위치의 공간 잠구기

		if (is_there_apple == false) // 사과가 없으면 꼬리가 있던 공간 리셋 & 꼬리 줄이기
		{
			Vector2D visitied_pos = visited_pos_queue.front();
			visited_pos_queue.pop();
			board.SetBoardSpace(visitied_pos, Board::Space::Empty);
		}

		return true;
	}

	void TurnLeft()
	{
		int temp = curr_dir.x;
		curr_dir.x = curr_dir.y;
		curr_dir.y = temp * -1;
	}

	void TurnRight()
	{
		int temp = curr_dir.x;
		curr_dir.x = curr_dir.y * -1;
		curr_dir.y = temp;
	}

};

int main()
{
	int map_size = 0;
	scanf("%d",  &map_size);

	Board board(map_size);

	int apple_count = 0;
	scanf("%d", &apple_count);

	for (int i = 0; i < apple_count; ++i)
	{
		Vector2D pos;
		scanf("%d %d", &pos.y, &pos.x);

		pos.FromRowAndCol(pos.x, pos.y);

		// 보드에 사과 세팅
		board.SetBoardSpace(pos, Board::Space::Apple);
	}

	int transform_count = 0;
	scanf("%d", &transform_count);

	Snake snake( Vector2D( 0, 0), Vector2D(1, 0));

	std::queue<RotationCommand> command_queue;

	for (int i = 0; i < transform_count; ++i)
	{
		int time = 0;
		char rotation_input = RotationCommand::left;

		scanf("%d %c", &time, &rotation_input);

		// 회전 커맨드 세팅
		RotationCommand cmd(time, rotation_input);
		command_queue.push(cmd);
	}

	int time = 1;
	while (snake.Move(board))
	{
		while (command_queue.empty() == false)
		{
			RotationCommand cmd =  command_queue.front();

			if (cmd.required_time > time)
				break;

			if (cmd.is_left)
			{
				snake.TurnLeft();
			}
			else
			{
				snake.TurnRight();
			}

			command_queue.pop();
		}

		++time;
	}

	printf("%d", time);

	return 0;
}