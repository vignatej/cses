#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = (int)1e9 + 7;
vector<ll> dp;
ll calc(ll n, vector<ll> & coins){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll ans{0};
    for(auto &i: coins){
        ans+=calc(n-i, coins);
        ans%=M;
    }
    dp[n]=ans;
    return ans;
}

int main(){
    ll n, x; cin>>n>>x;
    vector<ll> v(n); for(int i = 0;i<n;i++) cin>>v[i];
    dp.resize(x+1, -1);
    cout<<calc(x, v);
}