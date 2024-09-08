#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(){
    int x, y; cin>>x>>y;
    int ma = max(x, y); int mi = min(x, y);
    int s = (ma-1)*(ma-1)+1; int e = ma*ma;
    if(x==ma && ma%2==0) return e-mi+1;
    else if(x==ma) return s+mi-1;
    else if(y==ma && ma%2==0) return s+mi-1;
    else return e-mi+1;
}

signed main(){
    int t; cin>>t;
    while(t--){
        cout<<solve()<<'\n';
    }
}