#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    int prev = v[0];
    int ans{0};
    for(auto &i: v) {
        if(i<prev) ans+=prev-i; 
        prev=max(i, prev);}
    cout<<ans;

}