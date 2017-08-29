#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;
//就是构建BST和层次遍历，最水的30分题，做的有些快代码很不优雅
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v){
		left = NULL;
		right = NULL;
	}
};

int max(int x,int y){
	if(x > y)
		return x;
	else
		return y;
}
int maxDepth(Node* node){
	if(node == NULL) return 0;
	return max(maxDepth(node->left) + 1,maxDepth(node->right) + 1);
}

int levelNum(Node*node,int level){
	if(node == NULL) return 0;
	if(level == 1) return 1;
	return levelNum(node->left,level-1) + levelNum(node->right,level-1);
}
int main(){
	int n;
	while(cin>>n){
		int temp;
		Node *root,*cur,*newNode;
		for(int i = 0; i < n;i++){
			cin>>temp;
			if(i == 0){
				root = new Node(temp);
				cur = root;
			}else{
				newNode = new Node(temp);
				cur = root;
				while(cur != NULL){
					if(temp <= cur->val){
						if(cur->left == NULL){
							cur->left = newNode;
							break;
						}else{
							cur = cur->left;
						}
					}else{
						if(cur->right == NULL){
							cur->right = newNode;
							break;
						}else{
							cur = cur->right;
						}
					}
				}
			}
		}
		int max = maxDepth(root);
		int first = levelNum(root,max),second = levelNum(root,max-1);
		cout<<first<<" + "<<second<<" = "<<first+second<<endl;
	}
	return 0;
} 
