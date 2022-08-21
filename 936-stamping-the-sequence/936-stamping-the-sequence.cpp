class Solution {
private:
    vector<int> ret = vector<int>();
    
    bool check(string &target) {
        for(int i = 0; i < target.size(); i++) {
            if(target[i] != '?')
                return false;
        }
        
        return true;
    }
    
    void solve(int left, int right, string &stamp, string &target) {
        
        cout << left << "~" << right << "\n";
        
        for(int i = left; i <= right; i++) {
            bool errFlag = false;
            int count = 0;
            
            for(int j = 0; j < stamp.size(); j++) {
                if(target[i+j] != '?' && stamp[j] != target[i+j]) {
                    errFlag = true;
                    break;
                }
                else if(target[i+j] == '?')
                    count++;
            }
            
            if(errFlag || count == stamp.size())
                continue;
                        
            for(int j = 0; j < stamp.size(); j++)
                target[i+j] = '?';
            
            solve(left, i-1, stamp, target);
            solve(i+1, right, stamp, target);
            ret.push_back(i);
            return;
        }
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        
        solve(0, target.size()-stamp.size(), stamp, target);
                
        if(!check(target))
            return vector<int>();
        
        return ret;
    }
};