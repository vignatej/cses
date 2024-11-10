#include <bits/stdc++.h>
#define ll long long
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        long long result = 0;
        vector<long long> count(100001, 0);
        vector<long long> sum_of_subsequences(100001, 0);
        
        auto input_nums = nums;
        
        for (auto current_num : nums) {
            long long current_count = 1;
            long long current_sum = current_num;
            
            // If there is a valid subsequence ending with current_num - 1
            if (current_num > 0) {
                current_count = (current_count + count[current_num - 1]) % MOD;
            }
            
            // If there is a valid subsequence ending with current_num + 1
            if (current_num < 100000) {
                current_count = (current_count + count[current_num + 1]) % MOD;
            }
            
            // If there is a valid subsequence ending with current_num - 1
            if (current_num > 0) {
                current_sum = (current_sum + sum_of_subsequences[current_num - 1] + ((long long)count[current_num - 1] * current_num) % MOD) % MOD;
            }
            
            // If there is a valid subsequence ending with current_num + 1
            if (current_num < 100000) {
                current_sum = (current_sum + sum_of_subsequences[current_num + 1] + ((long long)count[current_num + 1] * current_num) % MOD) % MOD;
            }
            
            // Add the current subsequences sum to the total result
            result = (result + current_sum) % MOD;
            
            // Update count and sum for the current number
            count[current_num] = (count[current_num] + current_count) % MOD;
            sum_of_subsequences[current_num] = (sum_of_subsequences[current_num] + current_sum) % MOD;
        }
        
        return result;
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,1}; int k = 1;
    cout<<s.sumOfGoodSubsequences(v);
}

// curr = prev + (prev+i*count) +i
// cou = count + count+1;
// 
// 