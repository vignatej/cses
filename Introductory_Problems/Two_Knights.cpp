#include <bits/stdc++.h>
#define int long long
using namespace std;

static int prev_v = 96;
int solve(int n){
    vector<int> v{0,0, 6,28,96};
    if(n<=4) return v[n];
    int a = ((n-1)*(n-1)*((n-1)*(n-1)-1))/2;
    a-= prev_v;
    int b = 2;
    int ab = 2+2*(2+3+4*(n-5)+3+2);
    prev_v = (n*n*(n*n-1))/2 - (a+b+ab);
    return prev_v;
}

signed main(){
    int n; cin>>n;
    int k = 1;
    while(k<=n){
        cout<<solve(k)<<' ';
        k++;
    }
}