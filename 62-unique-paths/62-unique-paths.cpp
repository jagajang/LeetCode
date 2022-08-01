class Solution {
public:
    int uniquePaths(int m, int n) {
        // 아래 m-1번, 오른쪽 n-1번
        long long ret = 1;
        for(int i = 1; i < min(n, m); i++) {
            ret *= n + m - i - 1;
            ret /= i;
        }
            
        return (int)ret;
    }
};