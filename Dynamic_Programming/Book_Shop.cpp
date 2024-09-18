#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 7+(int)1e9;
int main(){
    ll n, x; cin>>n>>x;
    vector<ll> price(n), pages(n);
    for(int i = 0;i<n;i++) cin>>price[i];
    for(int i = 0;i<n;i++) cin>>pages[i];
    vector<ll> prev(x+1, 0), curr(x+1, 0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=x; j++){
            if(i!=0) curr[j]=prev[j];
            if(j>=price[i]) curr[j]=max(curr[j], pages[i]+((i!=0) ? prev[j-price[i]]:0));
        }
        prev=curr;
    }
    cout<<prev[x];
}