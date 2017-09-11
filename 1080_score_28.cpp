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
#include <queue>
using namespace std;
struct P{
	int id;
	int ge;
	int gl;
	int a[5];
	bool isCom;
	bool operator < ( const P& other)const{
		if(ge+gl == other.ge + other.gl){
			return ge > other.ge;
		}else
			return ge + gl > other.ge + other.gl;
	}

	bool operator == (const P& other) const{
		return ge + gl == other.ge + other.gl && ge == other.ge;
	}
};
int main(){
	int n,m,k;
	while(cin>>n>>m>>k){
		vector<int> quota(m);
		for(int i = 0; i < m;i++)
			cin>>quota[i];
		vector<P> v(n);
		for(int i = 0; i < n;i++){
			v[i].id = i;
			cin>>v[i].ge>>v[i].gl;
			for(int j = 0; j < k;j++)
				cin>>v[i].a[j];
		}
		sort(v.begin(),v.end());
		vector<vector<int>> result(m);
		for(int i = 0; i < n;i++){
			if(v[i].isCom) continue;
			for(int j = 0; j < k;j++){
				int school = v[i].a[j]; 
				if(quota[school] > result[school].size()){
					if(i != n-1 && v[i] == v[i+1]){
						P& p = v[i];
						for(int ii = i+1;ii < n;ii++){
							if(v[ii] == p){
								if(v[ii].isCom) continue;
								for(int jj = 0; jj < k;jj++){
									if(v[ii].isCom) break;
									int school = v[ii].a[jj]; 
									if(quota[school] > result[school].size() && jj != j){
										result[school].push_back(v[ii].id);
										v[ii].isCom = true;
										break;
									}else if(jj == j){
										v[ii].isCom = true;
										result[j].push_back(v[ii].id);
										break;
									}
								}
							}else{
								break;
							}
						}
					}
					result[school].push_back(v[i].id);
					v[i].isCom = true;
					break;
				}
			}
		}
		for(int i = 0; i < m;i++){
			int size = result[i].size();
			if(size != 0) sort(result[i].begin(),result[i].end());
			for(int j = 0; j < size;j++){
				cout<<result[i][j];
				cout<<(j == size-1 ? "" : " ");
			}
			cout<<endl;
		}
	}
	return 0;
} 
