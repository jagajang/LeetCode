class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector < int > lenMin;
        
        lenMin.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            
            if(lenMin.back() < num) {
                lenMin.push_back(num);
            }
            else {
                vector<int>::iterator iter = lower_bound(lenMin.begin(), lenMin.end(), num);
                *iter = num;
            }
        }
        
        return lenMin.size();
    }
};