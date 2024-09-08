#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    int i = 0; set<int> s; int ans{0};
    int j = 0;
    while(i<n && j<n){
        while(j<n && s.find(v[j])==s.end()){s.insert(v[j]); ans=max(ans, j-i+1);j++;}
        if(j==n) break;
        while(i<n && v[i]!=v[j]){s.erase(v[i]); i++;} s.erase(v[i]);
        i++;
    }
    cout<<ans;
}
