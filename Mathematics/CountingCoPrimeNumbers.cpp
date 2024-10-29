#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll int
// wrong ans
signed main(){
    int n; cin>>n;
    vector<int> v(n); for(auto &i: v) cin>>i;
    ll ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(gcd(v[i], v[j])==1) ans++;
        }
    }
    cout<<ans;

}