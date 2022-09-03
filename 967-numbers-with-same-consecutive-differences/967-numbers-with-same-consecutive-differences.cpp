class Solution {
private:
    vector<int> ret;
    
    void makeNum(int num, int appendRight, int diff) {
        
        if(appendRight == 0) {
            ret.push_back(num);
            return;
        }
        if(num == 0) {
            for(int i = 1; i < 10; i++)
                makeNum(i, appendRight-1, diff);
            return;
        }
        
        int lastNumeral = num % 10;
        
        if(lastNumeral - diff >= 0)
            makeNum(10*num + lastNumeral - diff, appendRight-1, diff);
        if(lastNumeral + diff < 10 && diff)
            makeNum(10*num + lastNumeral + diff, appendRight-1, diff);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        makeNum(0, n, k);
        return ret;
    }
};