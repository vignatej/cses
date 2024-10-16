#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll int

signed main(){
    int n, k; cin>>n>>k;
    vector<int> v(k, 0);
    for(auto &i: v) cin>>i;
    ll ans{0};
    for(int i =0;i<((1ll)<<k);i++){
        vector<int> vv;
        ll p=1; 
        int cc{0};
        for(int j = 0;j<k;j++){
            if(i & (1<<j) ){
                if(p>n/v[j]){p=n+1;} 
                else p*=v[j];
                cc++;
            }
        }
        if(cc%2==0) ans-=n/p;
        else ans+=n/p;
    }
    ans+=n;
    cout<<ans;
}