#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int pre[10005];
int find(int x){
	int root = x;
	while(pre[root] != root){
		root = pre[root];
	}
	int y = x,temp;
	while(pre[y] != root){
		temp = y;
		pre[y] = root;
		y = pre[temp];
	}
	return root;
}
void join(int x,int y){
	int fx = find(x),fy = find(y);
	if(fx != fy){
		pre[fy] = fx;
	}
}
int main(){
	int n,k;
	while(cin>>n){
		memset(pre,0,sizeof(pre));
		int maxBird = 0;
		for(int i = 0; i < n;i++){
			cin>>k;
			vector<int> v(k);
			for(int j = 0; j < k;j++){
				cin>>v[j];
				if(v[j] > maxBird)
					maxBird = v[j];
				if(pre[v[j]] == 0)
					pre[v[j]] = v[j];
			}
			for(int j = 1; j < k;j++){
				join(v[j-1],v[j]);
			}
		}
		unordered_set<int> tree;
		for(int i = 1; i <= maxBird;i++){
			tree.insert(find(i));
		}
		cout<<tree.size()<<" "<<maxBird<<endl;
		int t;
		cin>>t;
		while(t--){
			int b1,b2;
			cin>>b1>>b2;
			if(b1 > maxBird || b2 > maxBird || pre[b1] != pre[b2]){
				cout<<"No"<<endl;
			}else{
				cout<<"Yes"<<endl;
			}
		}

	}
	return 0;
} 
