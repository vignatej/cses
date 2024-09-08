#include <bits/stdc++.h>
using namespace std;
class seg_tree{public:
    vector<int> v; int n{1};
    seg_tree(vector<int> &arr){
        int nn  = arr.size();
        while(n<nn){n*=2;}
        v.resize(2*n, 1);
        for(int i = n-1;i>0;i--) v[i]=v[2*i]+v[2*i+1];
    }
    int calc_sum(int i, int j){
        i+=n; j+=n;int ans{0};
        while(i<=j){
            if(i%2==1){ans+=v[i]; i++;}
            if(j%2==0){ans+=v[j]; j--;}
            i/=2; j/=2;
        }return ans;
    }bool ism(int i){
        i+=n; return v[i]==1;
    }void change(int i){
        i+=n; v[i]=0;i/=2;
        while(i){v[i]=v[i*2]+v[i*2+1]; i/=2;}
    }
};

signed main(){
    int n; cin>>n; vector<int> v(n), quer(n); for(int i = 0;i<n;i++) cin>>v[i];
    for(int i = 0; i<n;i++) cin>>quer[i];   
    seg_tree s(v);
    for(auto &q: quer){
        int l = 0; int r = n-1;
        int ans{-1};
        while(l<=r){
            int m = (l+r)/2;
            int sum = s.calc_sum(0,m);
            if(sum>q){r=m-1;}
            else if(sum<q){l=m+1;}
            else{
                if(s.ism(m)){ans=m; break;}
                else{ r=m-1; }
            }
        }
        cout<<v[ans]<<' ';
        s.change(ans);
    }
}