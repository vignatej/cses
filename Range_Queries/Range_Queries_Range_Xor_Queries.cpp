#include <bits/stdc++.h>
#define ll long long
#define int ll
#define Vi vector<int>
#define Vii vector<vector<int>>
#define Pii pair<int, int>
#define Fi first
#define Se second
using namespace std;

signed main(){
    int n, q; cin>>n>>q;
    Vi v(n, 0); for(int i = 0;i<n;i++) cin>>v[i];
    Vii vv(n+1, Vi (32, 0));
    for(int i = 0;i<n;i++){
        vv[i+1]=vv[i];
        for(int j = 0;j<30;j++)
            if(v[i]&(1<<j)) vv[i+1][j]++;
    }
    for(;q>0;q--){
        int a, b; cin>>a>>b; a--; b--;
        int ans{0};
        for(int j = 0;j<30;j++){
            int c = vv[b+1][j]-vv[a][j];
            if(c%2==1) ans=ans|(1<<j);
        }
        cout<<ans<<'\n';
    }
}


