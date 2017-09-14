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
int cnt[10005];
struct Record{
	string plate;
	int time;
	int no;
	bool in;
	bool operator < (const Record& other)const{
		if(no == other.no)
			return time < other.time;
		else
			return no < other.no;
	}
};
int main(){
	int n,m;
	string plate,status;
	cin>>n>>m;
	vector<Record> v(n);
	vector<int> queries(m);
	int hh,mm,ss;
	unordered_map<int,bool> carIn;
	unordered_map<int,int> stay;
	unordered_map<string,int> name;
	unordered_map<int,string> mname;
	for(int i = 0; i < n;i++){
		cin>>v[i].plate;
		scanf(" %d:%d:%d ",&hh,&mm,&ss);
		cin>>status;
		v[i].time = hh*3600+mm*60+ss;
		if(status[0] == 'i')
			v[i].in = true;
		else
			v[i].in = false;
		int no = name.size();
		if(name.find(v[i].plate) == name.end()) {
			name[v[i].plate] = no;
		}
		else{
			no = name[v[i].plate];
		}
		mname[no] = v[i].plate;
		carIn[no] = false;
		v[i].no = name[v[i].plate];
	}
	sort(v.begin(),v.end());
	vector<Record> vv;
	for(int i = 0; i < n;i++){
		int no = v[i].no;
		if(v[i].in){
			if(carIn[no]){
				vv.pop_back();
			}else{
				carIn[no] = true;
				cnt[no]++;
			}
			vv.push_back(v[i]);
		}else{
			if(carIn[no]){
				vv.push_back(v[i]);
				cnt[no]++;
				carIn[no] = false;
				stay[no] += vv.back().time - vv[vv.size()-2].time;
			}
		}
	}
	for(unordered_map<int,bool>::iterator it = carIn.begin();it != carIn.end();it++){
		it->second = false;
	}
	//sort(vv.begin(),vv.end());
	while(m--){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		int query = hh*3600+mm*60+ss;
		int no,t=0;
		for(int i = 0; i < name.size();i++){
			for(int j = 0; j < cnt[i];j++){
				no = vv[t+j].no;
				if(vv[t+j].time > query){
					break;
				}
				if(vv[t+j].in)
					carIn[no] = true;
				else
					carIn[no] = false;
				}
			t+= cnt[i];
		}
		int ans = 0;
		for(unordered_map<int,bool>::iterator it = carIn.begin();it != carIn.end();it++){
			if(it->second) {
				ans++;
				it->second = false;
			}

		}
		cout<<ans<<endl;
	}
	int maxtime = -1;
	vector<string> result;
	for(unordered_map<int,int>::iterator it = stay.begin();it != stay.end();it++){
		if(it->second > maxtime){
			maxtime = it->second;
			result.clear();
			result.push_back(mname[it->first]);
		}else if(it->second == maxtime){
			result.push_back(mname[it->first]);
		}
	}
	sort(result.begin(),result.end());
	for(int i = 0;i < result.size();i++){
		cout<<result[i]<<' ';
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime%3600/60,maxtime%60);
	system("pause");
	return 0;
} 
