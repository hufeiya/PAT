#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int a[205][205];
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(a,0,sizeof(a));
		int x,y;
		for(int i = 0; i < m;i++){
			cin>>x>>y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		int query;
		cin>>query;
		for(int i = 0; i < query;i++){
			int num;
			bool result = true;
			cin>>num;
			vector<int> v(num);
			unordered_set<int> freq;
			for(int j = 0;j < num;j++){
				cin>>v[j];
				freq.insert(v[j]);
			}

			if(num != n+1 || v[0] != v[num-1] || freq.size() != n){
				cout<<"NO"<<endl;
				continue;
			}
			for(int j = 1; j < num;j++){
				if(a[v[j-1]][v[j]] == 0){
					result = false;
					break;
				}
			}
			cout<<(result ? "YES" : "NO")<<endl;
		}
	}
	return 0;
} 
