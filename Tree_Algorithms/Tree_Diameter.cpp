#include <bits/stdc++.h>
using namespace std;
class node{public:
    int v; 
    vector<node*> children;
    node(int v){this->v = v;}
    
    int h, par;
    void set(int hei, int p){
        h=hei; par=p;
        for(auto &i: children){
            if(i->v == par) continue;
            i->set(h+1, v);
        }
    }

    int dep{0};
    void set_dep(){
        for(auto &i: children){
            if(i->v==par) continue;
            i->set_dep();
            dep = max(dep, 1+i->dep);
        }
    }

    int ans{0};
    void calc_ans(){
        vector<int> depts;
        for(auto &i: children){
            if(i->v==par) continue;
            depts.push_back(i->dep+1);
        }
        ans=max(ans, h+dep);
        sort(depts.begin(), depts.end()); int ds = depts.size();
        if(depts.size()>=2) ans = max(ans, depts[ds-2]+depts[ds-1]);
    }
};
class graph{ public:
    vector<node*> nodes;
    graph(int n){
        for(int i = 0;i<=n;i++) nodes.push_back(new node(i));
    }

};
signed main(){
    int n; cin>>n;
    graph g(n);
    for(int i =1;i<n;i++){
        int a, b; cin>>a>>b;
        g.nodes[a]->children.push_back(g.nodes[b]);
        g.nodes[b]->children.push_back(g.nodes[a]);
    }
    g.nodes[1]->set(0, -1);
    g.nodes[1]->set_dep();
    int ans{0};
    for(auto &i: g.nodes){
        i->calc_ans();
        ans = max(ans, i->ans);
    }
    cout<<ans;
}