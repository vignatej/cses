#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n, k; cin>>n>>k;
        map<int, int> m;
        for(int i = 0;i<k;i++){
            int b, v; cin>>b>>v;
            m[b]+=v;
        }
        priority_queue<int> pq;
        for(auto &i: m) pq.push(i.second);
        ll ans{0};
        while(n-- && pq.size()){
            ans+=pq.top();
            pq.pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}