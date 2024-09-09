#include <bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int curr, int par, set<int> &list, map<int, vector<pair<int, int>>> &g){
    if(list.find(curr)!=list.end()) return;
    list.insert(curr);
    for(auto &i: g[curr]){
        if(i.first==par) continue;
        dfs(i.first, curr, list, g);
    }
}

signed main() {
    int n, x; cin>>n>>x;
    map<int, vector<pair<int, int>>> m;
    for(int i = 0;i<x;i++){
        int a, b, w; cin>>a>>b>>w;
        m[a].push_back({b, -1*w});
    }
    vector<int> dist(n+1, (int)1e15);
    dist[1]=0;
    for(int i =1;i<n;i++){
        for(auto &j: m){
            for(auto &k: j.second){
                int a = j.first; int b = k.first; int w = k.second;
                dist[b]=min(dist[b], dist[a]+w);
            }
        }
    }
    int ans = dist[n];
    set<int> neg_cyc;
    for(auto &j: m){
        for(auto &k: j.second){
            int a = j.first; int b = k.first; int w = k.second;
            int q = dist[b];
            dist[b]=min(dist[b], dist[a]+w);
            if(q!=dist[b]) neg_cyc.insert(b);
        }
    }
    map<int, vector<pair<int, int>>> rev_map;
    for(auto &i: m){
        for(auto &j: i.second){
            int a = i.first; int b = j.first; int w = j.second;
            rev_map[b].push_back({a, w});
        }
    }
    set<int> vis_back;
    dfs(n, -1, vis_back, rev_map);

    set<int> vis_front;
    dfs(1, -1, vis_front, m);

    set<int> both_vis;
    set_intersection(vis_front.begin(), vis_front.end(), vis_back.begin(), vis_back.end(), inserter(both_vis, both_vis.begin()));

    bool yes = true;
    for(auto &i: both_vis){
        if(neg_cyc.find(i)!=neg_cyc.end()){yes=false; break;}
    }
    if(yes){cout<<ans*(-1);}
    else cout<<-1;

}
