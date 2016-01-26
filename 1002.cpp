#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
double a[1001];
int main() {
    int n;
    bool flag = false;
    while(cin>>n)
    {
        flag = !flag;
        if (flag)
        {
            memset(a,0,1001);
        }
        int exponents;
        double coefficients;
        while(n--)
        {
            cin>>exponents>>coefficients;
            a[exponents] += coefficients;
        }
        if(!flag)
        {
            int size = 0;
            for(int i = 0;i <= 1000;i++)
            {
                if(a[i] != 0)
                {
                    size++;
                }
            }
            cout<<size;
            for(int i = 1000;i >= 0;i--)
            {
                if(a[i] != 0)
                {
                    cout<<" "<<i<<" "<<fixed<<setprecision(1)<<a[i];
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

