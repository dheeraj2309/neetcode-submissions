class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int nxt1 = 0, nxt2 = 0,curr = 0;
        for(int i = n - 1; i >= 0; i--){
            // dp[i] = max(nums[i] + dp[i + 2],dp[i + 1]);
            curr = max(nums[i] + nxt2,nxt1);
            nxt2 = nxt1;
            nxt1 = curr;
        }
        return curr;
    }
};
