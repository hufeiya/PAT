#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
bool isPrime(int num){
	int n = sqrt((double)num);
	for(int i = 2;i < n+1;i++){
		if(num % i == 0) return false;
	}
	return true;
}
int main(){
	int n,m;
	while(cin>>n){
		string temp;
		unordered_map<string,int> rank; 
		for(int i = 0; i < n;i++){
			cin>>temp;
			rank[temp] = i + 1;
		}
		cin>>m;
		while(m--){
			cin>>temp;
			cout<<temp<<": ";
			if(rank.find(temp) == rank.end()){
				cout<<"Are you kidding?"<<endl;
				continue;
			}else if(rank[temp] == -1){
				cout<<"Checked"<<endl;
			}else if(rank[temp] == 1){
				cout<<"Mystery Award"<<endl;
			}else if(isPrime(rank[temp])){
				cout<<"Minion"<<endl;
			}else{
				cout<<"Chocolate"<<endl;
			}
			rank[temp] = -1;
		}
	}
	return 0;
} 
