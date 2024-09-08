#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 7+(int)1e9;
ll n, m; vector<ll> v;
vector<vector<ll>> dp;
ll do_it(ll i, ll p){
    if(p==0 || p>m) return 0;
    if(i==n) return 1;
    if(v[i]!=0 && abs(v[i]-p)>1) return 0;
    if(dp[i][p]!=-1) return dp[i][p];
    ll ans{0};
    if(v[i]!=0) ans = do_it(i+1,v[i]);
    else ans = do_it(i+1, p-1)+do_it(i+1, p)+do_it(i+1, p+1);
    ans%=M;
    dp[i][p]=ans;
    return ans;
}

int main(){
    cin>>n>>m;
    v.resize(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    ll ans{0};
    dp.resize(n+1, vector<ll> (m+2, -1));
    if(v[0]!=0) ans=do_it(1, v[0]);
    else{
        for(int i = 1;i<=m;i++) ans+=do_it(1, i);
    }
    ans%=M;
    cout<<ans;
}