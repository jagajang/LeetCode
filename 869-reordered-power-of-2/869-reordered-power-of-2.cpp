class Solution {
private:
    vector<int> digitNum(long long n) {
        vector<int> ret = vector<int>(10, 0);
        
        while(n > 0) {
            ret[n%10]++;
            n /= 10;
        }
        
        return ret;
    }
    
    bool compareDigit(vector<int> a, vector<int> b) {
        for(int i = 0; i < 10; i++) {
            if(a[i] != b[i])
                return false;
        }
        
        return true;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        long long pow = 1;
        
        vector<int> digitN = digitNum(n);
        
        while(pow/10 <= n) {
            if(compareDigit(digitNum(pow), digitN))
                return true;
            pow *= 2;
        }
        
        return false;
    }
};