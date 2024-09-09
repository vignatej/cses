#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, x; cin>>n>>x;
    map<int, vector<pair<int, int>>> m;
    for(int i = 0;i<x;i++){
        int a, b, w; cin>>a>>b>>w;
        m[a].push_back({b, w});
    }
    priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
    pq.push({0, {1, false}});
    vector<int> dist_f(n+1, (int)1e15);
    vector<int> dist_h(n+1, (int)1e15);
    while(pq.size()){
        auto t = pq.top(); pq.pop();
        int w = t.first; int node = t.second.first; bool ish = t.second.second;
        if(dist_f[node]<=w) continue;
        if(ish==true && dist_h[node]<=w) continue;
        if(ish==false) dist_f[node]=w;
        dist_h[node]=min(dist_h[node], w);
        for(auto &i: m[node]){
            int nn = i.first; int ew = i.second;
            pq.push({w+ew, {nn, ish}});
            if(ish==false) pq.push({w+(ew/2), {nn, true}});
        }
    }
    cout<<dist_h[n];
}