class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n + 1,0);
        vector<int> dp1(n + 2,0);
        for(int i = n - 2; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i + 2],dp[i + 1]);
        }
        for(int i = n - 1; i >= 1; i--){
            dp1[i] = max(nums[i] + dp1[i + 2],dp1[i + 1]);
        }
        return max(dp[0],dp1[1]);
    }
};
