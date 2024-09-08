#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9+7;

int calc_pow(int a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    int q = calc_pow(a, n/2);
    int ans = (q%M)*(q%M);
    if(n%2) ans = ans*a;
    ans%=M;
    return ans;
}

signed main(){
    int n; cin>>n;
    cout<<calc_pow(2, n);
}