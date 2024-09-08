#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n; cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    int cs{0}; int ms{v[0]};
    for(auto &i: v){
        cs=max(cs+i, i);

        ms=max(ms, cs);
    }
    cout<<ms;
}
