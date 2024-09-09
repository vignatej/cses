#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, x; cin>>n>>x;
    map<int, vector<pair<int, int>>> m;
    for(int i = 0;i<x;i++){
        int a, b, w; cin>>a>>b>>w;
        m[a].push_back({b, w});
        // m[b].push_back({a, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    vector<int> ans(n+1, -1);
    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int cn = t.second; int cl = t.first;
        if(ans[cn]!=-1) continue;
        ans[cn]=cl;
        for(auto &i: m[cn]){
            int n2 = i.first; int l2 = i.second+cl;
            pq.push({l2, n2});
        }
    }
    for(int i = 1;i<=n;i++) cout<<ans[i]<<' ';

}