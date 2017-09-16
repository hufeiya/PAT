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
struct Street{
	bool b;
	int a[2];
};
Street a[505][505];
bool s[505];
int dis[505],pre[505];
int curlen[505],curtime[505];
const int MAX = 2147483647;
int n,m,start,dest;
void dijkstra(bool calculateLength){
	int index = 0;
	if(!calculateLength) index = 1;
	fill(dis,dis+n,MAX);
	fill(curlen,curlen+n,MAX);
	fill(curtime,curtime+n,MAX);
	fill(pre,pre+n,-1);
	fill(s,s+n,false);
	for(int i = 0; i < n;i++){
		if(a[start][i].b){
			dis[i] = a[start][i].a[index];
			pre[i] = start;
			curlen[i] = a[start][i].a[0];
			curtime[i] = a[start][i].a[1];
		}
	}
	dis[start] = 0;
	for(int i = 1; i < n;i++){
		int min = MAX;
		int u = start;
		for(int j = 0; j <n;j++){
			if(!s[j] && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		s[u] = true;
		for(int j = 0; j <n;j++){
			if(!s[j] && a[u][j].b){
				if(dis[u] + a[u][j].a[index] < dis[j]){
					dis[j] = dis[u] + a[u][j].a[index];
					pre[j] = u;
					curlen[j] = curlen[u] + a[u][j].a[0];
					curtime[j] = curtime[u] + a[u][j].a[1];
				}else if(dis[u] + a[u][j].a[index] == dis[j]){
					if(index == 0){
						if(curtime[u] + a[u][j].a[1] < curtime[j]){
							dis[j] = dis[u] + a[u][j].a[index];
							pre[j] = u;
							curlen[j] = curlen[u] + a[u][j].a[0];
							curtime[j] = curtime[u] + a[u][j].a[1];
						}
					}else{
						int l1 = 0,l2 = 0,t = j;
						while(pre[t] != -1){
							t = pre[t];
							l1++;
						}
						t = u;
						while(pre[t] != -1){
							t = pre[t];
							l2++;
						}
						if(l2 + 1 < l1){
							dis[j] = dis[u] + a[u][j].a[index];
							pre[j] = u;
							curlen[j] = curlen[u] + a[u][j].a[0];
							curtime[j] = curtime[u] + a[u][j].a[1];							
						}
					}
				}
			}
		}
	}
}
int main(){
	int v1,v2,oneway,length,time;
	cin>>n>>m;
	for(int i = 0; i <m;i++){
		cin>>v1>>v2>>oneway>>length>>time;
		a[v1][v2].b = true;
		a[v1][v2].a[0] = length;
		a[v1][v2].a[1] = time;
		if(!oneway){
			a[v2][v1].b = true;
			a[v2][v1].a[0] = length;
			a[v2][v1].a[1] = time;
		}
	}
	cin>>start>>dest;
	vector<int> r1;
	vector<int> r2;
	dijkstra(true);
	int i = dest,d1 = dis[dest],d2;
	while(pre[i] != -1){
		r1.push_back(i);
		i = pre[i];
	}
	dijkstra(false);
	d2 = dis[dest];
	i = dest;
	while(pre[i] != -1){
		r2.push_back(i);
		i = pre[i];
	}
	if(r1 == r2){
		cout<<"Distance = "<<d1<<"; Time = "<<d2<<": "<<start<<" -> ";
		for(int i = r1.size()-1;i >= 0;i--){
			cout<<r1[i]<<(i == 0 ? "\n" : " -> ");
		}
	}else{
		cout<<"Distance = "<<d1<<": "<<start<<" -> ";
		for(int i = r1.size()-1;i >= 0;i--){
			cout<<r1[i]<<(i == 0 ? "\n" : " -> ");
		}
		cout<<"Time = "<<d2<<": "<<start<<" -> ";
		for(int i = r2.size()-1;i >= 0;i--){
			cout<<r2[i]<<(i == 0 ? "\n" : " -> ");
		}
	}
	system("pause");
	return 0;
} 
