#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, x; cin>>n>>x;
    vector<ll> v(n); for(int i = 0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    vector<ll> prev(x+1, INT_MAX); prev[0]=0;
    for(int i = 0;i<n;i++){
        vector<ll> curr(x+1, INT_MAX); curr[0]=0;
        for(int j = 1;j<=x;j++){
            if(j-v[i]>=0) curr[j] = 1+curr[j-v[i]];
            if(i>0) curr[j] = min(prev[j], curr[j]);
            if(curr[j]>INT_MAX) curr[j] = (INT_MAX);
        }
        prev=curr;
    }
    cout<<(prev[x]==INT_MAX ? -1: prev[x]);
}