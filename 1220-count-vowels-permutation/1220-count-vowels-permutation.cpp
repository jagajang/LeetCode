class Solution {
private:
    const int MODULA = 1000000007;
    long long perm[20000][5];
public:
    int countVowelPermutation(int n) {
        for(int i = 0; i < 5; i++)
            perm[0][i] = 1;
        
        for(int i = 1; i < n; i++) {
            perm[i][0] = perm[i-1][1];
            perm[i][1] = (perm[i-1][0] + perm[i-1][2]) % MODULA;
            perm[i][2] = (perm[i-1][0] + perm[i-1][1] + perm[i-1][3] + perm[i-1][4]) % MODULA;
            perm[i][3] = (perm[i-1][2] + perm[i-1][4]) % MODULA;
            perm[i][4] = perm[i-1][0];
        }
        
        return (perm[n-1][0] + perm[n-1][1] + perm[n-1][2] + perm[n-1][3] + perm[n-1][4]) % MODULA;
    }
};