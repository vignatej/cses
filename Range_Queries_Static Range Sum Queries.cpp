#include <bits/stdc++.h>
#define ll long long
#define int ll
#define Vi vector<int>
#define Pii pair<int, int>
#define Fi first
#define Se second
using namespace std;

signed main(){
    int n, q; cin>>n>>q;
    Vi v(n+1);
    for(int i = 1;i<=n;i++){int a; cin>>a; v[i]=a;}
    Vi s(n+1, 0);
    for(int i = 1;i<=n;i++) s[i]=s[i-1]+v[i];
    for(int z = 0;z<q;z++){
        int a, b; cin>>a>>b; 
        int c = s[b]-s[a-1];
        cout<<c<<'\n';
    }
}