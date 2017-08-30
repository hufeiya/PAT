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
#include <exception>
using namespace std;
struct Person{
	string name;
	int height;
	void add(string n,int h){
		name = n;
		height = h;
	}
	bool operator <(const Person& other){
		if(height == other.height)
			return name > other.name;
		else
			return height < other.height;
	}
};
int main(){
	int n,k;
	while(cin>>n>>k){
		vector<Person> v(n);
		string name;
		int height;
		for(int i = 0; i < n;i++){
			cin>>name>>height;
			v[i].add(name,height);
		}
		sort(v.begin(),v.end());
		int row = n/k;
		vector<vector<string>> vv(k);
		for(int i = 0; i < k;i++){
			if(i < k - 1){
				vv[i].resize(row);
			}else{
				vv[i].resize(row + n%k);
			}
		}
		int t = v.size() - 1;
		for(int i = k-1;i >= 0;i--){
			int cur = vv[i].size()/2;
			int flag = -1;
			for(int j = 0; j < vv[i].size();j++){
				vv[i][cur] = v[t--].name;
				cur += (j+1)*flag;
				flag = -flag;
			}
		}
		for(int i = vv.size()-1;i >= 0; i--)
			for(int j = 0; j < vv[i].size();j++){
				cout<<vv[i][j];
				if(j != vv[i].size()-1)
					cout<<" ";
				else
					cout<<endl;
			}
	}
	return 0;
} 
