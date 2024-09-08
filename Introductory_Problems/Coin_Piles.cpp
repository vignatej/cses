#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        if(a>b) swap(a, b);
        if(b>2*a){cout<<"NO\n"; continue;}
        if((2*a-b)%3==0)cout<<"YES\n";
        else cout<<"NO\n";

    }
}