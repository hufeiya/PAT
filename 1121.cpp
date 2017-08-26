#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		unordered_map<string,string> pair;
		string a,b;
		for(int i = 0; i < n;i++){
			cin>>a>>b;
			pair[a] = b;
			pair[b] = a;
		}
		int m;
		cin>>m;
		unordered_set<string> participate;
		vector<string> single;
		string temp;
		for(int i = 0; i < m;i++){
			cin>>temp;
			participate.insert(temp);
		}
		for(unordered_set<string>::iterator it = participate.begin();it != participate.end();it++){
			if(pair.find(*it) == pair.end() || participate.find(pair[*it]) == participate.end()){
				single.push_back(*it);
			}
		}
		sort(single.begin(),single.end());
		cout<<single.size()<<endl;
		for(int i = 0; i < single.size();i++){
			cout<<single[i];
			if(i == single.size()-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
	
	return 0;
} 
