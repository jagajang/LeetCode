class Solution {
public:
    int uniquePaths(int m, int n) {
        vector < int > v;
        
        v.resize(m);
        v[0] = 1;
        
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                v[j] += v[j-1];
            
        return v[m-1];
    }
};