#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_cou(map<int, vector<int>> &g, int i, int k){
        set<int> nodes{i};
        vector<int> curr{i};
        if(k==0) return 1;
        if(k<0) return 0; 
        while(k--){
            vector<int> next;
            for(auto &i: curr){
                for(auto &j: g[i]) 
                    if(nodes.find(j)==nodes.end()) {next.push_back(j); nodes.insert(j);} 
            }
            curr=next;
        }
        return nodes.size();
    }
    void dfs(int n, int p, int k, int r, vector<int>& count, map<int, vector<int>>& g){
        if(k<0) return;
        count[r]++;
        for(auto &i: g[n]){
            if(i!=p) dfs(i, n, k-1, r, count, g);
        }
    }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        map<int, vector<int>> g1, g2;
        for(auto &i: edges1){
            g1[i[0]].push_back(i[1]);
            g1[i[1]].push_back(i[0]);
        }
        for(auto &i: edges2){
            g2[i[0]].push_back(i[1]);
            g2[i[1]].push_back(i[0]);
        }
        int n1 = g1.rbegin()->first+1;
        int n2 = g2.rbegin()->first+1;

        vector<int> counts1(n1, 0), counts2(n2, 0);
        for(int i = 0;i<n1;i++)
            dfs(i, -1, k, i, counts1, g1);
        
        for(int i = 0;i<n2;i++)
            dfs(i, -1, k-1, i, counts2, g2);
        int me = *max_element(counts2.begin(), counts2.end());
        for(auto &i: counts1) i+=me;
        return counts1;

        int ms{0};
        for(auto &i: g2){
            int j = i.first;
            ms=max(ms, get_cou(g2,j, k-1));
        }
        
        vector<int> ans(n1, 0);
        for(int i = 0;i<n1;i++){
            ans[i] = ms+get_cou(g1, i, k);
        }
        return ans;

    }
};

int main(){
    Solution s;
    vector<int> v{958,777,-746,566,989};
    vector<vector<int>> e1{{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> e2{{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    for(auto &i: s.maxTargetNodes(e1, e2, k))
        cout<<i<<' ';
}