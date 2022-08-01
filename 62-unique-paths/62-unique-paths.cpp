class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ret = 1;
        long long su = n + m - 1;
        long long mi = min(n, m);
        
        for(long long i = 1; i < mi; i++) {
            ret *= su - i;
            ret /= i;
        }
            
        return (int)ret;
    }
};