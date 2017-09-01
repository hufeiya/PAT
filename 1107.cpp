#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
int pre[1005];
//并查集
int findx(int x){
	if(pre[x] == x) return x;
	int root = x;
	while(pre[root] != root){
		root = pre[root];
	}
	int y = x,temp;
	while(pre[y] != root){
		temp = pre[y];
		pre[y] = root;
		y = temp;
	}
	return root;
}

void join(int x,int y,unordered_map<int,unordered_set<int>>& m){
	int fx = findx(x);
	int fy = findx(y);
	if(fx == fy) return;
	pre[fx] = fy;
	m[fy].insert(m[x].begin(),m[x].end());
}
int main(){
	int n;;
	while(cin>>n){
		int num;
		memset(pre,0,sizeof(pre));
		unordered_map<int,unordered_set<int>> m;
		for(int i = 1; i <= n;i++){
			cin>>num;
			getchar();
			int temp;
			for(int j = 0; j < num;j++){
				cin>>temp;
				m[i].insert(temp);
			}
			if(pre[i] == 0) pre[i] = i;
			bool first = true;
			for(int j = 1; j < i;j++){
				unordered_set<int>::iterator it = m[i].begin();
				for(;it != m[i].end();it++){
					if(m[j].find(*it) != m[j].end()){
						if(first){
							join(i,j,m);
							first = false;
						}else
							join(j,i,m);

					}
				}
			}
		}
		map<int,int> lead;
		for(int i = 1;i <= n;i++){
			lead[findx(i)]++;
		}
		cout<<lead.size()<<endl;
		vector<int> result;
		for(map<int,int>::reverse_iterator it = lead.rbegin();it != lead.rend();it++){
			result.push_back(it->second);
		}
		sort(result.begin(),result.end());
		for(int i = result.size()-1;i >= 0;i--){
			cout<<result[i];
			if(i != 0)
				cout<<" ";
			else
				cout<<endl;
		}
	}
	return 0;
} 
