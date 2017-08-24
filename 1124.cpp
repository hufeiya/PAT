#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <unordered_set>
using namespace std;
int main(){
	int m,n,s;
	while(cin >> m>>n>>s){
		vector<string> v(m+1);
		for(int i = 1; i < m + 1;i++){
			cin>>v[i];
		}
		vector<string> result;
		unordered_set<string> winner;
		for(int i = s;i < m + 1;i+=n){
			while(i < m + 1 && winner.find(v[i]) != winner.end()){
				i++;
			}
			winner.insert(v[i]);
			result.push_back(v[i]);
		}
		if(result.size() == 0){
			cout<<"Keep going..."<<endl;
		}else{
			for(int i = 0; i < result.size();i++){
				cout<<result[i]<<endl;
			}
		}

	}
	return 0;
} 
