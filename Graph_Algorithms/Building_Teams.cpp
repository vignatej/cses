#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, x; cin>>n>>x;
    map<int, vector<int>> m;
    for(int i = 0;i<x;i++){
        int a, b; cin>>a>>b;
        m[a].push_back(b); m[b].push_back(a);
    }
    vector<int> ass(n+1, -1);
    bool ok = true;
    for(int i =1;i<=n;i++){
        if(ass[i]!=-1) continue;
        vector<int> curr{i}; bool fir = true;
        while(curr.size()){
            vector<int> next;
            for(auto &i: curr) ass[i] = fir;
            for(auto &i: curr) for(auto &j: m[i]){
                if(ass[j]==fir){ok=false; break;}
                if(ass[j]!=(!fir)){next.push_back(j);}
            }
            curr=next; fir=!fir;
            if(!ok) break;
        }
        if(!ok) break;
    }
    if(!ok){cout<<"IMPOSSIBLE"; return 0;}
    ass.erase(ass.begin());
    for(auto &i: ass) cout<<i+1<<' ';

}