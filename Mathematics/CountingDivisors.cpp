#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

signed main(){
    int T; cin>>T;
    vector<int> v((int)1e6+1, 1);
    for(int i = 2;i<1e6+1;i++){
        for(int j = i; j<1e6+1; j+=i) 
            v[j]++;
    }
    while(T--){
        int n; cin>>n;
        // int c = 0;
        // int csq = sqrt(n);
        // for(int i =1;i<=csq;i++){
        //     if(n%i==0) c+=2;
        // }
        // if(csq*csq==n) c--;
        cout<<v[n]<<'\n';
    }



    
    return 0;
}