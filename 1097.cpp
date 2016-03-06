#include <iostream>
#include <iomanip>
#include <deque>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Node{
public:
    int val;
    int next;
    Node(){
    }
    Node(int v,int s):val(v),next(s){

    }
};

int main() {
    int firstAddr = -1;
    int n;
    while (cin >> firstAddr >> n) {
        unordered_map<int,Node*> list;
        unordered_set<int> unique;
        unordered_map<int,Node*> duplicate;
        for(int i = 0 ;i < n;i++){
            int addr,next;
            int value;
            cin>>addr>>value>>next;
            list[addr] = new Node(value,next);
        }
        int preAddr = firstAddr,curentAddr = firstAddr,preDupAddr = -1,firDupAddr = -1;
        for(int i = 0;i < n;i++){
            if(unique.find(abs(list[curentAddr]->val)) == unique.end()){
                unique.insert(abs(list[curentAddr]->val));
                if((i == n-1 || list[curentAddr]->next == -1) && preDupAddr != -1){
                    duplicate[preDupAddr]->next = -1;
                }
                preAddr = curentAddr;

            }else{
                list[preAddr]->next = list[curentAddr]->next;
                if(preDupAddr != -1){
                    duplicate[preDupAddr]->next = curentAddr;
                }else{
                    firDupAddr = curentAddr;
                }
                duplicate[curentAddr] = list[curentAddr];
                if((i == n-1 || list[curentAddr]->next == -1)){
                    list[preAddr]->next = -1;
                }
                preDupAddr = curentAddr;
            }
            curentAddr = list[curentAddr]->next;
            if(curentAddr == -1){
                break;
            }
        }
        while(firstAddr!= -1 && firstAddr != -1){
            if(list[firstAddr]->next != -1){
                printf("%05d %d %05d\n",firstAddr,list[firstAddr]->val,list[firstAddr]->next);
            }else{
                printf("%05d %d %d\n",firstAddr,list[firstAddr]->val,list[firstAddr]->next);
            }

            firstAddr = list[firstAddr]->next;
        }
        while(firDupAddr != -1 && firDupAddr != -1){
            if(duplicate[firDupAddr]->next != -1){
                printf("%05d %d %05d\n",firDupAddr,duplicate[firDupAddr]->val,duplicate[firDupAddr]->next);
            }else{
                printf("%05d %d %d\n",firDupAddr,duplicate[firDupAddr]->val,duplicate[firDupAddr]->next);
            }

            firDupAddr = duplicate[firDupAddr]->next;
        }

    }
    return 0;
}

