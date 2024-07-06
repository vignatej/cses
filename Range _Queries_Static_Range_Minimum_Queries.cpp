#include <bits/stdc++.h>
#define ll long long
#define int ll
#define Vi vector<int>
#define Vii vector<vector<int>>
#define Pii pair<int, int>
#define Fi first
#define Se second
using namespace std;

class seg_tree{public:
    Vi v; int n{1};
    seg_tree(Vi arr){
        int ps = arr.size();
        while(n<ps) n = (n<<1);
        v.resize(2*n, INT_MAX);
        for(int i = 0;i<ps;i++) v[i+n]=arr[i];
        for(int i = n-1;i>0;i--) v[i]=min(v[2*i], v[2*i+1]);
    }
    int get_min(int a, int b){
        int t = max(a, b); a = min(a, b); b = t;
        a+=n; b+=n;
        int ans = v[a];
        while(a<=b){
            if(a%2==1){ans=min(ans, v[a]); a++;}
            if(b%2==0){ans=min(ans, v[b]); b--;}
            a/=2; b/=2;
        }
        return ans;
    }
};

signed main(){
    int n, q; cin>>n>>q;
    Vi v(n, 0); for(int i = 0;i<n;i++){cin>>v[i];}
    seg_tree s(v);
    for(int i = 0;i<q;i++){
        int a, b; cin>>a>>b;
        cout<<s.get_min(a-1, b-1)<<'\n';
    }
}