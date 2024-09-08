#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n, x; cin>>n>>x;
    vector<pair<int, int>> v;
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back({a, i+1});
    }
    // auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){return a.first<b.first;};
    // sort(v.begin(), v.end(), cmp);
    set<pair<int, int>> s;
    for(auto &i: v) s.insert(i);
    for(auto &i: v){
        s.erase(i);
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b){return a.first<b.first;};
        auto it = s.lower_bound({x-i.first, 0});
        if(it!=s.end() && (it->first)+i.first==x){
            cout<<i.second<<' '<<it->second;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}
