#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int a[100050];
int main(){
	int n;
	while(cin>>n){
		for(int i = 0; i < n;i++)
			cin>>a[i];
		sort(a,a+n);
		int sum1 = 0,sum2 = 0;
		for(int i = 0; i < n;i++)
			if(i < n / 2)
				sum1 += a[i];
			else
				sum2 += a[i];
		cout<<(n % 2 ? 1 : 0)<<" "<<sum2-sum1<<endl;

	}
	return 0;
} 
