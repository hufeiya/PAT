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


int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> b[i];
        }
        vector<int> v(a);
        bool isInsert = false;//判断是插入排序
        bool isChange = false;//判断是插入排序之后的第一次改变
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (v[j] < v[k]) {
                    if(isInsert){
                        isChange = true;
                    }
                    int temp = v[j];
                    v[j] = v[k];
                    v[k] = temp;
                }
            }
            if(isInsert && isChange){
                cout<<"Insertion Sort"<<endl;
                for(int i = 0; i < n;i++){
                    cout<<v[i];
                    if(i == n-1){
                        cout<<endl;
                    }else{
                        cout<<" ";
                    }
                }
                break;
            }
            if(! isInsert){
                for(int i = 0; i < n;i++){
                    if(v[i] != b[i]){
                        break;
                    }
                    if(i == n - 1){
                        isInsert = true;
                    }
                }
            }

        }
        if(! isInsert){
            cout<<"Heap Sort"<<endl;
            int heapTailIndex = -1;//堆最末叶子的索引
            for(int i = n - 1;i >= 0;i--){
                if(b[i] < b[0]){
                    heapTailIndex = i;
                    break;
                }
            }
            if(heapTailIndex != -1){
                pop_heap(b.begin(),b.begin()+heapTailIndex + 1);
            }
            for(int i = 0; i < n;i++){
                cout<<b[i];
                if(i == n-1){
                    cout<<endl;
                }else{
                    cout<<" ";
                }
            }
        }


    }
    return 0;
}

