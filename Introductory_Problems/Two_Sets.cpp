#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    if(!(n%4==0 || (n+1)%4==0)) {cout<<"NO";return 0;}
    vector<bool> v(n+1, false);
    int rs = (n*(n+1))/4; int c{0};
    for(int i = n;i>0;i--){
        if(rs-i>=0){rs-=i;v[i]=true;c++;}
    }
    cout<<"YES"<<'\n';
    cout<<c<<'\n'; for(int i = 1;i<=n;i++) if(v[i]) cout<<i<<' ';
    cout<<'\n'<<n-c<<'\n'; 
    for(int i = 1;i<=n;i++) if(!v[i]) cout<<i<<' ';
}