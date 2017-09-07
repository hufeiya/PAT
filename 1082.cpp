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
//字符处理，需要考虑的情况较多，用了40分钟，哎
bool allZero(int index,string & s){
	for(int i = index;i < s.length();i++){
		if((s.length()-i) % 4 == 0) break;
		if(s[i] != '0') return false;
	}
	return true;
}
bool allZero2(int index,string & s){
	for(int i = index;i < s.length();i++){
		if(s[i] != '0') return false;
	}
	return true;
}
int main(){
	unordered_map<char,string> m;
	m['0'] = "ling";
	m['1'] = "yi";
	m['2'] = "er";
	m['3'] = "san";
	m['4'] = "si";
	m['5'] = "wu";
	m['6'] = "liu";
	m['7'] = "qi";
	m['8'] = "ba";
	m['9'] = "jiu";
	unordered_map<int,string> mm;
	mm[2] = "Shi";
	mm[3] = "Bai";
	mm[4] = "Qian";
	mm[5] = "Wan";
	mm[6] = "Shi";
	mm[7] = "Bai";
	mm[8] = "Qian";
	mm[9] = "Yi";
	string s;
	while(cin>>s){
		if(allZero2(0,s)){
			cout<<"ling\n";
			continue;
		}
		int flag = 0;
		for(int i = 0; i < s.length();i++){
			if(i == 0 && s[i] == '-'){
				cout<<"Fu";
				continue;
			}
			int bit = s.length() - i;
			if(s[i] == '0'){
				if(!allZero(i+1,s)){
					cout<<' '<<m['0'];
				}
				else if(mm.find(bit) != mm.end()){
					if(flag > 0){
					 flag--;
					}
					else{
						flag = (bit-1) % 4;
						if(flag > 0){
							flag--;
						}else
							cout<<' '<<mm[bit];
					}
				}
			}else{
				if(i != 0) cout<<' ';
				cout<<m[s[i]];
				if(mm.find(bit) != mm.end()){
					cout<<' '<<mm[bit];
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 
