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
using namespace std;
const int MAX = 100005;
bool prime[MAX];
//主要要记住散列开放寻址法中的二次探查公式，hi=(h(key)+i*i)％m 0≤i≤m-1 即di=i2
void makePrime(int n){
	memset(prime,1,sizeof(prime));
	prime[0] = false;
	prime[1] = false;
	for(int i = 2;i < n;i++){
		if( ! prime[i]) continue;
		for(int j = i * i; j < n && j > 0;j += i){
			prime[j] = false;
		}
	}
}
int main(){
	int msize;
	int n;
	while(cin>>msize>>n){
		makePrime(MAX);
		for(int i = msize;i < MAX;i++){
			if(prime[i]){
				msize = i;
				break;
			}
		}
		vector<int >v(n);
		for(int i = 0; i <n;i++)
			cin>>v[i];
		vector<bool> hash(msize,false);
		for(int i = 0; i < n;i++){
			bool find = false;
			for(int j = 0;j < msize;j++){
				int p = (v[i] + j*j)%msize;
				if( ! hash[p]){
					v[i] = p;
					hash[p] = true;
					find = true;
					break;
				}
			}
			if(!find) v[i] = -1;
		}
		for(int i = 0; i < n;i++){
			if(v[i] == -1)
				cout<<'-';
			else
				cout<<v[i];
			cout<<(i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
} 
