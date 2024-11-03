#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(auto &i: v) cin>>i;
        bool ya  = false;
        for(int i =1;i<n;i++) if(abs(v[i]-v[i-1])!=7 && abs(v[i]-v[i-1])!=5) ya=true;
        if(ya) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}