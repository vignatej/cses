#include <bits/stdc++.h>
using namespace std;


void mc(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &b){
    int n = v.size(); int m = v[0].size();
    if(!(0<=i && i<n && 0<=j && j<m)) return;
    if(b[i][j] || v[i][j]=='#') return;
    b[i][j]=true;
    vector<vector<int>> vv{{-1, 0},{1, 0}, {0,1},{0,-1}};
    for(auto &o: vv){
        int nx = i+o[0]; int ny = j+o[1];
        mc(nx, ny, v, b);
    }
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char> (m));
    vector<vector<bool>> comp(n, vector<bool> (m, false));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    int ans{0};
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++){
        if(v[i][j]=='.' && comp[i][j]==false){
            ans++; 
            mc(i, j, v, comp);
        }
    }
    cout<<ans;

}