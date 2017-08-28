#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
//本来用的unordered_set，但是输出要按顺序，就改成了vector，但这样查找太慢了也没时间改了
int main(){
	int n;
	while(cin>>n){
		string s;
		cin>>s;
		vector<char> repeatWords;
		for(int i = 0; i < s.length();i++){
			bool repeat = false;
			int repeatTimes = 1;
			char c = s[i];
			for(int j = i+1;j < s.length();j++){
				if(s[j] == c){
					repeat = true;
					repeatTimes++;
				}else 
					break;
			}
			if(repeatTimes%n == 0){
				vector<char>::iterator index = find(repeatWords.begin(),repeatWords.end(),c);
				if(index == repeatWords.end()){
					repeatWords.push_back(c);
				}
			}else {
				vector<char>::iterator index = find(repeatWords.begin(),repeatWords.end(),c);
				if(index != repeatWords.end()){
					repeatWords.erase(index);
				}
			}
			i += repeatTimes-1;
		}
		string result = "";
		for(int i = 0; i < s.length();i++){
			result += s[i];
			if( find(repeatWords.begin(),repeatWords.end(),s[i]) != repeatWords.end()){
				i += n-1;
			}
		}
		vector<char>::iterator it = repeatWords.begin();
		for(;it != repeatWords.end();it++){
			cout<<*it;
		}
		cout<<endl;
		cout<<result<<endl;
	}
	return 0;
} 
