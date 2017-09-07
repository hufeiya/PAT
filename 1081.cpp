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
long long gcd(long long a,long long b){
	long long c;
	while(b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main(){
	int n;
	while(cin>>n){
		vector<long long> v1(n);
		vector<long long> v2(n);
		for(int i = 0; i < n;i++){
			cin>>v1[i];
			getchar();
			cin>>v2[i];
			if(v2[i] < 0){
				v2[i] = -v2[i];
				v1[i] = -v1[i];
			}
		}
		long long a = 0,b,c;
		b = v1[0];
		c = v2[0];
		for(int i = 1; i < n;i++){
			b = b * v2[i] + c * v1[i];
			c *= v2[i];
			long long g = abs(gcd(b,c));
			//cout<<"======g"<<g<<" "<<b<<" "<<c<<endl;
			b /= g;
			c /= g;
			a += b/c;
			b %= c;
		}
		if(a != 0) cout<<a;
		if(b != 0 && a != 0) cout<<" ";
		if(b != 0) cout<<b<<"/"<<c<<endl;
		if(b == 0 && a == 0) cout<<0<<endl;

	}
	return 0;
} 
