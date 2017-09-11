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
//就是dfs找出所有最优结果，根本不需要dijkstra
int a[205][205];
bool link[205][205];
int mincost = 2147483647,maxhappy = -1,num;
vector<int> result;
vector<int> route;
bool vis[205];
unordered_map<int,int> happies;
void dfs(int n,int start,int end,int cost,int happy){
	if(start == end){
		if(cost < mincost){
			num = 1;
			mincost = cost;
			maxhappy = happy;
			result.assign(route.begin(),route.end());
		}else if(cost == mincost){
			num++;
			if(happy > maxhappy || (happy == maxhappy && route.size() < result.size())){
				maxhappy = happy;
				result.assign(route.begin(),route.end());
			}
		}
		return;
	}
	for(int i = 0; i < n;i++){
		if(i == start || !link[start][i] || vis[i]) continue;
		route.push_back(i);
		vis[i] = true;
		dfs(n,i,end,cost+a[start][i],happy+happies[i]);
		vis[i] = false;
		route.pop_back();
	}
}
int main(){
	int n,k;
	string start;
	while(cin>>n>>k>>start){
		unordered_map<string,int> um;
		unordered_map<int,string> umm;
		um[start] = 0;
		umm[0] = start;
		string temp;
		int thappy;
		for(int i = 1; i < n;i++){
			cin>>temp>>thappy;
			um[temp] = i;
			happies[i] = thappy;
			umm[i] = temp;
		}
		vis[um[start]] = true;
		string c1,c2;
		int cost;
		for(int i = 0; i <k;i++){
			cin>>c1>>c2>>cost;
			int i1 = um[c1],i2 = um[c2];
			a[i1][i2] = cost;
			a[i2][i1] = cost;
			link[i1][i2] = true;
			link[i2][i1] = true;
		}
		dfs(n,um[start],um["ROM"],0,0);
		cout<<num<<' '<<mincost<<' '<<maxhappy<<' '<<maxhappy/result.size()<<endl;
		cout<<start<<"->";
		for(int i = 0; i < result.size();i++){
			cout<<umm[result[i]];
			cout<<(i == result.size()-1 ? "\n" : "->");
		}
	}
	return 0;
} 
