#include <iostream>
#include <deque>
#include<string>

using namespace std;

int main()
{

    int repeat;
    cin >> repeat;

    for (int i = 0; i < repeat; i++)
    {

        deque<int> AC;
        
        string func;
        cin >> func;

        int arrnumber;
        cin >> arrnumber;
        
        string arrcmd;
        cin >> arrcmd;


        string temp="";

        for (int j = 0; j < arrcmd.length(); j++)
        {
            if ('0' <= arrcmd[j] && arrcmd[j] <= '9')
                temp += arrcmd[j];
            else if (arrcmd[j] == ',' || arrcmd[j] == ']') {
                if (temp!="") {
                    AC.push_back(stoi(temp));
                    temp="";
                }
            }
        }

        bool error = false;
        bool reverse = false;

        
        for (int j = 0; j < func.length(); j++)
        {
           if (func[j] == 'R')
               reverse=!reverse;
           if (func[j] == 'D') {
              if (AC.empty()) {
                 error = true;
                 break;
              }
              else {
                  if(reverse)AC.pop_back();
                  else AC.pop_front();
              }
           }
        }


        if (error)
        {
           cout << "error" << "\n";
        }
        else
        {
            cout << "[";
            if (reverse) {
                while (!AC.empty())
                {
                    cout << AC.back();
                        if (AC.size() != 1)
                        cout<<",";
                    AC.pop_back();
                }
            }
            else {
                while (!AC.empty())
                {
                    cout << AC.front();
                    if (AC.size() != 1)
                        cout << ",";
                    AC.pop_front();
                }
            }

            cout << "]" << endl;
        }


    }
}