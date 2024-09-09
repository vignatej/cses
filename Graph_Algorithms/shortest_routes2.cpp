#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, x, y; cin>>n>>x>>y;
    vector<vector<int>> v(n, vector<int> (n, (int)1e15));
    for(int i = 0;i<x;i++){
        int a, b, w; cin>>a>>b>>w;
        a--; b--;
        v[a][b]=min(v[a][b], w);
        v[b][a]=min(v[b][a], w);
    }
    for(int i = 0;i<n;i++) v[i][i]=0;
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            if(v[i][k]==(int)1e15) continue;
            for(int j = 0;j<n;j++){
                if(v[k][j]==(int)1e15) continue;
                v[i][j]=min(v[i][j], v[i][k]+v[k][j]);
            }
        }
    }
    for(int i = 0;i<y;i++){
        int a, b; cin>>a>>b; a--; b--;
        cout<<(v[a][b]<(int)1e15 ? v[a][b]:-1)<<'\n';
    }
}