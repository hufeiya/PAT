#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node{
	string val;
	Node *left;
	Node *right;
	Node *parent;
	int a,b;
	Node(string v,int x,int y):val(v),a(x),b(y){
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void infixOrder(Node* node){

	bool need = false;
	if(node->b != -1 && node->parent != NULL){
		need = true;
	}
	if(need) cout<<"(";
	if(node->a != -1){
		infixOrder(node->left);
	}
	cout<<node->val;
	if(node->b != -1){
		infixOrder(node->right);
	}
	if(need) cout<<")";
}
int main(){
	int n;
	while(cin >> n){
		vector<Node*> v(n+1);
		for(int i = 1;i < n+1;i++){
			string a;
			int b,c;
			cin>>a>>b>>c;
			Node* node = new Node(a,b,c);
			v[i] = node;
		}
		for(int i = 1; i < n+1;i++){
			if(v[i]->a != -1){
				v[i]->left = v[v[i]->a];
				v[v[i]->a]->parent = v[i];
			}
			if(v[i]->b != -1){
				v[i]->right = v[v[i]->b];
				v[v[i]->b]->parent = v[i];
			}
		}
		Node* root;
		for(int i = 1;i < n+1;i++){
			if(v[i]->parent == NULL){
				root = v[i];
				break;
			}
		}
		infixOrder(root);
		for(int i = 1; i < n+1;i++){
			delete v[i];
		}
	}
	
	return 0;
} 
