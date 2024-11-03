#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
bool contains(string &s, int i){
    int n = s.size();
    if(i>n-4) return false;
    if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') return true;
    return false;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        string s; cin>>s;
        int q; cin>>q;
        int n = s.size();
        vector<bool> v(n, false);
        int c = 0;
        for(int i = 0;i<n;i++)
            if(contains(s, i)){
                v[i]=true; c++;
            }
        while(q--){
            int p; char val; cin>>p>>val;
            // int cc = 0;
            s[p-1]=val;
            for(int j = max(1ll*0, p-4);j<=min(n, p+5);j++){
                bool cur = contains(s, j);
                if(v[j] == cur) continue;
                if(v[j]) c--;
                else c++;
                v[j] = cur;
            }
            if(c) cout<<"YES\n";
            else cout<<"NO\n";
        }

    }
    return 0;
}