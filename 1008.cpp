#include <iostream>
using namespace std;
#define MAX 10005
int a[MAX];
int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n;i++){
			cin >> a[i];
		}
		int sum = n*5;
		int curr = 0;
		for(int i = 0; i < n;i++){
			if(a[i] > curr)
				sum += 6*(a[i] - curr);
			else
				sum += 4*(curr - a[i]);
			curr = a[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}