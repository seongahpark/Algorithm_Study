//#include <iostream>
//#include <string>
//using namespace std;
//
//int main(){
//	string a[2];
//	string sA[2];
//	int ans[2];
//	
//	cin >> a[0] >> a[1];
//	for(int i=0; i<2; i++){
//		for(int j=2;j>=0;j--){
//			sA[i][2-j] = a[i][j];
//		}		
//		ans[i] = stoi(sA[i]); // string to int 변환 
//	}
//
//	if(ans[0] >= ans[1]) cout << ans[0];
//	else cout << ans[1];
//	
//	return 0;
//}

/// 위의 코드도 맞는 풀이... 새벽엔 틀렸다하고 오전에는 맞았다하는 백준 클라스
 
 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int i_a, i_b;
	i_a = stoi(a);
	i_b = stoi(b);
	cout << (i_a >= i_b ? i_a : i_b);
	
	return 0;
} 
