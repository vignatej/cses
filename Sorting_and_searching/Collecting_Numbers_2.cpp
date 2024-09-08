#include <bits/stdc++.h>
#define ll long long

using namespace std;

signed main(){
    int n, m; cin>>n>>m; 
    vector<int> v(n+1, 0);
    for(int i = 1;i<=n;i++) cin>>v[i];
    map<int, int> ma;
    for(int i = 0;i<=n;i++) ma[v[i]]=i;
    ma[n+1]=n+1;
    set<int> s;
    for(int i = 1;i<=n;i++){
        if(s.find(v[i]-1)==s.end()){ s.insert(v[i]); continue;}
        s.erase(v[i]-1); s.insert(v[i]);
    }
    int ans = s.size();
    for(int i = 0;i<m;i++){
        int a, b; cin>>a>>b;
        if(v[a]+1==v[b] || v[a]-1==v[b]){
            if(v[a]<v[b]) ans++;
            else ans--;
            cout<<ans<<'\n';
            ma[v[a]]=b; ma[v[b]]=a;
            swap(v[a], v[b]);
            continue;
        }
        
    }


}