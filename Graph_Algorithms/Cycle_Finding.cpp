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
    vector<int> dist(n+1, (int)1e15);
    vector<int> par(n+1, -1);
    dist[1]=0;
    int last;
    for(int i = 1;i<=n;i++){
        last = -1;
        for(auto &j: m)
            for(auto &k: j.second){
                int a = j.first; int b = k.first; int w = k.second;
                if(dist[b]>dist[a]+w){
                    dist[b]= dist[a]+w;
                    par[b]=a;
                    last = b;
                }
                
            }
    }

    if(last==-1){cout<<"NO"; return 0;}
    int y = last;
    for(int i = 0;i<n;i++) y=par[y];
    vector<int> path;
    for(int i = y; ;i=par[i]){
        path.push_back(i);
        if(path.size()>1 && path.back()==y) break;
    }
    reverse(path.begin(), path.end());
    cout<<"YES\n";
    for(auto &i: path) cout<<i<<' ';

}