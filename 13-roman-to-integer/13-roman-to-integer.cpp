class Solution {
private:
public:
    int romanToInt(string s) {
        int ret = 0;
        
        for(size_t i = 0; i < s.size(); i++) {
            char c = s[i];
            
            int prev;
            if(c == 'M') {
                prev = ret % 1000;
                ret += 1000 - 2*prev;;
            }
            else if(c == 'C') {
                prev = ret % 100;
                ret += 100 - 2*prev;
            }
            else if(c == 'X') {
                prev = ret % 10;
                ret += 10 - 2*prev;
            }
            else if(c == 'I')
                ret++;
            else if(c == 'D') {
                int prev = ret % 1000;
                ret += 500 - 2*prev;
            }
            else if(c == 'L') {
                int prev = ret % 100;
                ret += 50 - 2*prev;
            }
            else if(c == 'V') {
                int prev = ret % 10;
                ret += 5 - 2*prev;
            }
        }
        return ret;
    }
};