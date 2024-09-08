#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; cin>>n;
    vector<int> v; int ts{0};
    for(int i = 0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);ts+=a;
    }
    sort(v.begin(), v.end());
    int ls{0}, lc{0}, rs{ts}, rc{n};
    int ans{ts};
    int j = 0;

    for(int i = 0;i<n;i++){
        rs-=v[i]; rc--;
        ans=min(ans, lc*v[i]-ls + rs-rc*v[i]);
        lc++; ls+=v[i];
    }

    // for(int i = v[0];i<=v[n-1];i++){
    //     while(v[j+1]==i){
    //         lc++; ls+=v[j]; rc--; rs-=v[j+1];
    //         j++;
    //     }
    //     int clc{lc}, cls{ls}, crc{rc}, crs{rs};
    //     if(i>v[j]){
    //         clc++; cls+=v[j];
    //     }
    //     ans=min(ans, clc*i-cls + crs - crc*(i));
    // }

    cout<<ans;
}
