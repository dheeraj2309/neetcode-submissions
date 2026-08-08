#include <cstring>
class Solution {
public:
    int dp[101][2];
    int solve(int idx,bool prev,vector<int>&nums){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int take = -1,skip = -1;
        if(!prev){
            take = nums[idx] + solve(idx + 1,!prev,nums);
        }
        skip = solve(idx + 1,false,nums);
        return dp[idx][prev] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2,0);
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i + 2],dp[i + 1]);
        }
        return dp[0];
    }
};
