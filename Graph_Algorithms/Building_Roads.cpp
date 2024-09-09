#include <bits/stdc++.h>
using namespace std;

vector<int> head;
vector<int> siz;

int get_head(int i){
    if(head[i]==i) return i;
    return head[i] = get_head(head[i]);
}
void unite(int i, int j){
    i = get_head(i); j = get_head(j);
    if(i==j) return;
    if(siz[i]<siz[j]) swap(i, j);
    head[j]=head[i];
    siz[i]+=siz[j];
}

int main(){
    int n, m; cin>>n>>m;
    head.resize(n+1);
    siz.resize(n+1);
    for(int i = 0;i<=n;i++) head[i]=i;
    for(auto &i: siz) i=1;
    for(int i =0;i<m;i++){
        int a, b; cin>>a>>b;
        unite(a, b);
    }
    for(int i = 1;i<=n;i++) head[i]=get_head(i);
    int ans{0};
    set<int> hds;
    for(int i =1;i<=n;i++) hds.insert(head[i]);
    cout<<(hds.size() - 1)<<'\n';
    vector<int> hd; copy(hds.begin(), hds.end(), back_inserter(hd));
    for(int i = 0;i<hd.size()-1;i++) cout<<hd[i]<<' '<<hd[i+1]<<'\n';
}