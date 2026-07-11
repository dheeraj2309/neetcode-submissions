class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int sign = (x < 0) ? 1 : 0;
        x = abs(x);
        while(x > 0){
            int b = x % 10;
            x /= 10;
            ans = (ans * 10 + b);
        }
        ans = sign ? -1 * ans : ans;
        if( ans > INT_MAX || ans < INT_MIN) return 0;
        return ans;
    }
};
