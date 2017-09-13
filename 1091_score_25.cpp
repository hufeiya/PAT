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
#include <stack>
#include <queue>
using namespace std;
bool a[80][1300][130];
bool vis[80][1300][130];
int m,n,l,t;
int dfs(int z,int y,int x){
	if(z < 0 || y < 0 || x < 0 || z >= l || y >= m || x >= n) return 0;
	if(vis[z][y][x] || !a[z][y][x]) return 0;
	vis[z][y][x] = true;
	return  1 + dfs(z+1,y,x) + dfs(z,y+1,x) + dfs(z,y,x+1) + dfs(z-1,y,x) + dfs(z,y-1,x) + dfs(z,y,x-1);
}
int main(){
	while(cin>>m>>n>>l>>t){
		for(int i = 0; i < l;i++){
			for(int j = 0; j < m;j++){
				for(int k = 0; k < n;k++){
					cin>>a[i][j][k];
				}
			}
		}
		int temp,result = 0;
		for(int i = 0; i < l;i++){
			for(int j = 0; j < m;j++){
				for(int k = 0; k < n;k++){
					temp = dfs(i,j,k);
					if(temp >= t) result += temp;
				}
			}
		}
		cout<<result<<endl;
	}
	return 0;
} 
