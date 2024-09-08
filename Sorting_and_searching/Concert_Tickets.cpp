#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n, m; cin>>n>>m;
    vector<int> v1(n), v2(m);
    for(int i = 0;i<n;i++) cin>>v1[i];
    for(int i = 0;i<m;i++) cin>>v2[i];
    multiset<int> s; for(auto &i: v1) s.insert(i);
    for(auto &i: v2){
        auto it = s.upper_bound(i);
        if(it==s.begin()) {cout<<-1<<'\n'; continue;}
        it=prev(it);
        cout<<(*it)<<'\n';
        s.erase(it);
    }
}
