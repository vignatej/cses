#include <bits/stdc++.h>
using namespace std;

class node{public:
    int v;
    vector<node*> children;
    
    pair<int, int> calc(int par){
        vector<pair<int, int>> yn;
        for(auto &i: children){
            if(i->v==par) continue;
            yn.push_back(i->calc(v));
        }
        int n{0};
        for(auto &i: yn) n+=i.first;
        int y{n};
        for(auto &i: yn){
            int cy = n; cy-=i.first;
            cy+=i.second+1;
            y=max(cy, y);
        }
        // if(max(y, n)==0) if(children.size()) return {1, 0};
        return {max(y, n), n};
    }
};
class graph{ public:
    vector<node*> nodes;
    graph(int n){
        for(int i = 0;i<=n;i++) nodes.push_back(new node());
        for(int i = 0;i<=n;i++) nodes[i]->v=i;
    }
    void add_edge(int a, int b){
        nodes[a]->children.push_back(nodes[b]);
        nodes[b]->children.push_back(nodes[a]);
    }
};

signed main(){
    int n; cin>>n;
    graph g(n);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        g.add_edge(a, b);
    }
    cout<<(g.nodes[1]->calc(-1)).first;

}