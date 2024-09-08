#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m; cin>>n>>m;
    vector<vector<char>> v(n, vector<char> (m));
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin>>v[i][j];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int sx{-1}, sy{-1}, ex{-1}, ey{-1};
    for(int i = 0;i<n;i++) for(int j = 0;j<m;j++){ 
        if(v[i][j]=='A'){sx=i; sy=j;}
        if(v[i][j]=='B'){ex=i; ey=j;}
    }
    pq.push({0, {sx, sy}});
    vector<vector<bool>> comp(n, vector<bool> (m, false));
    vector<vector<int>> gl(n, vector<int> (m, -1));    
    vector<vector<int>> vv{{-1, 0, 'D'}, {1, 0, 'U'}, {0,-1, 'R'},{0,1, 'L'}};
    
    while(pq.size()){   
        auto t = pq.top(); pq.pop();
        int cl = t.first; int x=t.second.first; int y = t.second.second;
        if(!(0<=x && x<n && 0<=y && y<m)) continue;
        if(comp[x][y] || v[x][y]=='#') continue;
        
        comp[x][y]=true; gl[x][y]=cl;
        for(auto &i: vv){
            int nx = x+i[0]; int ny = y+i[1];
            pq.push({cl+1, {nx, ny}});
        }
    } 
    if(gl[ex][ey]==-1){cout<<"NO"; return 0;}
    
    string s; int tl = gl[ex][ey];
    int cx{ex}; int cy{ey};
    while(tl!=0){
        int nx, ny;
        for(auto &i: vv){
            nx=cx+i[0]; ny = cy+i[1];
            if(!(0<=nx && nx<n && 0<=ny && ny<m)) continue;
            if(gl[nx][ny]+1!=tl) continue;
            tl--; cx=nx; cy=ny;
            s.push_back(i[2]);
            break;
        }
    }
    reverse(s.begin(), s.end());
    cout<<"YES\n"<<s.length()<<'\n'<<s;

}