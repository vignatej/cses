#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(int s, int e, int sp, int rp){
    string ss = to_string(s); string ep = to_string(e);
    int n = ss.size();
    if(s==e){return ss[rp-sp]-'0';}
    int m = (e+s)/2;
    int mep = sp + (m-s+1)*n -1;
    if(rp<=mep) return solve(s, m, sp, rp);
    else return solve(m+1, e, mep+1, rp);
}

signed main(){
    int T; cin>>T; 
    while(T--){    
        int n; cin>>n;
        int p = 0;
        int i = 1;
        while(1){
            string s{'1'}, e;
            for(int j = 1;j<i;j++) s.push_back('0');
            for(int j = 0;j<i;j++) e.push_back('9');
            int si = stoll(s); int ei = stoll(e);
            int sp{p+1}; int ep{p+(ei-si+1)*i};
            if(sp<=n && n<=ep){cout<<solve(si, ei, sp, n)<<'\n'; break;}
            p=ep;i++;
        }
    }
}