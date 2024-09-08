#include <bits/stdc++.h>
#define ll long long
using namespace std;
void print(int n, int i){
    if(i==1){cout<<'*'; return;}
    cout<<'*';
    for(int j = 1;j<i-1;j++) cout<<' ';
    cout<<'*';
}
signed main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++) cin>>v[i];
    set<int> s;
    for(auto &i: v){
        if(s.find(i-1)==s.end()){ s.insert(i); continue;}
        s.erase(i-1); s.insert(i);
    }
    cout<<s.size();

}