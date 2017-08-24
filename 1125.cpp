#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		double temp;
		multiset<double> s;
		for(int i = 0; i < n;i++){
			cin>>temp;
			s.insert(temp);
		}
		double a,b,c;
		while(s.size() > 1){
			multiset<double>::iterator it = s.begin();
			a = *it;
			s.erase(it);
			it = s.begin();
			b = *it;
			s.erase(it);
			c = (a+b)/2;
			s.insert(c);
		}
		cout<<int(*s.begin())<<endl;
	}
	return 0;
} 
