class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        queue < int > seqStart;
        int numsIndex = 0;
        
        for(int val = -1000; val <= 1001; val++) {
            
            int count = 0;
            
            for(; numsIndex < nums.size() && nums[numsIndex] == val; numsIndex++)
                count++;

            if(count < seqStart.size()) {
                for(int i = 0; seqStart.size() > count; i++) {
                    int fr = seqStart.front();
                    seqStart.pop();
                    
                    if(fr + 3 > val)
                        return false;
                }
            }
            else if(count > seqStart.size()) {
                for(int i = 0; seqStart.size() < count; i++)
                    seqStart.push(val);
            }
        }
        
        return true;
    }
};