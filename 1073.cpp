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
int main(){
	string s;
	while(cin>>s){
		bool postive = true;
		int start = 0;
		if(s[0] == '-'){
			postive = false;
			start = 1;
		}else if(s[0] == '+')
			start = 1;
		string x;
		int y;
		for(int i = start;i < s.length();i++){
			if(s[i] == 'E'){
				string sub = s.substr(start,i-1);
				x = sub;
				stringstream ss;
				sub = s.substr(i+1,s.length());
				ss<<sub;
				ss>>y;
				break;
			}
		}
		string result = "";
		if(y < 0){
			for(int i = 0; i <x.length();i++){
				if(x[i] == '.'){
					x.erase(i,1);
					if(i - abs(y) > 0){
						string::iterator it = x.begin() + i-abs(y);
						x.insert(it,'.');
					}else{
						x = "0." + string(abs(y)-i,'0') + x;
					}
					break;
				}

			}
		}else{
			int len,pos;
			for(int i = 0; i <x.length();i++){
				if(x[i] == '.'){
					pos = i;
					len = x.length()-i-1;
					x.erase(i,1);
					break;
				}
			}
			if(y-len > 0)
				x += string(y-len,'0');
			else{
				string::iterator it = x.begin() + pos + y;
				x.insert(it,'.');
			}
			for(int i = 0; i < x.length() - 1;i++){
				if(x[i] == '0' && x[i+1] != '.'){
					x.erase(i,1);
					i--;
				}else{
					break;
				}
			}
			if(x[x.length()-1] == '.')
				x.erase(x.length()-1,1);
		}
		if(!postive) cout<<'-';
		cout<<x<<endl;
	}
	return 0;
} 
