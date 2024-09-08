// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// int solve(const string &s, vector<vector<bool>> &av, int x, int y, int cl){
//     if(cl==48) return 1;
//     if(s[cl]!='?'){
//         char c = s[cl]; int nx{x}, ny{y};
//         if(c=='U') nx--;
//         else if(c=='D') nx++;
//         else if(c=='L') ny--;
//         else ny++;
//         if(!(0<=nx && nx<7 && 0<=ny && ny<7)) return 0;
//         if(av[nx][ny]) return 0;
//         av[nx][ny]=true;
//         int ans = solve(s, av, nx, ny, cl+1);
//         av[nx][ny]=false;
//         return ans;
//     }
//     vector<char> v{'U','D', 'L', 'R'};
//     int ans{0};
//     for(auto &i: v){
//         char c = i; int nx{x}, ny{y};
//         if(c=='U') nx--;
//         else if(c=='D') nx++;
//         else if(c=='L') ny--;
//         else ny++;
//         if(!(0<=nx && nx<7 && 0<=ny && ny<7)) continue;
//         if(av[nx][ny]) continue;
//         av[nx][ny]=true;
//         ans += solve(s, av, nx, ny, cl+1);
//         av[nx][ny]=false;
//     }
//     return ans;
// }

// signed main(){
//     string s; cin>>s;
//     vector<vector<bool>> v(7, vector<bool> (7, false));
//     v[0][0]=true;
//     cout<<solve(s, v, 0,0,0);
// }


#include <bits/stdc++.h>
#define int long long
using namespace std;
int gans{0};
int solve(const string &s, vector<vector<bool>> &av, int x, int y, int cl) {
    if (cl == 48 && x==6 && y==0) return 1;
    if(av[6][0]) return 0;
    if (s[cl] != '?') {
        char c = s[cl]; int nx{x}, ny{y};
        if (c == 'U') nx--;
        else if (c == 'D') nx++;
        else if (c == 'L') ny--;
        else ny++;
        if (!(0 <= nx && nx < 7 && 0 <= ny && ny < 7)) return 0;
        if (av[nx][ny]) return 0;
        av[nx][ny] = true;
        int ans = solve(s, av, nx, ny, cl + 1);
        av[nx][ny] = false;
        if(gans<ans){ gans=max(gans, ans); cout<<gans<<' ';}
        return ans;
    }
    vector<char> v{'U', 'D', 'L', 'R'};
    int ans{0};
    for (auto &i : v) {
        char c = i; int nx{x}, ny{y};
        if (c == 'U') nx--;
        else if (c == 'D') nx++;
        else if (c == 'L') ny--;
        else ny++;
        if (!(0 <= nx && nx < 7 && 0 <= ny && ny < 7)) continue;
        if (av[nx][ny]) continue;
        av[nx][ny] = true;
        ans += solve(s, av, nx, ny, cl + 1);
        av[nx][ny] = false;
    }
        if(gans<ans){ gans=max(gans, ans); cout<<gans<<' ';}
    return ans;
}

signed main() {
    string s; cin >> s;
    vector<vector<bool>> v(7, vector<bool>(7, false));
    v[0][0] = true;
    cout << solve(s, v, 0, 0, 0);
}
