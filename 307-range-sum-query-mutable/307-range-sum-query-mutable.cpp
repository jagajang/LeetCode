class NumArray {
private:
    int numSize;
    vector<int> segTree;
    
    /*
        pos : current index in segTree
        segTree[pos] : sum of n where left <= n < right
        target : sum of n where rangeLeft <= n < rangeRight
    */
    int getSum(int pos, int left, int right, int rangeLeft, int rangeRight) {
        // in range
        if(rangeLeft <= left && right <= rangeRight)
            return this->segTree[pos];
        
        // not in range
        if(right <= rangeLeft || rangeRight <= left)
            return 0;
        
        // some in range
        int mid = (left + right) / 2;
        int ret = 0;
        
        // add left half (left ~ mid-1)
        if(rangeLeft < mid)
            ret += getSum(2*pos, left, mid, rangeLeft, rangeRight);
        if(mid < rangeRight)
            ret += getSum(2*pos+1, mid, right, rangeLeft, rangeRight);
            
        return ret;
    }

public:
    NumArray(vector<int>& nums) {
        this->numSize = 1;
        while(this->numSize < nums.size()) {
            this->numSize *= 2;
        }
        
        this->segTree.resize(this->numSize * 2);
        
        for(int i = 0; i < nums.size(); i++)
            this->segTree[this->numSize + i] = nums[i];
        
        for(int i = this->numSize - 1; i > 0; i--)
            this->segTree[i] = this->segTree[2*i] + this->segTree[2*i + 1];
    }
    
    void update(int index, int val) {
        int pos = this->numSize + index;
        int diff = val - this->segTree[pos];
        
        while(pos) {
            this->segTree[pos] += diff;
            pos /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        return getSum(1, 0, this->numSize, left, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */