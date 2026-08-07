class Solution {
public:
    int tribonacci(int n) {
        int prev1 = 1, prev2 = 1, prev3 = 0, curr = 0;
        for(int i = 3; i <= n; i++){
            curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr; 
        }
        if(n == 0) return prev3;
        else if(n == 1) return prev2;
        else if(n == 2) return prev1;
        else return curr;
    }
};