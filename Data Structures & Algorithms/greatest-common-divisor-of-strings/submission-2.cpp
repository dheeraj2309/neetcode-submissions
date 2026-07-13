class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        if(s1.size() < s2.size()) swap(s1,s2);
        int m = s1.size(),n = s2.size();
        // check if s2 is already GCD
        if(m % n == 0){
            string temp;
            temp.reserve(m/n);
            for(int i = 0; i < m/n; i++) temp += s2;
            if(s1  == temp) return s2;
        }
        // if GCD exits , it is smaller than s2 and is substring of s2
        // i have to find the shortest subtring which divides s2
        int idx = 0;
        for(int i = 1; i < n; i++){
            if(n % i == 0){
                string temp;
                temp.reserve(n/i);
                string sub = s2.substr(0,i);
                for(int j = 0; j < n/i; j++) temp += sub;
                if(temp == s2){
                    idx = i;
                    break;
                }
            }
        }
        if(idx == 0) return "";
        string ans = s2.substr(0,idx);
        // possible gcd now is s2.substr(0,idx)
        if( m % idx == 0){
            string temp;
            temp.reserve(m/idx);
            for(int i = 0; i < m/idx; i++) temp += ans;
            if(s1 == temp) return ans;
        }

        return "";
    }
};