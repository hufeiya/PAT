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
//注意用getline之前如果存在cin的话要先cin.ingore()清空
int main(){
	int n;
	while(cin>>n){
		cin.ignore();
		vector<string> v;
		string temp;
		for(int i = 0; i < n;i++){
			getline(cin,temp);
			v.push_back(temp);
		}
		string s = "";
		for(int i = 0; i < v[0].length();i++){
			char c = v[0][v[0].length()-i-1];
			for(int j = 1; j < n;j++){
				if(i >= v[j].length() || v[j][v[j].length()-i-1] != c){
					goto end;
				}
			}
			s += c;
		}
end:
		if(s.empty()){
			cout<<"nai\n";
		}else{
			reverse(s.begin(),s.end());
			cout<<s<<endl;
		}
	}
	return 0;
} 
