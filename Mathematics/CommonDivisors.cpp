#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    int n; cin>>n; vector<int> v(n); 
    for(auto &i: v) cin>>i;
    vector<int> occ(1000005, 0);
    for(auto &i: v) occ[i]++;
    int me = *max_element(v.begin(), v.end());
    for(int cgcd = me; cgcd>0; cgcd--){
        int d{0};
        for(int i = cgcd; i<=me;i+=cgcd){ 
            d+=occ[i];
        }
        if(d>1){cout<<cgcd; break;} 
    }

    // int n; cin>>n; vector<int> v(n, 0); 
    // for(int i = 0;i<n;i++) cin>>v[i];
    // vector<int> count(1e6+1, 0);
    // for(auto &curr: v){
    //     for(int i = 1;i<=sqrt(curr); i++){
    //         if(curr%i!=0) continue;
    //         int o = curr/i;
    //         count[i]++;
    //         if(o!=i) count[o]++;
    //     }
    // }

    // for(int i = 1e6;i>=0;i--){
    //     if(count[i]>1){ cout<<i; break;}
    // }
    
    return 0;
}