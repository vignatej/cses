#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
ll MOD = 1e9+7;
ll pow_m(int a, int b){
    if(b==0) return 1;
    // if(a==1 || b==1) return a;
    ll ans = pow_m(a, b/2)%MOD;
    ans*=ans; ans%=MOD;
    if(b%2) ans*=a;
    ans%=MOD;
    return ans;
}
ll inverse(ll i, ll mod){
    if(i==1) return 1;
    return (mod - ((mod/i)*inverse(mod%i,mod))%mod+mod)%mod;
}
ll my_inv(ll i){
    return pow_m(i, MOD-2)%MOD;
}
signed main(){
    int n; cin>>n;
    map<int, int> m;
    for(int i = 0;i<n;i++){int a, b; cin>>a>>b; m[a]=b;}
    // for count
    ll cou{1};
    for(auto &i: m){cou*=(i.second + 1)%MOD; cou%=MOD;}
    cout<<cou<<' ';


    //for sum
    ll sum{1};
    for(auto &i: m){
        ll temp = (pow_m(i.first, i.second+1)-1+MOD)%MOD;
        // temp*=inverse(i.first-1, MOD);
        temp*=my_inv(i.first-1);
        temp%=MOD;
        sum*=temp;
        sum%=MOD;
    }
    cout<<sum<<' ';

    //prod
    ll prod = 1;
    ll exponent = cou;
    for (auto &it : m) {
        int p = it.first, e = it.second;
        ll power = (e * (e + 1) / 2) % (MOD - 1);  // Reduce exponent modulo MOD-1
        ll term = pow_m(p, ((power) % (MOD - 1)));
        prod = (prod * term) % MOD;
    }cout<<prod;
}