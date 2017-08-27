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
		vector<int> v(n+1);
		for(int i = 1; i <= n;i++){
			cin>>v[i];
		}
		sort(v.begin()+1,v.end());
		int result = 0;
		for(int i = n ; i > 0;i--){
			if(v[n - i + 1] > i ){
				result = i;
				break;
			}
		}
		cout<<result<<endl;
	}
	return 0;
} 
