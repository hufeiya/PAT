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
double a[100005];
//不能硬算，要超时。找规律，第i个数出现(n-i)*(i+1)次
//奇怪为什么用float就是错的
int main(){
	int n;
	while(cin>>n){
		for(int i = 0; i < n;i++)
			scanf("%lf",&a[i]);
		double result = 0;
		for(int i = 0; i < n;i++){
			result += a[i]*(n-i)*(i+1);
		}
		printf("%.2lf\n",result);
	}
	return 0;
} 
