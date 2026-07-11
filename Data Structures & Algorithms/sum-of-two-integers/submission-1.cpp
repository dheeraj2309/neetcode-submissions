class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0;
        for(int i = 0; i < 32; i++){
            int ai = (a >> i) & 1;
            int bi = (b >> i) & 1;
            int sum = ai ^ bi ^ carry;
            carry = ai + bi + carry >= 2;
            if(sum) ans |= (1 << i);
        }
        return ans;
    }
};
