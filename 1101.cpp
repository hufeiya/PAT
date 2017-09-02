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
//这个坑爹的dp水题，就前后扫两次存储当前最大最小节点，但如果没有满足的元素要输出0和两个回车，
//不然测试点3会格式错误！测试点3还占4分。。。。。。。
int main(){
	int n;
	while(cin>>n){
		vector<int> v(n);
		vector<int> max(n,0);
		vector<int> min(n,2147483647);
		for(int i = 0; i < n;i++){
			cin>>v[i];
		}
		if(n == 1){
			cout<<1<<endl;
			cout<<v[0]<<endl;
			continue;
		}
		max[0] = v[0];
		min[n-1] = v[n-1];
		for(int i = 1; i <n;i++)
			max[i] = max[i-1] < v[i] ? v[i] : max[i-1];
		for(int i = n - 2; i >= 0;i--)
			min[i] = min[i+1] > v[i] ? v[i] : min[i+1];
		vector<int> result;
		for(int i = 0; i < n;i++){
			if((i == 0 && min[i+1] > v[i]) || 
				(i > 0 && i < n - 1 && max[i-1] < v[i] && min[i+1] > v[i]) || 
				(i == n - 1 && max[i-1] < v[i]))
				result.push_back(v[i]);
		}
		sort(result.begin(),result.end());
		cout<<result.size()<<endl;
		for(int i = 0; i < result.size();i++){
			cout<<result[i];
			cout<<(i < result.size()-1 ? " " : "\n");
		}
		if(result.size() == 0)
			cout<<endl;
	}
	return 0;
} 
