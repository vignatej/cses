#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    string s; cin>>s;
    map<char, int> m; for(auto &i: s) m[i]++;
    int oc{0};
    for(auto &i: m) if(i.second%2) oc++;
    if(oc>1){cout<<"NO SOLUTION"; return 0;}
    string s1, s2; char a = '@';
    for(auto &i: m){
        char c = i.first; int v = i.second;
        for(int j = 0;j<v/2;j++){ s1.push_back(c); s2.push_back(c);}
        if(v%2) a=c;
    }
    if(a!='@') s1.push_back(a);
    copy(s2.rbegin(), s2.rend(), back_inserter(s1));
    cout<<s1;
}