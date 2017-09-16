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
struct Node{
	int val;
	int level;
	Node*left;
	Node*right;
	Node(int v){
		val = v;
		level = 0;
		left = NULL;
		right = NULL;
	}
};
int getHeight(Node*node){
	if(node == NULL) return 0;
	return node->level;
}
void calHeight(Node* node){
	if(node == NULL) return;
	node->level =  max(getHeight(node->left),getHeight(node->right)) + 1;
}
Node* LLRotate(Node* node){
	Node* left = node->left;
	node->left = left->right;
	left->right = node;
	calHeight(node);
	calHeight(left);
	return left;
}
Node* RRRotate(Node* node){
	Node* right = node->right;
	node->right = right->left;
	right->left = node;
	calHeight(node);
	calHeight(right);
	return right;
}
Node* LRRotate(Node* node){
	node->left = RRRotate(node->left);
	return LLRotate(node);
}
Node* RLRotate(Node* node){
	node->right = LLRotate(node->right);
	return RRRotate(node);
}
Node* insert(Node* root,int val){
	if(root == NULL){
		root = new Node(val);
	}else if(val < root->val){
		root->left = insert(root->left,val);
		if(getHeight(root->left) - getHeight(root->right) == 2){
			if(val < root->left->val){
				root = LLRotate(root);
			}else{
				root = LRRotate(root);
			}
		}
	}else{
		root->right = insert(root->right,val);
		if(getHeight(root->left) - getHeight(root->right) == -2){
			if(val > root->right->val){
				root = RRRotate(root);
			}else{
				root = RLRotate(root);
			}
		}
	}
	calHeight(root);
	return root;
}
int main(){
	int n,temp;
	cin>>n;
	Node* node = NULL;
	while(n--){
		cin>>temp;
		node = insert(node,temp);
	}
	cout<<node->val<<endl;
	system("pause");
	return 0;
} 
