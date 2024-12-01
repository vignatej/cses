#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double ts{0};
        ts = accumulate(nums.begin(), nums.end(), 0);
        map<double, int> m;
        for(auto &i: nums) m[i]++;
        for(int i = n-1;i>=0;i--){
            ts-=nums[i];
            m[nums[i]]--;
            double cs = ts/2;
            if(m[cs])  return nums[i];
            m[nums[i]]++;
            ts+=nums[i];
        }
        return nums[0];
        
    }
};

int main(){
    Solution s;
    vector<int> v{958,777,-746,566,989};
    cout<<s.getLargestOutlier(v);
}