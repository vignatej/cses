#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s; cin>>s;
    int n = s.length();
    int i = 0; int j=0;
    int ans{0};
    while(i<n){
        int j = i+1;
        while(j<n && s[j]==s[i]) j++;
        ans=max({ans, j-i});
        i=j;
    }
    cout<<ans;
}