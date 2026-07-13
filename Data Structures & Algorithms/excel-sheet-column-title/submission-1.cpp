class Solution {
public:
    string convertToTitle(int num) {
        /*
        AAAA - 26 * 26 * 26 + 1
        332 
        332/26
        */
        string ans;
        while(num > 0){
            num--;
            int c = num % 26;
            ans += 'A' + c;
            num /= 26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};