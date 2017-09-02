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
struct Node{
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int v):val(v){
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
void printLevel(Node* node,int level,vector<int>& v){
	if(node == NULL) return;
	if(level < 0) return;
	if(level == 0)
		v.push_back(node->val);
	else{
		printLevel(node->left,level-1,v);
		printLevel(node->right,level-1,v);
	}
}
void inOrder(Node*node,vector<int>& v){
	if(node == NULL) return;
	inOrder(node->left,v);
	v.push_back(node->val);
	inOrder(node->right,v);
}
void invertNode(Node* node){
	if(node == NULL) return;
	Node* temp;
	temp = node->left;
	node->left = node->right;
	node->right = temp;
	invertNode(node->left);
	invertNode(node->right);
}
int main(){
	int n;
	while(cin>>n){
		vector<Node*> tree(n);
		for(int i = 0; i < n;i++){
			Node* node = new Node(i);
			tree[i] = node;
		}
		string s1,s2;
		int a1,a2;
		stringstream ss;
		for(int i = 0; i < n;i++){
			cin>>s1>>s2;
			if(s1[0] != '-'){
				ss<<s1;
				ss>>a1;
				ss.clear();
				tree[i]->left = tree[a1];
				tree[a1]->parent = tree[i];
			}
			if(s2[0] != '-'){
				ss<<s2;
				ss>>a2;
				ss.clear();
				tree[i]->right = tree[a2];
				tree[a2]->parent = tree[i];
			}
		}
		int rootIndex;
		for(int i = 0; i < n;i++){
			if(tree[i]->parent == NULL){
				rootIndex = i;
				break;
			}
		}
		invertNode(tree[rootIndex]);
		vector<int>v1,v2;
		for(int i = 0; i < n;i++){
			printLevel(tree[rootIndex],i,v1);
		}
		inOrder(tree[rootIndex],v2);
		for(int i = 0; i <v1.size();i++){
			cout<<v1[i];
			cout<<(i < v1.size()-1 ? " " : "\n");
		}
		for(int i = 0; i <v2.size();i++){
			cout<<v2[i];
			cout<<(i < v2.size()-1 ? " " : "\n");
		}


	}
	return 0;
} 
