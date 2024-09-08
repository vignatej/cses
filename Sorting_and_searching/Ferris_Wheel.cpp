#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n, x; cin>>n>>x;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());

    // approach 1
    int l{0}, r{n-1};
    int ans{0};
    while(l<=r){
        if(l==r){ans++; l++;}
        else if(v[l]+v[r]<=x){ans++; l++; r--;}
        else{r--; ans++;}
    }
    cout<<ans;
    return 0;

    //  approach 2
    // set<pair<int, int>> s; 
    // for(int i = 0;i<n;i++) s.insert({v[i], i});
    // vector<bool> comp(n, false); int ans{0};
    // for(int i = 0;i<n;i++){
    //     if(comp[i]) continue;
    //     int x1 = v[i]; s.erase({x1, i});
    //     int r = x-x1;
    //     auto it = s.upper_bound({r, -1});
    //     auto pit = it; if(it!=s.begin()) pit=prev(it);
    //     if(pit==s.end()){ans++; continue;}
    //     int x2 = (*pit).first; int p = (*pit).second;
    //     if(x1+x2>x){ans++; continue;}
    //     ans++; 
    //     comp[p]=true;
    //     s.erase(pit);
    // }
    // cout<<ans;
}
