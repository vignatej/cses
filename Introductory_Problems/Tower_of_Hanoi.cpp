#include <bits/stdc++.h>
#define int long long
using namespace std;

pair<int, string>& operator+=(pair<int, string> &a, const pair<int, string> &b){
    a.first+=b.first; 
    a.second+=b.second;
    return a;
}

pair<int, string> toh(int N, int s, int m, int e){
    if(N==0) return {0, ""};
    pair<int, string> ans{0, ""};
    ans+=toh(N-1, s, e, m);
    // cout<<f<<' '<<t<<'\n';
    ans.first++;
    ans.second+=to_string(s)+" "+to_string(e)+"\n";
    ans+=toh(N-1, m, s, e);
    return ans;
}

signed main(){
    int n; cin>>n;
    auto a = toh(n, 1, 2,3);
    cout<<a.first<<'\n'<<a.second<<'\n';

}