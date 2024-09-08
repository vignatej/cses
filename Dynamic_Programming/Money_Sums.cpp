#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> solve(vector<int> & coins, int s, int e){
    if(s>e) return {};
    if(s==e) return {coins[s]};
    int m = (s+e)/2;
    auto a = solve(coins, s, m);
    auto b = solve(coins, m+1, e);
    set<int> ans;
    for(auto &i: a) ans.insert(i);
    for(auto &i: b) ans.insert(i);
    for(auto &i: a) for(auto &j: b) ans.insert(i+j);
    vector<int> av;
    copy(ans.begin(), ans.end(), back_inserter(av));
    return av;
}

int main(){
    int n; cin>>n; vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    // auto ans = solve(v, 0, n-1);
    // cout<<ans.size()<<'\n';
    // for(auto &i: ans) cout<<i<<' ';
    int ma = 100000;
    vector<vector<bool>> dp(n, vector<bool> (ma+1, false));
    for(int i = 0;i<n;i++) dp[i][0]=1;
    dp[0][v[0]]=1;
    for(int i = 0;i<n;i++){
        for(int j = 1;j<=ma; j++){
            if(i>0) dp[i][j]=dp[i-1][j];
            if(dp[i][j]) continue;
            if(i>0 && j-v[i]>=0 && dp[i-1][j-v[i]]) dp[i][j]=1;
        }
    }
    vector<int> ans;
    for(int i = 1;i<=ma;i++){
        bool ya = false;
        for(int j = 0;j<n;j++) if(dp[j][i]) ya=true;
        if(ya) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(auto &i: ans) cout<<i<<' ';
    
}