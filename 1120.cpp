#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		vector<string> v(n);
		unordered_map<int,int> frequent;
		for(int i = 0; i < n;i++) cin>>v[i];
		for(int i = 0; i < n;i++){
			int sum = 0;
			for(int j = 0; j < v[i].length();j++){
				sum += v[i][j] - '0';
			}
			frequent[sum]++;
		}
		vector<int> result;
		unordered_map<int,int>::iterator it = frequent.begin();
		for(;it != frequent.end();it++){
			result.push_back(it->first);
		}
		sort(result.begin(),result.end());
		cout<<result.size()<<endl;
		for(int i = 0; i < result.size();i++){
			cout<<result[i];
			if(i == result.size()-1)
				cout<<endl;
			else
				cout<<" ";
		}
	}
	
	return 0;
} 
