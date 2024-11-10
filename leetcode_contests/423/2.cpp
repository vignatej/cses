#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> inc_sizes;;
        int inc_len = 0;
        nums.insert(nums.begin(), INT_MIN);

        for(int i = 1;i<nums.size();i++){ 
            if(nums[i]>nums[i-1]){ 
                inc_len++;
                
            }
            else{ 
                inc_sizes.push_back(inc_len+1);
                inc_len=0;
            }
            if(i==nums.size()-1) inc_sizes.push_back(inc_len+1);
        }
        nums.erase(nums.begin()); inc_sizes[0]-=1;
        int ans = (*max_element(inc_sizes.begin(), inc_sizes.end()))/2;
        for(int i = 1;i<inc_sizes.size();i++){
            ans=max(ans, min(inc_sizes[i], inc_sizes[i-1]));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> v{19,-14,0,9}; int k = 1;
    cout<<s.maxIncreasingSubarrays(v);
}

        // 2,5,7,8,9,2,3,4,3,1
        // 0,1,2,3,4,5,6,7,8,9
        // 0,1,2,3,4,4,5,6,7,7