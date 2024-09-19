#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> dp;
ll do_it(ll n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    string ns = to_string(n);
    ll ans = INT_MAX;
    for(auto &i: ns){
        if(i=='0') continue;
        ll nn = n; nn-=(i-'0');
        ans = min(ans, 1+do_it(nn));
    }
    dp[n]=ans;
    return ans;
}
int main(){
    ll n; cin>>n;
    dp.resize(n+1, -1);
    cout<<do_it(n);
}