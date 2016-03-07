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

const int MAX = 1005;
int prevv[MAX];

int find(int x){
    int r = x;
    while(prevv[r] != r){
        r = prevv[r];
    }
    int i = x,j;
    while(i != r){
        j = prevv[i];
        prevv[i] = r;
        i = j;
    }
    return r;
}

void join(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx != fy){
        prevv[fy] = fx;
    }
}

int main() {
    int n,m,k;

    while (cin >> n >> m >> k) {
        int raw[m*2];
        for(int i =0 ;i < m;i++){
            int x,y;
            cin>>x>>y;
            raw[i*2] = x;
            raw[i*2 + 1] = y;
        }
        for(int i = 0; i < k;i++){
            int city;
            cin >> city;
            for(int i = 1; i <= n;i++){
                prevv[i] = i;
            }
            for(int i =0 ;i < m;i++){
                if(raw[i*2] == city || raw[i*2+1] == city){
                    continue;
                }
                join(raw[i*2],raw[i*2+1]);
            }
            unordered_set<int> head;
            for(int i = 1; i <= n;i++){
                if(i == city){
                    continue;
                }
                int root = find(i);
                if(head.find(root) == head.end()){
                    head.insert(root);
                }
            }
            cout<<head.size()-1<<endl;
        }

    }
    return 0;
}

