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
        while(n<ps) n=(n<<1);
        v.resize(2*n, 0);
        for(int i = 0;i<ps;i++) v[i+n]=arr[i];
        for(int i = n-1;i>0;i--) v[i]=v[2*i]+v[2*i+1];
    }
    int calc_sum(int a, int b){
        int t = max(a, b); a=min(a, b); b=t;
        a+=n; b+=n;
        int ans = 0;
        while(a<=b){
            if(a%2==1){ans+=v[a];a++;}
            if(b%2==0){ans+=v[b]; b--;}
            a/=2; b/=2;
        }
        return ans;
    }
    void change_elem(int p, int val){
        p+=n; int d = v[p]-val;
        while(p){v[p]-=d; p/=2;}
    }
};

signed main(){
    int n, q; cin>>n>>q;
    Vi arr(n); for(int i = 0;i<n;i++)cin>>arr[i];
    seg_tree s(arr);
    for(int i = 0;i<q;i++){
        int a, b, c; cin>>a>>b>>c;
        if(a==1){
            s.change_elem(b-1, c);
        }
        else{
            cout<<s.calc_sum(b-1, c-1)<<'\n';
        }
    }
}