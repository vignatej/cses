#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> get(int n){
    if (n==1) return {0, 1};
    vector<int> v = get(n-1);
    vector<int> ans;
    for(auto &i: v) ans.push_back((1<<(n-1))+i);
    copy(ans.rbegin(), ans.rend(), back_inserter(v));
    return v;
}
char print_bits(int num, int n){
    while(n>0){if((num>>(n-1))&1)cout<<'1'; else cout<<'0'; n--;}
    return '\n';
}

signed main(){
    int n; cin>>n;
    for(auto &i: get(n)) cout<<print_bits(i, n);
}