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
int a[1005][1005];
int result;
bool vis[1005];
struct Node{
	int id,layer;
	Node(int a,int b):id(a),layer(b){}
};
void bfs(int n,int target,int level){
	queue<Node> q;
	memset(vis,0,sizeof(bool)*(n+1));
	vis[target] = true;
	q.push(Node(target,0));
	int cur = target;
	while( ! q.empty()){
		cur = q.front().id;
		int l = q.front().layer;
		if(l > level) break;
		q.pop();
		if(cur != target) result++;
		for(int i = 1;i <= n;i++){
			if(! vis[i] && a[i][cur] == 1 && l <= level){
				q.push(Node(i,l+1));
				vis[i] = true;
				
			}
		}
	}
}
int main(){
	int n,l;
	while(cin>>n>>l){
		for(int i = 1; i <= n;i++){
			int num,temp;
			cin>>num;
			for(int j = 1; j <= num;j++){
				cin>>temp;
				a[i][temp] = 1;
			}
		}
		int num;
		cin>>num;
		while(num--){
			int query;
			result = 0;
			cin>>query;
			bfs(n,query,l);
			cout<<result<<endl;
		}
	}
	return 0;
} 
