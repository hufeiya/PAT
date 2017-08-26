#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Node{
	Node* left;
	Node* right;
	int val;
	Node(int v):val(v){
		left = NULL;
		right = NULL;
	}
};
int a[40];
int b[40];
int findPos(int *a,int low,int high,int target){
	for(int i = low; i <= high;i++)
		if(a[i] == target) return i;
}
Node* dfs(int *a,int *b,int low,int high,int index){
	if(low > high) return NULL;
	Node * node = new Node(b[index]);
	if(low == high) return node;
	int pos = findPos(a,low,high,b[index]);
	node->left = dfs(a,b,low,pos-1,index-1-(high-pos));
	node->right = dfs(a,b,pos+1,high,index-1);
	return node;
}

int printLevel(Node*node,int level,Node*root,vector<int> & v){
	if(node == NULL || level < 0) return 0;
	if(level == 0){
		v.push_back(node->val);
		return 1;
	}
	return printLevel(node->left,level-1,root,v) + printLevel(node->right,level-1,root,v);
}
int main(){
	int n;
	while(cin>>n){
		for(int i = 0;i < n;i++) cin>>a[i];
		for(int i = 0;i < n;i++) cin>>b[i];
		Node* root = dfs(a,b,0,n-1,n-1);
		vector<int> v;
		for(int i = 0; i < n;i++){
			vector<int> singleLevel;
			if(printLevel(root,i,root,singleLevel) == 0) break;
			if(i % 2 == 0) reverse(singleLevel.begin(),singleLevel.end());
			v.insert(v.end(),singleLevel.begin(),singleLevel.end());
		}
		for(int i = 0; i < v.size();i++){
			if(i != 0) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
	
	return 0;
} 
