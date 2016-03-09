#include <iostream>
#include <deque>
#include <queue>
#include <unordered_map>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXINT = 2147483647;
int w[505][505];
int startIndex,endIndex,maxPeople,number;
class City{
public:
    int index;
    int people;
    int dist;
    vector<City*> prev;
    City(int index,int people){
        this->index = index;
        this->people = people;
        dist = MAXINT;
    }

};

void relax(City*u,City* v){
    if(w[u->index][v->index] == -1){
        return;
    }
    if(v->dist >= u->dist + w[u->index][v->index]) {
        if (v->dist > u->dist + w[u->index][v->index]) {
            v->prev.clear();
            v->dist = u->dist + w[u->index][v->index];
        }
        v->prev.push_back(u);
    }
}

void dfs(City* city,int people){
    if(city->index == startIndex){
        number++;
        if(people + city->people > maxPeople){
            maxPeople = people + city->people;
        }
        return;
    }
    for(int i = 0;i < city->prev.size();i++){
        dfs(city->prev[i],city->people + people);
    }
}
int main() {
    int n,m,c1,c2;
    while(cin >> n >> m >> c1 >> c2) {
        startIndex = c1;
        endIndex = c2;
        maxPeople = 0;
        number = 0;
        memset(w,-1,sizeof(w));
        vector<City*> all(n);
        unordered_map<int,City*> um;
        for(int i = 0;i < n;i++){
            int people;
            cin >> people;
            all[i] = new City(i,people);
            um[i] = all[i];
        }
        for(int i = 0;i < m;i++){
            int a,b,dis;
            cin>>a>>b>>dis;
            if(w[a][b] == -1 || w[a][b] > dis){
                w[a][b] = dis;
                w[b][a] = dis;
            }

        }
        all[c1]->dist = 0;
        while(!um.empty()){
            int minIndex = MAXINT,minLen = MAXINT;
            unordered_map<int,City*>::iterator iter = um.begin();
            for(;iter != um.end();++iter){
                if(iter->second->dist < minLen){
                    minIndex = iter->first;
                    minLen = iter->second->dist;
                }
            }
            City* u = um[minIndex];
            um.erase(minIndex);

            for(iter = um.begin();iter != um.end();++iter) {
                relax(u,iter->second);
            }

        }
        dfs(all[c2],0);
        cout<<number<<" "<<maxPeople<<endl;
        for(int i = 0;i < all.size();i++){
            delete all[i];
        }
    }
    return 0;
}

