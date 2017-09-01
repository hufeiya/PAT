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
using namespace std;
//dfs，这个要剪枝，采用路径压缩，就是下面的函数，不然有一个用例超时
int get(int x,vector<int> & v,vector<int>& time){
	if(v[x] != -1){
		time[x] =  get(v[x],v,time) + 1;
		v[x] = -1;
		return time[x];
	}else{
		return time[x];
	}
}
int main(){
	int N;
	double P,r;
	while(cin>>N>>P>>r){
		vector<int> v(N,-1);
		vector<int> time(N,0);
		vector<int> retailer;
		for(int i = 0;i < N;i++){
			int num,temp;
			cin>>num;
			if(num == 0) retailer.push_back(i);
			while(num--){
				cin>>temp;
				v[temp] = i;
			}
		}
		vector<int> num(retailer.size(),0);
		for(int i = 0; i < retailer.size();i++){
			num[i] = get(retailer[i],v,time);
		}
		int min = 9999999;
		for(int i = 0; i < retailer.size();i++){
			if(num[i] < min){
				min = num[i];
			}
		}
		int sum = 0;
		for(int i = 0; i < retailer.size();i++){
			if(num[i] == min) sum++;
		}
		cout<<setprecision(4)<<fixed<<P*pow((1+0.01*r),min)<<" "<<sum<<endl;
	}
	return 0;
} 
