#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main() {
    int n; cin>>n;
    set<int> s;
    for(int i = 0;i<n;i++){int c; cin>>c;s.insert(c);}
    cout<<s.size();

}
