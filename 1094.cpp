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
struct Node{
	vector<int> child;
	Node(){}
};

int getLevelNum(Node& node,int level,vector<Node>& v){
	if(level <= 0) return 0;
	if(level == 1){
		return 1;
	}else{
		if(node.child.size() == 0)
			return 0;
		else{
			int sum = 0;
			for(int i = 0; i < node.child.size();i++)
				sum += getLevelNum(v[node.child[i]],level-1,v);
			return sum;
		}
	}
	
}
int main(){
	int n,m;
	while(cin>>n>>m){
		if(n == 1 && m == 0){
			cout<<1<<" "<<1<<endl;
			continue;
		}
		vector<Node> v(n+1);
		for(int i = 1; i <= m;i++){
			int index,num,temp;
			cin>>index>>num;
			while(num--){
				cin>>temp;
				v[index].child.push_back(temp);
			}
		}
		int max = 0,level = 1,cur;
		for(int i = 1; i < n;i++){
			cur = getLevelNum(v[1],i,v);
			if(cur > max){
				max = cur;
				level = i;
			}else if(cur == 0)
				break;
		}
		cout<<max<<" "<<level<<endl;
	}
	return 0;
} 
