#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int n, m, q; cin>>n>>m>>q;
    vector<vector<int>> v_o(n, vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>v_o[i][j];
        }
    }
    vector<vector<int>> v(m, vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            v[j][i]=v_o[i][j];
        }
    }
    for(int i = 0;i<m;i++){
        for(int j = 1;j<n;j++){
            v[i][j]|=v[i][j-1];
        }
    }
    while(q--){
        int cq; cin>>cq;
        int le = 0; int ri = n-1;
        bool comp = false;
        while(cq--){
            int r; char o; int c; cin>>r>>o>>c;
            r--;
            if(comp) continue;
            if(o=='<'){
                auto it = lower_bound(v[r].begin(), v[r].end(), c);
                int d = distance(v[r].begin(), it);d--;
                ri = min(ri, d);
            }else{
                auto it = upper_bound(v[r].begin(), v[r].end(), c);
                int d = distance(v[r].begin(), it);
                le = max(le, d);
            }
        }
        if(le<=ri) cout<<le+1<<'\n';
        else cout<<-1<<'\n'; 
    }

}