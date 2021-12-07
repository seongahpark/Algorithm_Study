#include <iostream>

#define North 0
#define East 1
#define South 2
#define West 3

using namespace std;
int **area;
int clean_block = 0;
void RobotAction(int direction,int position_x,int position_y)
{
	int back_posx =position_x;
	int back_posy =position_y;
	int tile_value = area[position_y][position_x];
	
	if(tile_value == 0)
	{
		area[position_y][position_x] = 2;
		++clean_block;
	}

	bool blocked = true;
	int dir  = direction;
	int value=0;
	for(int i=0;i<4;++i)
	{
		int posx = position_x;
		int posy = position_y;
		dir = (dir + 3)%4;
		if(dir == North)
			posy -=1;
		else if(dir == East)
			posx +=1;
		else if(dir== South)
			posy +=1;
		else if(dir== West)
			posx -=1;
		value = area[posy][posx];
		if(value == 0)
		{
			RobotAction(dir,posx,posy);
			blocked = false;
			break;
		}		
	}
	if(blocked)
	{
		if(direction == North)
			back_posy +=1;
		else if(direction == East)
			back_posx -=1;
		else if(direction == South)
			back_posy -=1;
		else if(direction == West)
			back_posx +=1;
		value = area[back_posy][back_posx];
		if(value !=1)
			RobotAction(direction,back_posx,back_posy);
	}
}

int main()
{
	// 행,열 
	int row,col;
	// 가로 위치, 세로위치, 방향 
	int position_x,position_y,direction;
	
	// 세로,가로 입력 
	cin>>row>>col; 
	cin>>position_y>>position_x>>direction;

	area = new int*[row];
	
	for(int i=0;i<row;++i)
	{
		area[i] = new int[col];
	}
	
	for(int i=0;i<row;++i)
	{
		for(int j=0;j<col;++j)
		{
			int value =0;
			cin>>value;
			area[i][j] = value;
		}
	}
	
	RobotAction(direction,position_x,position_y);

	cout<<clean_block;
	
	for(int i=0;i<row;++i)
		delete area[i];
		
	delete [] area;
	
	return 0;
}
