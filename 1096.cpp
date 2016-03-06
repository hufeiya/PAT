#include <iostream>
#include <iomanip>
#include <deque>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


int main() {
    int n;

    while (cin >> n) {
        bool prime = false;
        int len = sqrt(n);
        for(int i = 2;i <= len;i++){
            if(n % i == 0){
                break;
            }
            if(i == len){
                prime = true;
            }
        }
        if(prime){
            cout<<1<<endl<<n<<endl;
            continue;
        }
        int endNum = 2,temp = n,max = 0;
        int subEndNum = 2,subMax = 0;
        for(int i = 2;i <= 1000;i++){
            if(temp / i > 0 && temp % i == 0){
                subMax++;
                temp /= i;
                subEndNum = i;
            }else{
                temp = temp * (i - subMax);
                if(subMax > max){
                    max = subMax;
                    endNum = subEndNum;
                }
                i--;
                subMax -= 1;

            }
        }
        cout<<max<<endl;
        for(int i = endNum - max + 1;i <= endNum;i++){
            cout<<i;
            if(i == endNum){
                cout<<endl;
            }else{
                cout<<'*';
            }
        }
    }
    return 0;
}

