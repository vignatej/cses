#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll M = 1e9+7;

signed main(){
    int n; cin>>n; 
    map<int, int> m;
    int cn{n};
    for(int i =2;i<=cn;i++){
        if(cn%i!=0) continue;
        while(cn%i==0){
            cn/=i; m[i]++;
        }
    }
    vector<int> prods;
    for(auto &i: m){
        int f = i.first; int s = i.second;
        int su{1}; int p{1};
        for(int j = 1;j<=s;j++){
            p*=f; p%=M;
            su+=p;
            su%=M;
        }
        prods.push_back(su);
    }
    int ans{1};
    for(auto &i: prods){
        ans*=i; ans%=M;
    }
    cout<<ans<<'\n';

    return 0;
}