#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n; cin>>n;
    vector<pair<int, int>> v;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    map<int, int> m;
    for(auto &i: v){
        int s = i.first; int e = i.second; e--;
        auto it = m.upper_bound(s-1);
        if(it==m.begin()){
            m[e]=max(m[e], (int) 1);
            continue;
        }
        it=prev(it);
        if(m[e]>(*it).second+1) continue;
        m[e]=max(m[e],(*it).second+1);
        m.erase(m.upper_bound(e), m.end());
    }
    cout<<(m.rbegin()->second);
}
