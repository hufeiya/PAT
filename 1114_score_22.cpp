#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
int pre[10000];
int people[10000];
int sets[10000];
int area[10000];
int find(int id){
	if(pre[id] == id) return id;
	int x = id;
	while(pre[x] != x){
		x = pre[x];
	}
	int y = id,temp;
	while(pre[y] != x){
		temp = pre[y];
		pre[y] = x;
		y = temp;
	}
	return x;
}

void join(int x,int y){
	int x1,y1;
	x1 = find(x);
	y1 = find(y);
	if(x1 != y1){
		if(y1 < x1){
			pre[x1] = y1;
			people[y1] += people[x1];
			sets[y1] += sets[x1];
			area[y1] += area[x1];
		}else{
			pre[y1] = x1;
			people[x1] += people[y1];
			sets[x1] += sets[y1];
			area[x1] += area[y1];
		}
	}
}

struct Family{
	int minId;
	int memSum;
	double avgSets;
	double avgArea;
	void add(int id,int mem,int sets,int area){
		minId = id;
		memSum = mem;
		avgSets = double(sets) / mem;
		avgArea = double(area) / mem;
	}
	bool operator < (const Family& other){
		if(fabs(avgArea - other.avgArea) < 0.001){
			return minId < other.minId;
		}else{
			return avgArea > other.avgArea;
		}
	}
	string idFormat(){
		string sid;
		stringstream ss;
		ss << minId;
		ss >> sid;
		string zero (4 - sid.length(),'0');
		return zero + sid;
	}
	void print(){
		cout<<idFormat()<<" "<<memSum<<" "<<setprecision(3)<<fixed<<avgSets<<" "<<setprecision(3)<<fixed<<avgArea<<endl;
	}
};
int main(){
	int n;
	while(cin>>n){
		memset(pre,0,sizeof(pre));
		memset(people,0,sizeof(pre));
		memset(sets,0,sizeof(pre));
		memset(area,0,sizeof(pre));
		vector<int> ids(n);
		for(int i = 0; i < n;i++){
			int id,father,mother,childNum,setsNum,areaNum;
			cin>>id>>father>>mother>>childNum;
			ids[i] = id;
			vector<int> children(childNum);
			for(int j = 0;j < childNum;j++){
				cin>>children[j];
				if(pre[children[j]] == 0){
					pre[children[j]] = children[j];
					people[children[j]] = 1;
				}
			}
			cin>>setsNum>>areaNum;
			if(pre[id] == 0){
				pre[id] = id;
				people[id] = 1;
				sets[id] = setsNum;
				area[id] = areaNum;
			}else{
				sets[find(id)] += setsNum;
				area[find(id)] += areaNum;
			}
			if(father != -1){
				if(pre[father] == 0){
					pre[father] = father;
					people[father] = 1;
				}
				join(id,father);
			}
			if(mother != -1){
				if(pre[mother] == 0){
					pre[mother] = mother;
					people[mother] = 1;
				}
				join(id,mother);
			}
			for(int j = 0;j < childNum;j++)
				join(id,children[j]);
		}
		unordered_set<int> idset;
		for(int i = 0; i <n;i++){
			idset.insert(find(ids[i]));
		}
		vector<Family> families(idset.size());
		int t = 0;
		for(unordered_set<int>::iterator it = idset.begin();it != idset.end();it++){
			int id = *it;
			families[t++].add(id,people[id],sets[id],area[id]);
		}
		sort(families.begin(),families.end());
		cout<<families.size()<<endl;
		for(int i = 0; i < families.size();i++){
			families[i].print();
		}
	}
	return 0;
} 
