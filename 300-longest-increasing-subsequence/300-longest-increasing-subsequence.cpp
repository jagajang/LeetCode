class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 1;
        vector < int > lenMin;
        
        lenMin.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if(lenMin.back() < num) {
                lenMin.push_back(num);
                ret++;
            }
            else {
                auto iter = lower_bound(lenMin.begin(), lenMin.end(), num);
                *iter = num;
            }
        }
        
        return ret;
    }
};