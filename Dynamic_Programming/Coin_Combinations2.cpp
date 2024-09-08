#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, x; cin>>n>>x;
    vector<ll> v(n); for(int i = 0;i<n;i++) cin>>v[i];
    // vector<vector<ll>> dp(n, vector<ll> (x+1, 0));
    vector<ll> prev(x+1, 0), curr(x+1, 0);
    ll M = (int)1e9 + 7;
    for(int i = 0;i<n;i++){
        curr[0]=1;
        for(int j = 1;j<=x;j++){
            if(i!=0) curr[j]=prev[j];
            if(j-v[i]>=0) curr[j] += curr[j-v[i]];
            curr[j]%=M;
        }
        prev=curr;
    }
    cout<<prev[x];
}