#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n; vector<int> v(n); for(int i = 0;i<n;i++) cin>>v[i];
    int ts{0}; for(auto &i: v) ts+=i;
    int ans{INT_MAX};
    for(int i = 1;i<(1<<n); i++){
        int cs{0};
        for(int j = 0;j<n;j++) if((i>>j)&1) cs+=v[j];
        int rs=ts-cs;
        // if(abs(cs-rs)==0){
        //     cout<<i<<' ';
        // }
        ans=min(ans, abs(rs-cs));
    }
    cout<<ans;



}