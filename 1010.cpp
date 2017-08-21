#include <iostream>
#include <string>
using namespace std;

long long binarySearch(const string& n2,long long low,long long high,long long target){
	if(low >= high) return 0;
	long long mid = (low + high)/2;
	int i = n2.length();
	long long int sum2 = 0,re = 1;
	bool flag = false;
	while (i--){
		if(n2[i] <= '9'){
			if(n2[i] - '0' >= mid) {
				break;						
			}
			sum2 += (n2[i] - '0')*re;
		}else{
			if(n2[i] - 87 >= mid){
				break;						
			}
			sum2 += (n2[i] - 87)*re;
		}
		re *= mid;
		if(re < 0 || sum2 > target){
			return binarySearch(n2,low,mid,target);
		}
	}
	if(sum2 == target){
		return mid;
	}else if(sum2 > target){
		return binarySearch(n2,low,mid,target);
	}else{
		return binarySearch(n2,mid+1,high,target);
	}
}

int main(){
	string n1,n2;
	long long tag,redix;
	while(cin>>n1>>n2>>tag>>redix){
		if(n1.length() == 1 && n2.length() == 1){
			if(n1[0] =='1' && n2[0] == '1'){
				cout<<"2"<<endl;
				continue;
			}
		}
		string target = tag == 1 ? n1 : n2;
		string other = tag == 1 ? n2 : n1;
		int i = target.length();
		long long int sum1 = 0,re = 1;
		while (i--){
			if(target[i] <= '9'){
				sum1 += (target[i] - '0')*re;
			}else{
				sum1 += (target[i] - 87)*re;
			}
			re *= redix;
		}
		long long int result = 0;
		for(int j = 1; j <= 10000000;j++){
			int i = other.length();
			long long int sum2 = 0,re = 1;
			bool flag = false;
			while (i--){

				if(other[i] <= '9'){
					if(other[i] - '0' >= j) {
						flag = true;
						break;            
					}
					sum2 += (other[i] - '0')*re;
				}else{
					if(other[i] - 87 >= j){
						flag = true;
						break;            
					}
					sum2 += (other[i] - 87)*re;
				}
				re *= j;
				if(re < 0){
					flag = true;
					break;
				}
			}
			if(flag) continue;
			if(sum2 == sum1){
				result = j;
				break;
			}
		}
		if(result != 0){
			cout<<result<<endl;
			continue;
		}
		result = binarySearch(other,1,9223372036854775807,sum1);
		if(result == 0)
			cout<<"Impossible"<<endl;
		else
			cout<<result<<endl;
	}
	return 0;
}
