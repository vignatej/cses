#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll int
// wrong ans
int M = 1e9+7;
vector<map<int, int>> s;
int ncr(int n, int r){
    if(r==0) return 1;
    if(r==1) return n;
    if(n==1) return 1;
    if(n==r) return 1;
    if(s[n].find(r)!=s[n].end()) return s[n][r];
    ll ans = (ncr(n-1, r)+ncr(n-1, r-1))%M;
    s[n][r] = ans;
    return ans;
}
signed main(){
    int n; cin>>n;
    while(n--){
        int a, b; cin>>a>>b;
        if(((int)s.size())<a+1) s.resize(a+1); 
        cout<<ncr(a, b)<<'\n';
    }
}