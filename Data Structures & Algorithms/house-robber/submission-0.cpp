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
        memset(dp,-1,sizeof(dp));
        return solve(0,false,nums);
    }
};
