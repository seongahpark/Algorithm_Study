#include <iostream>
#include <vector>
using namespace std;
int main()
{	
	int testCase=0;
	cin>>testCase;
	vector<string> strings(testCase);
	vector<int> r(testCase);
	for(int i=0;i<testCase;++i)
	{
		int tmp_r;
		string tmp_str;
		cin>>tmp_r>>tmp_str;
		
		r[i] = tmp_r;
		strings[i] = tmp_str;
	}
	
	for(int i=0;i<testCase;++i)
	{
		string tmp = strings[i];
		int tmp2 = r[i];
		for(int j = 0;j<tmp.length();++j)
		{
			for(int k=0;k<tmp2;++k)
			{
				cout<<tmp[j];
			}
		}
		cout<<endl;
	}
 	
	return 0;
}
