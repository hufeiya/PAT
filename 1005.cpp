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
    string s;
    while(cin >> s) {
        int n = 0;
        for(int i = 0; i < s.length();i++){
            n += s[i] - '0';
        }
        vector<string> v = {"zero","one","two","three","four","five","six","seven"
                ,"eight","nine"};
        stringstream ss;
        ss << n;
        ss >> s;
        for(int i = 0;i < s.length();i++){
            cout<<v[s[i] - '0'];
            if(i == s.length()-1){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
    }
    return 0;
}

