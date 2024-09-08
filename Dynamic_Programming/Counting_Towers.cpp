#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M = 7+(int)1e9;

//  not did it
//  not did it//  not did it//  not did it//  not did it//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
//  not did it
int get1(int n){
    if(n==0) return 0;

}
int get2(int n){
    int ans{0};
    for(int i = n-1;i>=0;i--){
        ans+=get2(i)*(1+get1(n-i)*2);
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<get2(n);
    }
}