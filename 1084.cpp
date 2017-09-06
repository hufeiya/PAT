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
//注意大小写问题，只要一个键坏了大写小写都打不出来了
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		unordered_set<char> us;
		vector<char> result;
		for(int i = 0; i < s2.length();i++){
			if(s2[i] >= 97 && s2[i] < 123)
				s2[i] -= 32;
			us.insert(s2[i]);
		}
		for(int i = 0; i < s1.length();i++){	
			if(s1[i] >= 97 && s1[i] < 123)
				s1[i] -= 32;
			if(us.find(s1[i]) == us.end()){
				result.push_back(s1[i]);
				us.insert(s1[i]);
			}
		}
		for(int i = 0; i < result.size();i++){
			if(result[i] >= 97 && result[i] < 123)
				result[i] -= 32;
			cout<<result[i];
		}
		cout<<endl;
	}
	return 0;
} 
