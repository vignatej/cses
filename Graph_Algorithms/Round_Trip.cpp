#include <bits/stdc++.h>
using namespace std;

bool do_it(int curr, map<int, vector<int>> &g, int par, set<int> &seen, vector<int> &order, vector<int> &ans){
    if(ans[curr]!=-1) return ans[curr];
    if(seen.find(curr)!=seen.end()){
        auto it = find(order.begin(), order.end(), curr);
        cout<<distance(it, order.end())+1<<'\n';
        for(;it!=order.end(); it++) cout<<(*it)<<' ';
        cout<<curr; 
        ans[curr]=1;
        return 1;
    }
    seen.insert(curr);
    order.push_back(curr);
    bool cans = false;
    for(auto &i: g[curr]){
        if(i==par) continue;
        cans = do_it(i, g, curr, seen, order, ans);
        if(cans) {ans[curr] = 1; return true;}
    }
    seen.erase(curr); order.pop_back();
    ans[curr]=0;
    return false;
}

int main(){
    int n, x; cin>>n>>x;
    map<int, vector<int>> m;
    for(int i = 1;i<=x;i++){
        int a, b; cin>>a>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    bool an = false; vector<int> ans(n+1, -1);
    for(int i =1;i<=n && an==false;i++){
        set<int> seen; vector<int> order;
        an = do_it(i, m, 0, seen, order, ans);
    }
    if(!an){cout<<"IMPOSSIBLE"; return 0;}

}