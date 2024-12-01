#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    pair<int, int> get_e_o(map<int, vector<int>> &g){
        vector<int> curr{0};
        set<int> comp{0};
        int e{1}, o{0}; bool odd = true;
        while(curr.size()){
            vector<int> next;
            for(auto &i: curr) 
                for(auto &j: g[i])
                    if(comp.find(j)==comp.end()){next.push_back(j); comp.insert(j);}
            if(odd) o+=next.size();
            else e+=next.size();
            curr=next;
            odd=!odd;
        }
        return {e, o};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

        pair<int, int> e_o1 = get_e_o(g1);
        pair<int, int> e_o2 = get_e_o(g2);
        vector<int> v1(n1, 0);
        v1[0]=e_o1.first;
        vector<int> curr {0};
        set<int> comp{0};
        bool odd = true;
        while(curr.size()){
            vector<int> next;
            for(auto &i: curr)
                for(auto &j: g1[i])
                    if(comp.find(j)==comp.end()) {
                        next.push_back(j); 
                        comp.insert(j);
                        if(odd) v1[j]=e_o1.second;
                        else v1[j]=e_o1.first;
                    }
            odd=!odd;
            curr=next;
        }

        for(auto &i: v1) i+=max(e_o2.second, e_o2.first);
        return v1;


    }
};

int main(){
    Solution s;
    vector<int> v{958,777,-746,566,989};
    vector<vector<int>> e1{{0,1},{0,2},{2,3},{2,4}};
    vector<vector<int>> e2{{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};
    int k = 2;
    for(auto &i: s.maxTargetNodes(e1, e2))
        cout<<i<<' ';
}