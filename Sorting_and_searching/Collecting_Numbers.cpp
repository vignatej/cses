#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin>>n;
    vector<pair<int, int>> v(n);
    for(int i = 0;i<n;i++){int c; cin>>c; v[i]={c, i+1};};
    sort(v.begin(), v.end());
    int cr = 0; int pp = n+1;
    for(int i = 0;i<n;i++){
        if(pp<=v[i].second){pp=v[i].second;}
        else{pp=v[i].second; cr++;}
    }
    cout<<cr;

}
