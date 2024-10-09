#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

// const ll M = 1e9+7;
ll solve(ll a, int b, ll M){
    if(b==0) return 1;
    if(b==1) return a;
    ll half = solve(a, b/2, M);
    half*=half;
    half%=M;
    if(b%2==0) return half;
    return (half*a)%M;
}

signed main(){
    int T; cin>>T;
    while(T--){
        int a, b, c; cin>>a>>b>>c;
        cout<<solve(a, solve(b, c, 1e9+6), 1e9+7)<<'\n';
    }


    
    return 0;
}