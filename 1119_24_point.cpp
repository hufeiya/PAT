#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int a[35];
int b[35];
bool isUnique;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v){
		left = NULL;
		right = NULL;
	}
};
void dfs(int i ,int j,Node*pre,int len){
	if(i >= len || j < 0) return;
	if(a[i] == b[j]){
		isUnique = false;
		pre->left = new Node(a[i]);
		dfs(i+1,j-1,pre->left,len);
	}else if(i + 1 < len && a[i+1] == b[j]){
		pre->left = new Node(a[i]);
		pre->right = new Node(a[i+1]);
		dfs(i+2,j-1,pre->right,len);
	}else if(i + 1 < len && a[i+1] != b[j]){
		pre->left = new Node(a[i]);
		pre->right = new Node(b[j]);
		dfs(i+1,j-2,pre->left,len);
	}
}
bool first;
void inOrder(Node* node){
	if(node == NULL) return;
	inOrder(node->left);
	if(first)
		first = false;
	else
		cout<<" ";
	cout<<node->val;
	inOrder(node->right);
}
int main(){
	int n;
	while(cin>>n){
		isUnique = true;
		first = true;
		for(int i = 0; i < n;i++) cin>>a[i];
		for(int i = 0; i < n;i++) cin>>b[i];
		Node* root = new Node(a[0]);
		dfs(1,n-2,root,n);
		if(isUnique)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		inOrder(root);
		cout<<endl;
	}
	return 0;
} 
