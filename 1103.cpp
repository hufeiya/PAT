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
vector<int> v;
vector<int>tempv;
vector<int> ans;
int n,k,p,m;
int maxfac = -1;
void init(){
	for(int i = 0; i < m;i++){
		v.push_back(pow((double)i,p));
	}
}
void dfs(int t,int sum,int facsum,int former){
	if(t == 0){
		if(sum != n) return;
		if(facsum > maxfac){
			maxfac = facsum;
			ans = tempv;
		}else if(facsum == maxfac){
			for(int i = ans.size()-1;i >= 0; i--){
				if(ans[i] < tempv[i]){
					ans = tempv;
					break;
				}else if(ans[i] > tempv[i])
					break;
			}
		}
	}else{
		for(int i = former; i < m;i++){
			if(sum + v[i] > n - t + 1) break;
			tempv.push_back(i);
			dfs(t-1,sum + v[i],facsum + i,i);
			tempv.pop_back();
		}
	}
}
int main(){

	cin>>n>>k>>p;
	m = pow(n,1.0/p) + 1;
	init();
	dfs(k,0,0,1);
	if(maxfac == -1){
		cout<<"Impossible\n";
		return 0;
	}
	//sort(ans.begin(),ans.end());
	cout<<n<<" = ";
	for(int i = ans.size()-1;i >= 0;i--){
		cout<<ans[i]<<'^'<<p<<(i == 0 ? "\n" : " + ");
	}
	system("pause");
	return 0;
} 
