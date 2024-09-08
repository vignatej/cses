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
    vector<vector<char>> f(n, vector<char>(n));
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++) cin>>f[i][j];
    Vii v(n, Vi (n, 0));
    if(f[0][0]=='*') v[0][0]=1;
    for(int i = 1;i<n;i++){
        v[0][i]+=v[0][i-1];
        if(f[0][i]=='*') v[0][i]++;
    }
    for(int j = 1;j<n;j++){
        if(f[j][0]=='*') v[j][0]=1;
        for(int i = 1;i<n;i++){
            v[j][i]+=v[j][i-1];
            if(f[j][i]=='*') v[j][i]++;
        }
        for(int i = 0;i<n;i++) v[j][i]+=v[j-1][i];
    }
    for(;q>0; q--){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        x1--; y1--; x2--; y2--;
        ll ans{v[x2][y2]};
        if(x1!=0) ans-=v[x1-1][y2];
        if(y1!=0) ans-=v[x2][y1-1];
        if(x1!=0 && y1!=0) ans+=v[x1-1][y1-1];
        cout<<ans<<'\n';
    }
}