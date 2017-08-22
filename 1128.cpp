#include <iostream>
#include <string>
using namespace std;
int a[1005];
int main(){
	int k,n;
	while(cin>>k){
		while(cin>>n){
			for(int i = 0;i < n;i++){
				cin>>a[i];
			}
			int result = true;
			for(int i = 0; i < n;i++){
				for(int j = 0; j < i;j++){
					if(a[i] - a[j] == i-j || a[i]-a[j] == j - i || a[i] == a[j]){
						result = false;
						goto end;
					}
				}
			}
end:
			cout<<(result? "YES":"NO")<<endl;
		}
	}
	return 0;
}
