#include <bits/stdc++.h>
#define int long long
using namespace std;

set<string> all;
string s;
void permute(int i){
    int n = s.length();
    if(i==n){all.insert(s); return;}
    for(int j = i;j<n;j++){
        swap(s[i], s[j]);
        permute(i+1);
        swap(s[i], s[j]);
        // permute(i+1);
    }
}

signed main(){
    cin>>s;
    permute(0);
    cout<<all.size()<<'\n';
    // map<string,int> m; for(auto &i: all) m[i]++;
    // for(auto &i: all) cout<<i<<'\n';
}