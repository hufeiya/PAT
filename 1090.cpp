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
using namespace std;
//考察树的层次遍历
int pre[100005];
int sum[100005];
int find(int i){
	if(pre[i] != -1){
		if(sum[i] != 0) return sum[i];
		int times = sum[pre[i]] + 1;
		if(times == 1)
			times = find(pre[i]) + 1;
		sum[i] = times;
		return times;
	}else
		return 0;
}
int main(){
	int n;
	while(cin>>n){
		memset(pre,0,sizeof(int)*n);
		memset(sum,0,sizeof(int)*n);
		unordered_map<int,int> s;
		long double a,b;
		cin>>a>>b;
		for(int i = 0; i < n;i++)
			cin>>pre[i];
		for(int i = 0; i < n;i++){
			int times = find(i);
			s[times]++;
		}
		int max = 0,index = 0;
		unordered_map<int,int>::iterator it = s.begin();
		for(;it != s.end();it++){
			if(it->first > max){
				max = it->first;
				index = it->second;
			}
		}
		if(index == 0) index = 1;
		long double result = a*pow((1 + 0.01*b),max);
		cout<<setprecision(2)<<fixed<<result<<" "<<index<<endl;
	}
	return 0;
} 
