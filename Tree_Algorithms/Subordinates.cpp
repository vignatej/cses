#include <bits/stdc++.h>
using namespace std;
class node{public:
    int val;
    vector<node*> child;
    int saved{-1};
    int get_ans(){
        if(saved!=-1) return saved;
        int ans{0};
        for(auto &i: child) ans+=i->get_ans();
        saved = ans+1;
        return saved;
    }
};
class graph{public:
    vector<node*> v;
    graph(int n){
        for(int i = 0;i<=n;i++){
            auto nn = new node(); nn->val=i;
            v.push_back(nn);
        }
    }
};

signed main(){
    int n; cin>>n;
    graph g(n);
    for(int i =2;i<=n;i++){
        int a; cin>>a;
        g.v[a]->child.push_back(g.v[i]);
    }
    for(int i =1;i<=n;i++) cout<<g.v[i]->get_ans() -1<<' ';

}