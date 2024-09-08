#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> v;
    for(int i = 2;i<=n;i+=2){
        v.push_back(i);
    }
    if(n!=1 && abs(v.back()-1)<=1){
        cout<<"NO SOLUTION"; return 0;}
    for(int i = 1;i<=n;i+=2){v.push_back(i);}
    for(auto &i: v) cout<<i<<' ';
}