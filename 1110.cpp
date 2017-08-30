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
//判断是否是完全二叉树，我的方法是先算出总共n层，再前序遍历，
//如果小于n层时有空节点就是非完全，等于n层时再判断是不是从左到右有
//空节点出现后还有非空节点，如果有那就是非完全
struct Node{
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int v){
		val = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};
int getLevel(Node*node,int level){
	if(node == NULL) return level;
	return max(getLevel(node->left,level+1),getLevel(node->right,level+1));
}
int result;
bool findLast;
void levelOrder(Node* node,int cur,int level){
	if(cur < level){
		if(node == NULL){
			result = -1;
		}else{
			levelOrder(node->left,cur+1,level);
			levelOrder(node->right,cur+1,level);
		}
	}else{
		if(node == NULL){
			if(!findLast){
				findLast = true;
			}
		}else{
			if(findLast){
				result = -1;
			}else if(result != -1){
				result = node->val;
			}
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		vector<Node*> v(n);
		for(int i = 0; i < n;i++)
			v[i] = new Node(i);
		string a,b;
		int x,y;
		for(int i = 0; i < n;i++){
			cin>>a>>b;
			stringstream ss;
			if(a[0] != '-'){
				ss<<a;
				ss>>x;
				ss.clear();
				v[i]->left = v[x];
				v[x]->parent = v[i];
			}
			if(b[0] != '-'){
				ss<<b;
				ss>>y;
				ss.clear();
				v[i]->right = v[y];
				v[y]->parent = v[i];
			}
		}
		Node* root;
		for(int i = 0; i < n;i++)
			if(v[i]->parent == NULL){
				root = v[i];
				break;
			}
		int level = getLevel(root,0);
		findLast = false;
		levelOrder(root,1,level);
		if(result == -1){
			cout<<"NO "<<root->val<<endl;
		}else{
			cout<<"YES "<<v[result]->val<<endl;
		}

	}
	return 0;
} 
