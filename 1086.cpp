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
struct Node{
	int left,right,val;
	Node(){
		left = -1;
		right = -1;
	}
};
void postOrder(Node node,vector<Node>& v,vector<int>& result){
	if(node.left != -1) postOrder(v[node.left],v,result);
	if(node.right != -1) postOrder(v[node.right],v,result);
	result.push_back(node.val);
}
int main(){
	int n;
	while(cin>>n){
		vector<Node> v(n+1);
		for(int i = 1; i <= n;i++){
			v[i].val = i;
		}
		stack<int> st;
		string s;
		int temp;
		int root = -1,pop = 0;
		for(int i = 1; i <= n;){
			cin>>s;
			if(s.compare("Push") == 0){
				cin>>temp;
				if(root == -1){
					root = temp;
					st.push(temp);
				}else{
					if(pop != 0){
						v[pop].right = temp;
						pop = 0;
					}else{
						v[st.top()].left = temp;
					}
					st.push(temp);
				}
				
			}else if(s.compare("Pop") == 0){
				i++;
				pop = st.top();
				st.pop();
			}
		}
		vector<int>result;
		postOrder(v[root],v,result);
		for(int i = 0;i < result.size();i++){
			cout<<result[i];
			cout<<(i == result.size()-1 ? "\n" : " ");
		}
	}
	return 0;
} 
