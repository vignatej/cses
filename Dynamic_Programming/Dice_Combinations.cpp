#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> dp;
const ll M = 7+(int)1e9;

ll calc(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    if(dp[n]!=-1) return dp[n];
    ll a = calc(n-1)+calc(n-2)+calc(n-3)+calc(n-4)+calc(n-5)+calc(n-6);
    a%=M; dp[n] = a;
    return a;
}

int main(){
    int n; cin>>n;
    dp.resize(n+2, -1);
    cout<<calc(n);
}