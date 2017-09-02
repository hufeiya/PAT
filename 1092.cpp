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
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		unordered_map<char,int> m;
		for(int i = 0; i < s2.length();i++)
			m[s2[i]]++;
		for(int i = 0;i < s1.length();i++)
			m[s1[i]]--;
		bool answer = true;
		int sum = 0;
		for(int i = 0; i < s2.length();i++){
			if(m[s2[i]] > 0){
				answer = false;
				sum += m[s2[i]];
				m[s2[i]] = 0;
			}
		}
		if(answer){
			cout<<"Yes "<<s1.length() - s2.length()<<endl;
		}else{
			cout<<"No "<<sum<<endl;
		}
		
	}
	return 0;
} 
