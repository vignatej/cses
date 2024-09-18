#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n; cin>>n;
    ll M = 7+(int)1e9;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0;i<n;i++) for(int j =0;j<n;j++) cin>>v[i][j];
    vector<vector<ll>> dp(n, vector<ll>(n, 0)); if(v[0][0]=='.') dp[0][0]=1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(v[i][j]=='*') continue;
            if(i!=0) dp[i][j]=dp[i-1][j];
            if(j!=0) dp[i][j]+=dp[i][j-1];
            dp[i][j]%=M;
        }
    }
    cout<<dp[n-1][n-1];
}