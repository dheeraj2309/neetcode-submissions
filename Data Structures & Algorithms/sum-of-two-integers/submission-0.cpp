class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            uint32_t carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
