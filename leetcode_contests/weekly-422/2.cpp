#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n = mt.size(); int m = mt[0].size();
        vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(m, vector<ll> (2, INT_MAX)));
        priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;
        pq.push({0,{0,{0,0}}});
        dist[0][0][0]=0;
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()){
            int ct = pq.top().first;
            int inc = pq.top().second.first;
            int x = pq.top().second.second.first;
            int y = pq.top().second.second.second;
            pq.pop();
            if(x==n-1 && y==m-1) return ct;
            for(auto &d: directions){
                int ni = x+d[0]; int nj = y+d[1]; int ninc = (inc+1)%2;
                if(0<=ni && ni<n && 0<=nj && nj<m){
                    int nt = max(ct+inc+1, mt[ni][nj]+inc+1);
                    if(nt<dist[ni][nj][ninc]){
                        dist[ni][nj][ninc] = nt;
                        pq.push({nt, {ninc, {ni, nj}}});
                    }
                }
            }
        }
        return min(dist[n-1][m-1][1],dist[n-1][m-1][0]);
    }
};


signed main(){
    Solution s;
    vector<vector<int>> v{{0,0,0},{0,0,0}};
    cout<<s.minTimeToReach(v);

    return 0;
}