#include <cstring>
class Solution {
public:
    int dp[1001][1001][2];
    pair<int,int> solve(int si,int ei,string &s){
        if(si == ei){
            return {si,si};
        }
        if(si + 1 == ei){
            if(s[si] == s[ei]) return {si,ei};
            return {si,si};
        }
        if(dp[si][ei][0] != -1) return {dp[si][ei][0],dp[si][ei][1]};
        pair<int,int> ans;
        if(s[si] == s[ei]){
            auto [l,r] = solve(si + 1,ei - 1,s);
            if(l - si == 1 && ei - r == 1){
                ans = {si,ei};
            }else{
                auto [l1,r1] = solve(si + 1,ei,s);
                auto [l2,r2] = solve(si,ei - 1,s);
                if(r1 - l1 >= r2 - l2) ans = {l1,r1};
                else ans = {l2,r2};
            }
        }else{
            auto [l1,r1] = solve(si + 1,ei,s);
            auto [l2,r2] = solve(si,ei - 1,s);
            if(r1 - l1 >= r2 - l2) ans = {l1,r1};
            else ans = {l2,r2};
        }
        dp[si][ei][0] = ans.first,dp[si][ei][1] = ans.second;
        return ans;
    }
    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        auto [l,r] = solve(0,s.size() - 1,s);
        return s.substr(l,r - l + 1);
    }
};
