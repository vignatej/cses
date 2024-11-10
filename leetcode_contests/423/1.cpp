#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<ll> ps{0};
        int n = nums.size();
        for(int i = 1;i<n;i++){ 
            if(nums[i]>nums[i-1]) ps.push_back(ps.back()+1);
            else ps.push_back(ps.back());
        }
        for(int i = 0;i<=n-2*k;i++){
            ll s1 = ps[i+k-1]-ps[i]+1;
            ll s2 = ps[i+2*k-1]-ps[i+k]+1;
            if(s1==k && s2==k) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> v{5,4,3,2,1}; int k = 1;
    cout<<s.hasIncreasingSubarrays(v, k);
}

        // 2,5,7,8,9,2,3,4,3,1
        // 0,1,2,3,4,5,6,7,8,9
        // 0,1,2,3,4,4,5,6,7,7