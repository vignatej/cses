#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n; cin>>n;
    multiset<pair<int, int>> s;
    vector<pair<int, int>> v;
    for(int i = 0;i<n;i++){
        int a, b; cin>>a>>b;
        s.insert({a, 1}); s.insert({b, -1});
    }
    for(auto &i: s){
        int a = i.first; int b = i.second;
        if(v.size()==0){v.push_back(i); continue;}
        if(v.back().first==a) v.back().second+=b;
        else v.push_back(i);
    }
    int ans{0};
    int curr = 0;
    for(auto &i: v){
        curr+=i.second;
        ans=max(ans, curr);
    }
    cout<<ans;
}
