class Solution {
private:
    const int NUM_MAX = 1000000001;
    
    int matSize, matSq;
    vector < int > matComp;
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        matSize = matrix.size();
        matComp.resize(matSize);
        
        int minVal;
        
        for(int i = 0; i < k; i++) {
            int minIdx = -1;
            minVal = NUM_MAX;
            
            for(int j = 0; j < matSize; j++) {
                int idx = matComp[j];
                
                if(idx == matSize)
                    continue;
                
                if(matrix[j][idx] < minVal) {
                    minVal = matrix[j][idx];
                    minIdx = j;
                }
            }
            matComp[minIdx]++;
            
            //cout << i << " : " << minVal << "\n";
        }

        return minVal;
    }
};