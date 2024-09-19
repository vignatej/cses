#include <bits/stdc++.h>
using namespace std;
#define ll long long
// vector<vector<int>> dp;
// ll solve(int m1, int m2){
//     // int t = max(m1, m2); m1=min(m1, m2); m2=t;
//     if(m1==m2) return 0;
//     if(dp[m1][m2]!=-1) return dp[m1][m2];
//     ll ans{INT_MAX};
//     for(int i = 1;i<m1;i++) ans=min(ans, 1ll+ solve(m1-i, m2)+solve(i, m2));
//     for(int i = 1;i<m2;i++) ans=min(ans, 1ll+ solve(m1, m2-i)+solve(m1, i));
//     dp[m1][m2]=ans;
//     return ans;
// }

int main(){
    int a, b; cin>>a>>b;
    vector<vector<ll>> dp(a+1, vector<ll> (b+1, INT_MAX));
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++){
            if(i==j) {dp[i][j]=0; continue;}
            if(i==1 || j==1){dp[i][j]=max(i-1, j-1); continue;}
            dp[i][j]=INT_MAX;
            for(int k = 1;k<i;k++) dp[i][j]=min(dp[i][j], 1+dp[i-k][j]+dp[k][j]);
            for(int k = 1;k<j;k++) dp[i][j]=min(dp[i][j], 1+dp[i][j-k]+dp[i][k]); 
        }
    }

    cout<<dp[a][b];

}