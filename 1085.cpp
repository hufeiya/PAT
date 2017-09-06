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
long long a[100005];
//排序，两个指针
int main(){
	int n,p;
	while(cin>>n>>p){
		for(int i = 0; i <n;i++)
			cin>>a[i];
		sort(a,a+n);
		int sum = 0;
		for(int i = n - 1,j = n - 1;i >=0 && i <= j;){
			if(a[i]*p >= a[j]){
				sum++;
				i--;
			}else{
				j--;
				i--;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
} 
