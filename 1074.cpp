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
using namespace std;
/**
*	这一题我用链表做的，但谁用链表做谁傻逼，因为可以用简单的模拟来替代
*	而且时间卡的很紧，用链表如果用string存储的话还超时
*	而且，最后一个测试点很坑，竟然有不在链表上的节点
*/
struct Node{
	int addr;
	int val;
	int next;
	Node(int a,int v,int n):addr(a),val(v),next(n){}
	Node(int a):addr(a){
	val = -1;
	next = -1;
	}
	Node(){}
};
int main(){
	int dummy;
	int n,M;
	while(cin>>dummy>>n>>M){
		unordered_map<int,Node*> m;
		for(int i = 0; i < n;i++){
			Node* node = new Node();
			cin>>node->addr>>node->val>>node->next;
			m[node->addr] = node;
		}
		//大坑，有些节点可能不在链表上，重新计算n
		int temp = dummy;
		for(int i = 0; i < n;i++){
			Node* node = m[temp];
			if(node->next == -1){
				n = i+1;
				break;
			}else
				temp = node->next;
		}
		int pre = dummy;
		for(int i = M; i <= n;i += M){
			Node * start = m[pre];
			if(i != M) start = m[start->next];
			Node* cur = start;
			Node * next = m[cur->next];
			for(int j = 0;j < M-1;j++){
				int temp = next->next;
				next->next = cur->addr;
				cur = next;
				next = m[temp];
				if(j == M - 2) {
					start->next = temp;
					if(i != M){
						m[pre]->next = cur->addr;
					}else{
						dummy = cur->addr;
					}
					pre = start->addr;
				}
			}
		}
		while(n--){
			if(m[dummy]->next == -1)
				printf("%05d %d %d\n",m[dummy]->addr,m[dummy]->val,m[dummy]->next);
			else
				printf("%05d %d %05d\n",m[dummy]->addr,m[dummy]->val,m[dummy]->next);
			if(m[dummy]->next == -1) break;
			dummy = m[dummy]->next;
			
		}
	}
	return 0;
} 
