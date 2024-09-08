#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n; 
    vector<int> v(n-1); for(int i = 0;i<n-1;i++) cin>>v[i];
    vector<bool> has(n+2, false);
    for(auto &i: v) has[i]=true;
    for(int i = 1;i<=n+1;i++) if(!has[i]){cout<<i; break;}

}