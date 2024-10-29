#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll M = 1e9+7;

ll calc_sum(int i){
    return (((i%M)*((i+1)%M))/2)%M;
}


signed main(){
    int n; cin>>n; 
    ll ans{0};
    for(int i = 1;i<=sqrt(n);i++){
        ans+=i*floor(n/i);
        ans%=M;
    }
    int l = floor(sqrt(n));
    for(int i = sqrt(n);i>0;i--){
        ll r = n/i;
        if(l>r) continue;
        ll cs = ((calc_sum(r)-calc_sum(l))+M)%M;
        ans+=cs*i;
        ans%=M;
        l=r;
    }
    cout<<ans<<'\n';



    return 0;
}