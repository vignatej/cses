#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n; 
    cout<<n<<' ';
    while(n!=1){
        if(n%2==0){n/=2;}
        else{n=n*3+1;}
        cout<<n<<' ';
    }
}