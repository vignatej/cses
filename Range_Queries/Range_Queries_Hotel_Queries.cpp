#include <bits/stdc++.h>
using namespace std;

class seg_tree{ 
public:
    vector<int> v; int n{1};
    seg_tree(vector<int> &arr){
        int nn = arr.size();
        while(n<nn) n*=2;
        v.resize(2*n, 0);
        for(int i = 0;i<nn;i++) v[n+i]=arr[i];
        for(int i = n-1;i>0;i--) v[i]=max(v[2*i], v[2*i+1]);
    }
    void chan_elem(int p , int val){
        v[n+p]=val;p+=n; p/=2;
        while(p){v[p]=max(v[2*p], v[2*p+1]);p/=2;}
    }
    int get_ind(int m){
        int i = 1; 
        if(v[i]<m) return -1;
        while(i<n){
            if(v[2*i]>=m) i=2*i;
            else i=2*i+1;
        }
        return i-n;
    }

};

signed main(){
    int n, m; cin>>n>>m; 
    vector<int> h(n), r(m);
    for(int i = 0;i<n;i++) cin>>h[i];
    for(int i = 0;i<m;i++) cin>>r[i];
    seg_tree s(h);
    for(auto &i: r){
        int o = s.get_ind(i);
        cout<<o+1<<" ";
        if(o==-1) continue;
        s.chan_elem(o, h[o]-i);
        h[o]-=i;
    }

}