#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int t; cin>>t;
    while(t--){
        int l, r, i, k; cin>>l>>r>>i>>k;
        int m = powl(2, i);
        int a = l/m; int b = r/m;
        int tv = r-l+1;
        int td = b-a+1;
        if(m*a+k < l) td--;
        if(m*b+k > r) td--;
        cout<<tv-td<<'\n';
    }


    return 0;
}