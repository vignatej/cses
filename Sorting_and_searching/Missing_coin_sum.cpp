#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    sort(v.begin(), v.end());
    int x = 1;
    for(auto &i: v){
        if(i<=x) x+=i;
        else{cout<<x; return 0;}
    }
    cout<<x;
}
