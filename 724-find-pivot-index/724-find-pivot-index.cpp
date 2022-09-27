class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        
        for(int i = 0; i < nums.size(); i++)
            total += nums[i];
        
        int tmpSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] + tmpSum + tmpSum == total) {
                return i;
            }
            tmpSum += nums[i];
        }
        
        return -1;
    }
};