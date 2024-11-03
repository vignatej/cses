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
        int n, m; cin>>n>>m;
        vector<vector<char>> v(n, vector<char>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                cin>>v[i][j];
            }
        }
        int ml = min(n, m)/2;
        ll ans{0};
        for(int l = 1;l<=ml;l++){
            vector<pair<int, int>> vv{{l-1, l-1}};
            while(true){
                if(vv.back().second+l==m) break;
                vv.push_back({vv.back().first, vv.back().second+1});
            }
            while(true){
                if(vv.back().first+l==n) break;
                vv.push_back({vv.back().first+1, vv.back().second});
            }
            while(true){
                if(vv.back().second-l==-1) break;
                vv.push_back({vv.back().first, vv.back().second-1});
            }
            while(true){
                if(vv.back().first-l==-1) break;
                vv.push_back({vv.back().first-1, vv.back().second});
            }
            vector<char> cv;
            for(auto &i: vv) cv.push_back(v[i.first][i.second]);
            int cs = cv.size();
            if(cs-1<4) continue;
            cv.push_back(cv[1]);
            cv.push_back(cv[2]);
            for(int i = 0;i<=cv.size()-4;i++)
                if(cv[i]=='1' && cv[i+1]=='5' && cv[i+2]=='4' && cv[i+3]=='3') ans++;
        }
        cout<<ans<<'\n';

    }
    return 0;
}