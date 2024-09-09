#include <bits/stdc++.h>
using namespace std;


bool is_comp(int i, int j, int n, int m){
    return (i==0 || i==n-1) || (j==0 || j==m-1);
}

int main(){
    int n, m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    
    vector<vector<char>> prev(n, vector<char> (m, '0'));
    vector<vector<bool>> isv(n, vector<bool> (m, false));
    vector<pair<int, int>> cp;

    vector<vector<bool>> mi(n, vector<bool> (m, false));
    vector<pair<int, int>> mp;
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++){
        if(v[i][j]=='A'){isv[i][j]=true; cp.push_back({i, j});}
        if(v[i][j]=='M'){mi[i][j]=true; mp.push_back({i, j});}
    }

    bool comp=false; int ansx, ansy;
    vector<vector<int>> vv{{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};
    while(!comp && cp.size()){
        decltype(mp) nmp;
        for(auto &i: mp){
            int x{i.first}, y{i.second};
            for(auto &j: vv){
                int nx = x+j[0]; int ny=y+j[1];
                if(!(0<=nx && nx<n && 0<=ny && ny<m)) continue;
                if(v[nx][ny]=='#') continue;
                if(mi[nx][ny]) continue;
                mi[nx][ny]=true; 
                nmp.push_back({nx, ny});
            }
        }
        mp=nmp;
        decltype(cp) ncp;
        for(auto &i: cp){
            int x{i.first}, y{i.second};
            if(is_comp(x, y, n, m)){comp=true; ansx=x; ansy=y; break;}
            for(auto &j: vv){
                int nx = x+j[0]; int ny = y+j[1];
                if(!(0<=nx && nx<n && 0<=ny && ny<m)) continue;
                if(v[nx][ny]=='#') continue;
                if(isv[nx][ny]) continue;
                if(mi[nx][ny]) continue;
                isv[nx][ny]=true;
                prev[nx][ny]=j[2];
                ncp.push_back({nx, ny});
            }
        }
        cp=ncp;
    }
    if(!comp) {cout<<"NO"; return 0;}
    cout<<"YES\n";
    int x{ansx}, y{ansy};
    vector<char> ans;
    while(v[x][y]!='A'){
        ans.push_back(prev[x][y]);
        for(auto &i: vv){
            if(i[2]==prev[x][y]){x-=i[0]; y-=i[1]; break;}
        }
    }
    cout<<ans.size()<<'\n';
    reverse(ans.begin(), ans.end());
    for(auto &i: ans) cout<<i;

}