#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
ll MOD = 1e9+7;
ll pow_m(int a, int b){
    if(b==0) return 1;
    if(a==1 || b==1) return a;
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
        temp*=inverse(i.first-1, MOD);
        temp%=MOD;
        sum*=temp;
        sum%=MOD;
    }
    cout<<sum<<' ';

    //prod
    ll prod{1};
    for(auto &q: m){
        int i = q.first; int j = q.second;
        pow_m(i, j);
    }
    for(auto &q: m){
        int po = j*(j+1)/2;
        po*=ap/(j+1);
        prod*=pow(i, po);
    }
    cout<<prod<<' ';
}