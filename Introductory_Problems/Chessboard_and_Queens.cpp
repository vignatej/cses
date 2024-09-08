#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isok(vector<vector<char>> &b, int cp){
    int x = cp/8; int y = cp%8;
    for(int i = y;i>=0;i--) if(b[x][i]=='q') return false;
    for(int i = x;i>=0;i--) if(b[i][y]=='q') return false;
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        if (b[i][j] == 'q')
            return false;
    for (int i = x, j = y; i >= 0 && j < 8; i--, j++)
        if (b[i][j] == 'q')
            return false;

    return true;
}
int solve(vector<vector<char>> & b, int r, int cp){
    if(r==0) return 1;
    int x = cp/8; int y = cp%8;
    if(x==8) return 0;
    int ans = solve(b, r, cp+1);
    if(b[x][y]=='*') return ans;
    if(!isok(b, cp)) return ans;
    b[x][y]='q';
    ans += solve(b, r-1, cp+1);
    b[x][y]='.';
    return ans;
}

signed main(){
    vector<vector<char>> v(8, vector<char>(8, '*'));
    for(int i = 0;i<8;i++){
        for(int j = 0;j<8;j++) cin>>v[i][j];
    }
    cout<<solve(v, 8, 0);
}