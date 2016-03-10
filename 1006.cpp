#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;

const int MAXINT = 2147483647;

int main() {
    int n;
    while(cin >> n) {
        unordered_map<string,string> in;
        unordered_map<string,string> out;
        vector<string> vin;
        vector<string> vout;
        while(n--){
            string id,signin,signout;
            cin>>id>>signin>>signout;
            in[signin] = id;
            out[signout] = id;
            vin.push_back(signin);
            vout.push_back(signout);
        }
        sort(vin.begin(),vin.end());
        sort(vout.begin(),vout.end());
        cout<<in[vin[0]]<<" "<<out[vout[vout.size() - 1]]<<endl;
    }
    return 0;
}

