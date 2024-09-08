#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n, m, k; cin>>n>>m>>k;
    vector<int> v1(n), v2(m);
    for(int i = 0;i<n;i++) cin>>v1[i];
    for(int i = 0;i<m;i++) cin>>v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i{0}, j{0};
    int ans{0};
    while(i<n && j<m){
        int mi = min(v1[i], v2[j]);
        int ma = max(v1[i], v2[j]);
        if(ma-mi<=k) {ans++;i++;j++;}
        else if(mi==v1[i])i++;
        else if(mi==v2[j])j++;
    }
    cout<<ans;

}
