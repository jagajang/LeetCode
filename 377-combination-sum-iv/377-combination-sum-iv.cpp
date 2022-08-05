class Solution {
private:
    const int INT_OVERFLOW = 10000000000;
public:
    int combinationSum4(vector<int>& nums, int target) {
        long long numCase[1001] = {0, };
        
        sort(nums.begin(), nums.end());
        
        numCase[0] = 1;
        
        for(int i = 0; i < target; i++)
            for(int j = 0; j < nums.size(); j++) {
                int next = i + nums[j];
                if(next > target)
                    break;
                    
                numCase[next] += numCase[i];
                numCase[next] %= INT_OVERFLOW;
            }
                
        
        return numCase[target];
    }
};