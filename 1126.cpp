#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int a[505];
bool visited[505];

void dfs(vector<vector<int>> & v,vector<int> & item){
	if(item.size() > 0){
		for(int i = 0;i < item.size();i++){
			if( ! visited[item[i]]){
				visited[item[i]] = true;
				dfs(v,v[item[i]]);
				
			}
		}
	}
}
int main(){
	int n,m;
	while(cin>>n>>m){
		memset(a,0,sizeof(int)*(n+1));
		vector<vector<int>> v(n+1);
		memset(a,0,sizeof(bool)*(n+1));
		int x,y;
		for(int i = 0; i < m;i++){
			cin>>x>>y;
			a[x]++;
			a[y]++;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bool b = true;
		int oddNum = 0;
		for(int i = 1; i < n+1;i++){
			if(a[i]%2){
				b = false;
				oddNum++;
			}
		}
		visited[1] = true;
		dfs(v,v[1]);
		if(b){
			for(int i = 1; i < n + 1;i++){
				if( ! visited[i]){
					b = false;
					continue;
				}
			}
		}

		for(int i = 1; i <n+1;i++){
			if(i != 1) cout<<" ";
			cout<<a[i];
		}

		cout<<endl;
		if(b)
			cout<<"Eulerian";
		else if(oddNum == 2)
			cout<<"Semi-Eulerian";
		else
			cout<<"Non-Eulerian";
		cout<<endl;

	}
	return 0;
} 
