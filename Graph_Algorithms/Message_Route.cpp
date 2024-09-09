#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, x; cin>>n>>x;
    map<int, vector<int>> m;
    for(int i = 0;i<x;i++){
        int a, b; cin>>a>>b;
        m[a].push_back(b); m[b].push_back(a);
    }
    vector<int> prev(n+1, -1);
    prev[1]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(pq.size()){
        auto a = pq.top(); pq.pop();
        int curr = a.second; int l = a.first;
        for(auto i: m[curr]){
            if(prev[i]!=-1) continue;
            prev[i]=curr;
            pq.push({l+1, i});
        }
    }

    if(prev[n]==-1){cout<<"IMPOSSIBLE"; return 0;}
    int i = n; vector<int> ans;
    while(i!=0){
        ans.push_back(i);
        i=prev[i];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto i: ans) cout<<i<<' ';

}