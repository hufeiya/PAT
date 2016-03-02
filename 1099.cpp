#include <iostream>
#include <string>
#include <iomanip>
#include <deque>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(){
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
public:
    Node* root;
    vector<int> v;
    int index;
    BinaryTree(){
        index = 0;
    }
    void inOrder(Node *node){
        if(node){
            inOrder(node->left);
            node->val = v[index++];
            inOrder(node->right);
        }
    }
    void levelOrder(){
        queue<Node*>q;
        q.push(root);
        //Node*node = root;
        while(index --){
            Node* node  = q.front();
            cout<<node->val;
            if(index){
                cout<<" ";
            }else{
                cout<<endl;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            q.pop();
        }
    }
};

struct cmp{
    bool operator()(int &a,int &b){
        return a > b;
    }
};

int main() {
    int n;
    while(cin >> n){
        BinaryTree* tree = new BinaryTree();
        if(n == 0){
            continue;
        }
        Node *nodes = new Node[n];
        for(int i = 0 ;i < n;i++){
            int left,right;
            cin>>left>>right;
            if(left != -1){
                nodes[i].left = &nodes[left];
            }
            if(right != -1){
                nodes[i].right = &nodes[right];
            }
        }
        tree->root = &nodes[0];
        for(int i = 0;i < n;i++){
            int x;
            cin >> x;
            tree->v.push_back(x);
        }
        sort(tree->v.begin(),tree->v.end());
        tree->inOrder(tree->root);
        tree->levelOrder();
        delete tree;
        delete[] nodes;
    }
    return 0;
}

