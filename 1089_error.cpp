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
using namespace std;
int temp[105];
void merge(vector<int> &v,int p,int q,int r){
	int n1 = q - p;
	int n2 = r - q;
	for(int i = p; i < r;i++)
		temp[i] = v[i];
	int a1 = p,a2 = q;
	for(int i = p;i < r;i++){
		if((a2 >= r) ||(a1 < q && temp[a1] < temp[a2])){
			v[i] = temp[a1];
			a1++;
		}else{
			v[i] = temp[a2];
			a2++;
		}
	}
}
bool findi = false;
bool findj = false;
void mergeSort(vector<int>&v,int p,int r,vector<int>& vv){
	if(p < r -1){
		int q = (p+r)/2;
		if ((p+r) % 2) q++;
		mergeSort(v,p,q,vv);
		mergeSort(v,q,r,vv);
		if(findj) return;
		merge(v,p,q,r);
		if(findi) {
			findj = true;
			return;
		}
		bool same = true;
		for(int i = 0; i < v.size();i++){
			if(v[i] != vv[i]){
				same = false;
				break;
			}
		}
		if(same){
			findi = true;
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		vector<int> v(n);
		vector<int> vv(n);
		for(int i = 0; i < n;i++)
			cin>>v[i];
		for(int i = 0; i < n;i++)
			cin>>vv[i];
		bool isInsertSort = false;
		vector<int> a(v);
		bool equal = true;
		for(int i = 1;i < n;i++){
			equal = true;
			int temp = a[i],j = i-1;
			for(;j >= 0 && a[j] > temp;j--){
				a[j+1] = a[j];
			}
			a[j+1] = temp;
			for(int j = 0;j < n;j++){
				if(equal && a[j] != vv[j]){
					equal = false;
					break;
				}
			}
			if(isInsertSort){
				break;
			}
			if(equal){
				isInsertSort = true;
				equal = false;
			}
		}
		if(isInsertSort){
			cout<<"Insertion Sort"<<endl;
			for(int i = 0; i < n;i++){
				cout<<a[i];
				cout<<(i == n - 1 ? "\n" : " ");
			}
			continue;
		}
		findi = false;
		findj = false;
		mergeSort(v,0,n,vv);
		cout<<"Merge Sort"<<endl;
			for(int i = 0; i < n;i++){
				cout<<v[i];
				cout<<(i == n - 1 ? "\n" : " ");
			}

	}
	return 0;
} 
