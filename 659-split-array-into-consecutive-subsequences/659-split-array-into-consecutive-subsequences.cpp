class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        //cout << "--- tc start ---\n";
        
        queue < int > seqStart;
        int numsIndex = 0;
        
        for(int val = -1000; val <= 1001; val++) {
            
            int count = 0;
            
            for(; numsIndex < nums.size() && nums[numsIndex] == val; numsIndex++)
                count++;
            
            /*if(count)
                cout << val << " : " << seqStart.size() << ", " << count << "\n";
            */
            if(count < seqStart.size()) {
                // drop sequence
                for(int i = 0; seqStart.size() > count; i++) {
                    int fr = seqStart.front();
                    seqStart.pop();
                    
                    //cout << "drop " << fr << "\n";
                    
                    if(fr + 3 > val)
                        return false;
                }
            }
            else if(count > seqStart.size()) {
                // add sequence
                for(int i = 0; seqStart.size() < count; i++) {
                    //cout << "add " << val << "\n";
                    seqStart.push(val);
                }
            }
            // numMap[val] == numMap.size() => do nothing
        }
        
        return true;
    }
};