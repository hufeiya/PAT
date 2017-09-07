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
struct P
{
	string name;
	string no;
	int grade;
	bool operator < (const P& p) const{
		return grade > p.grade;
	}
};
int main(){

	int n;
	while(cin>>n){
		vector<P> v(n);
		string name,no;
		int grade,l,h;
		for(int i = 0; i < n;i++){
			cin>>name>>no>>grade;
			v[i].name = name;
			v[i].no = no;
			v[i].grade = grade;
		}
		cin>>l>>h;
		if(l > h){
			cout<<"NONE\n";
			continue;
		}
		sort(v.begin(),v.end());
		int a1 = -1,a2 = -1;
		for(int i = 0; i < n;i++){
			if(a2 == -1 && v[i].grade <= h){
				a2 = i;
			}
			if(v[i].grade >= l){
				a1 = i;
			}
		}
		if(a1 == -1 || a2 == -1 || a1 < a2){
			cout<<"NONE\n";
			continue;
		}
		for(int i = a2;i <= a1;i++){
			cout<<v[i].name<<" "<<v[i].no<<endl;
		}

	}
	return 0;
} 
