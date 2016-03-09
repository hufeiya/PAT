#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXINT = 2147483647;
const int NIL = -1;
class Node{
public:
    vector<Node*>children;
};

int a[105];
void dfs(Node* node,int num){
    if(node->children.empty()){
        if(a[num] == NIL){
            a[num] = 0;
        }
        a[num]++;
    }
    for(int i = 0; i < node->children.size();i++){
        dfs(node->children[i],num+1);
    }
}
int main() {
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 || m == 0){
            cout<<1<<endl;
            continue;
        }
        memset(a,NIL,sizeof(a));
        unordered_map<int,Node*> um;
        for(int  i = 0 ;i < m;i++){
            int index,num;
            cin>>index>>num;
            if(um.find(index) == um.end()){
                um[index] = new Node();
            }
            Node* parent = um[index];
            for(int j = 0; j < num;j++){
                int child;
                cin >> child;
                if(um.find(child) == um.end()){
                    um[child] = new Node();
                }
                parent->children.push_back(um[child]);
            }
        }
        dfs(um[1],0);
        int last = 0;
        for(int i = 0;i < n;i++){
            if(a[i] != -1){
                last = i;
            }
        }
        for(int i = 0;i < last;i++){
            if(a[i] == -1){
                a[i] = 0;
            }
        }
        for(int i = 0;i < n;i++){
            if(a[i] == -1){
                cout<<endl;
                break;
            }
            if(i != 0){
                cout<<" ";
            }
            cout<<a[i];
        }
    }
    return 0;
}

