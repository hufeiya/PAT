#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int a[50005];
int book[50005];
struct Node{
	int num;
	int cnt;
	Node(int x,int y):num(x),cnt(y){}
	bool operator < (const Node& x)const{
		if(cnt == x.cnt){
			return num < x.num;
		}else{
			return cnt > x.cnt;
		}
	}
};
int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i = 0; i < n;i++){
			cin>>a[i];
		}
		set<Node> result;
		memset(book,0,50005);
		for(int i = 0;i < n;i++){
			if(i > 0){
				cout<<a[i]<<":";
				int j = 0;
				set<Node>::iterator it = result.begin();
				for(;it != result.end() && j < k;it++,j++){
					cout<<" "<<it->num;
				}
				cout<<endl;
			}
			set<Node>::iterator find = result.find(Node(a[i],book[a[i]]));
			if(find != result.end()){
				int cnt = find->cnt;
				result.erase(find);
				result.insert(Node(a[i],cnt+1));
			}else{
				result.insert(Node(a[i],1));
			}
			book[a[i]]++;
		}
	}
	return 0;
} 
