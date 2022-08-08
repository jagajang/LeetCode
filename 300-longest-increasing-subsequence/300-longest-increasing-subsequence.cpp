class Solution {
private:
    int lisLen[2500];
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            lisLen[i] = max(lisLen[i], 1);
            ret = max(ret, lisLen[i]);
            
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] < nums[j])
                    lisLen[j] = max(lisLen[j], lisLen[i] + 1);
            }
        }
        
        return ret;
    }
};