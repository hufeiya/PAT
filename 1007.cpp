#include <iostream>
using namespace std;
#define MAX 10005
int a[MAX];
int start[MAX];
int s[MAX];
int main(){
	int n;
	while(cin >> n){
		bool allNeg = true;
		for(int i = 0; i < n;i++){
			cin>>a[i];
			if(allNeg && a[i] >= 0)
				allNeg = false;
		}
		if(allNeg){
			cout<<0<<" "<<a[0]<<" "<<a[n-1]<<endl;
			continue;
		}
		s[0] = a[0];
		start[0] = 0;
		for(int i = 1;i < n;i++){
			if(s[i-1] >= 0){
				s[i] = s[i-1] + a[i];
				start[i] = start[i-1];
				//if(s[i-1] == 0) start[i] = i;
			}else{
				s[i] = a[i];
				start[i] = i;
			}
		}
		int max = -1,st,ed;
		for(int i = 0; i < n;i++){
			if(s[i] > max){
				max = s[i];
				ed = i;
			}
		}
		st = start[ed];
		cout<<max<<" "<<a[st]<<" "<<a[ed]<<endl;

	}
	return 0;
}