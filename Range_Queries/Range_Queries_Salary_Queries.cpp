#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> using multi_ordered_set = tree<T, null_type, 
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;


signed main(){
    int n, q; cin>>n>>q;
    vector<int> v(n, 0); for(int i = 0;i<n;i++) cin>>v[i];
    multi_ordered_set<int> s;
    for(auto &i: v) s.insert(i);
    for(int i = 0;i<q;i++){
        char c; int a, b; cin>>c>>a>>b;
        if(c=='!'){ a--;
            s.erase(s.find_by_order(s.order_of_key(v[a])));
            v[a]=b; s.insert(v[a]);
        }else if(c=='?'){
            int ans = s.order_of_key(b+1) -s.order_of_key(a);
            cout<<ans<<'\n';
        }
    }
}