#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    vector<int> c{0};
    for(auto &i: v){
        if(i>=c.back()){c.push_back(i); continue;}
        auto it = upper_bound(c.begin(), c.end(), i);
        int d = distance(c.begin(), it);
        c[d]=i;
    }

    cout<<(c.size()-1);

}
