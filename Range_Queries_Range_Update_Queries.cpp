#include <bits/stdc++.h>
#define ll long long
#define int ll
#define Vi vector<int>
#define Vii vector<vector<int>>
#define Pii pair<int, int>
#define Fi first
#define Se second
using namespace std;

class segtree{ public:
    Vi v; int n{1};
    segtree(Vi arr){
        int ps = arr.size();
        while(n<ps) n=(n<<1);
        v.resize(2*n, 0);
        for(int i = 0;i<ps;i++) v[i+n]=arr[i];
        for(int i = n-1;i>0;i--) v[i]=v[2*i]+v[2*i+1]; 
    }
    int calc_sum(int a, int b){
        int t = max(a, b); a = min(a, b); b = t;
        a+=n; b+=n; int s{0};
        while(a<=b){
            if(a%2==1){s+=v[a]; a++;}
            if(b%2==0){s+=v[b]; b--;}
            a/=2; b/=2;
        }return s;
    }
    void inc(int p, int val){
        p+=n;
        v[p] += val; p/=2;
        while(p){v[p]=v[2*p]+v[2*p+1]; p/=2;}
    }
};

signed main(){
    int n, q; cin>>n>>q;
    Vi v(n); for(int i = 0;i<n;i++) cin>>v[i];
    Vi d = v; for(int i = 1;i<n;i++) d[i]=v[i]-v[i-1];
    segtree s(d);
    for(int i = 0;i<q;i++){
        int a; cin>>a;
        if(a==1){
            int l, r, u; cin>>l>>r>>u;
            l--; s.inc(l, u); 
            if(r<n) s.inc(r, -u);
        }
        else{
            int b; cin>>b;
            cout<<s.calc_sum(0, b-1)<<'\n';
        }
    }
}