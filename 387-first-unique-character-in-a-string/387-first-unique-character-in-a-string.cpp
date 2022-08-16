class Solution {
private:
    const int LEN_MAX = 100000;
public:
    int firstUniqChar(string s) {
        vector < int > firstPos = vector<int>(26, LEN_MAX);
        
        for(int i = 0; i < s.size(); i++) {
            char c = s[i] - 'a';
            
            // first appear
            if(i < firstPos[c])
                firstPos[c] = i;
            // appear more than once
            else if(firstPos[c] < i)
                firstPos[c] = -1;
        }
        
        int ret = LEN_MAX;
        for(int i = 0; i < 26; i++) {
            if(firstPos[i] == -1 || firstPos[i] == LEN_MAX)
                continue;
            
            ret = min(ret, firstPos[i]);
        }
        
        if(ret == LEN_MAX)
            ret = -1;
        
        return ret;
    }
};