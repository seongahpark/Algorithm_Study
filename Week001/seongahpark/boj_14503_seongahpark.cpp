#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t_x, t_y;
	int x, y, pos;
	int count = 0;
	int check = 0;
	cin >> t_x >> t_y;
	cin >> x >> y >> pos;
	vector<vector<int>> arr;
	vector<int> v;

	int tmp;
	for(int i=0; i<t_x; i++){
		for(int j=0; j<t_y; j++){
			cin >> tmp;
			v.push_back(tmp);
		}
		arr.push_back(v);
		v.clear();
	}

	int loop_chk = 0;
	while(loop_chk == 0){
		if(arr[x][y] == 0){
			arr[x][y] = 2; //clean success 
			count++;
		}else if(check >= 4){
			check = 0;
			switch(pos){
				case 0:
					if(arr[x+1][y] == 1) loop_chk = 1;
					else x++;
					break;
				case 1:
					if(arr[x][y-1] == 1) loop_chk = 1;
					else y--;
					break;
				case 2:
					if(arr[x-1][y] == 1) loop_chk = 1;
					else x--;
					break;
				case 3:
					if(arr[x][y+1] == 1) loop_chk = 1;
					else y++;
					break;
			}
		}else{
			switch(pos){
				case 0:
					if(arr[x][y-1] == 0) {
						y--;
						check = 0;	
					}						
					else check++;
					pos = 3;
					break;
				case 1:
					if(arr[x-1][y] == 0){
						x--;
						check = 0;
					}
					else check++;
					pos = 0;
					break;
				case 2:
					if(arr[x][y+1] == 0){
						y++;
						check = 0;
					}
					else check++;
					pos = 1;
					break;
				case 3:
					if(arr[x+1][y] == 0){
						x++;
						check = 0;
					}
					else check++;
					pos = 2;
					break;
			}
		}
	}
	
	cout << count;
	return 0;
}
