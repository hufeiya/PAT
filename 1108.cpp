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
#include <exception>
using namespace std;
bool isLegal(string& s){
	bool havePoint = false;
	int i = 0;
	if(s[0] == '+' || s[0] == '-')
		i = 1;
	else if(s[0] < '0' || s[0] > '9')
		return false;
	for(; i < s.length();i++){
		if(s[i] == '.'){
			if(havePoint)
				return false;
			else{
				havePoint = true;
				if(i == 0 || (i == 1 && (s[0] == '+' || s[0] == '-'))) return false;
				if(i + 3 < s.length())
					return false;
			}
		}else if(s[i] < '0' || s[i] > '9'){
			return false;
		}
	}
	stringstream ss;
	double temp;
	ss<<s;
	ss>>temp;
	if(temp < -1000 || temp > 1000) return false;
	return true;
}
int main(){
	int n;
	while(cin>>n){
		string s;
		stringstream ss;
		double sum = 0,temp;
		int num = 0;
		for(int i = 0 ;i <n;i++){
			cin>>s;
			if(isLegal(s)){
				ss<<s;
				ss>>temp;
				ss.clear();
				sum += temp;
				num++;
			}else{
				cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
			}
		}
		if(num == 0)
			cout<<"The average of 0 numbers is Undefined"<<endl;
		else if(num == 1)
			cout<<"The average of "<<num<<" number is "<<setprecision(2)<<fixed<<sum<<endl;
		else
			cout<<"The average of "<<num<<" numbers is "<<setprecision(2)<<fixed<<sum/num<<endl;
	}
	return 0;
} 
