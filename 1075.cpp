nclude <iostream>
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
using namespace std;
struct User{
	string id;
	vector<int> v;
	int score;
	int sum;
	int sub;
	User(){
		id = "";
		score = 0;
		sum = 0;
		sub = 0;
	}
	bool operator < (const User& other) const{
		if(score == other.score){
			if(sum == other.sum)
				return id < other.id;
			else
				return sum > other.sum;
		}else{
			return score > other.score;
		}
	}
};
int main(){
	int n,k,m;
	while(cin>>n>>k>>m){
		vector<int> points(k+1);
		vector<User> users(n+1);
		for(int i = 1; i <= k;i++)
			cin>>points[i];
		string uid;
		int pid,score,iid;
		stringstream ss;
		while(m--){
			cin>>uid>>pid>>score;
			ss<<uid;
			ss>>iid;
			ss.clear();
			User& user = users[iid];
			if(user.id.empty()) user.id = uid;
			if(user.v.size() == 0) user.v.resize(k+1,-2);
			if(score > user.v[pid]){
				user.v[pid] = score;
				if(score == -1) 
					user.v[pid] = 0;
				else
					user.sub++;
			}
		}
		for(int i = 1; i <= n;i++){
			for(int j = 1; j <= k;j++){
				if(users[i].v.size() == 0) continue;
				if(users[i].v[j] > 0) users[i].score += users[i].v[j];
				if(users[i].v[j] == points[j]) users[i].sum++; 
			}
		}
		sort(users.begin()+1,users.end());
		int rank = 1;
		for(int i = 1; i <= n;i++){
			if(users[i].sub == 0) continue;
			cout<<rank<<' '<<users[i].id<<' '<<users[i].score;
			for(int j = 1; j <= k;j++){
				if(users[i].v[j] >= 0)
					cout<<' '<<users[i].v[j];
				else
					cout<<' '<<'-';
			}
			cout<<endl;
			if(i != n && users[i].score > users[i+1].score)
				rank = i+1;
		}
	}
	return 0;
} 
