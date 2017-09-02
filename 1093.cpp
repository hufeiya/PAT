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
//有O(n)、O(n2)、O(n3)三种复杂度的解法，只有O(n)不超时
int main(){
	string s;
	while(cin>>s){
		int sum = 0,len = s.length();
		vector<int> va(len+1,0);
		vector<int> vt(len+1,0);
		for(int i = len-1; i >= 0;i--){
			if(s[i] == 'T')
				vt[i] = vt[i+1] + 1;
			else
				vt[i] = vt[i+1];
		}
		for(int i = len-1; i >= 0;i--){
			if(s[i] == 'A')
				va[i] = va[i+1] + vt[i+1];
			else
				va[i] = va[i+1];
		}
		for(int i = 0; i < len;i++){
			if(s[i] != 'P') continue;
			sum += va[i+1];
			sum %= 1000000007;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
