#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int a,b;
    stringstream ss;
    while(cin>>a>>b)
    {
        int result =  a + b;
        if (result < 0)
        {
            result = -result;
            cout<<'-';
        }
        if(result < 1000)
        {
            cout << result << endl;
        }
        else
        {
            ss<<result;
            string s = ss.str();
            for(int i = 0;i < s.length();i++)
            {
                cout<<s[i];
                int splash = (s.length() - i - 1);
                if(splash % 3 == 0 && splash != 0)
                {
                    cout<<',';
                }
            }
            cout<<endl;
        }
        ss.str("");

    }
    return 0;
}

