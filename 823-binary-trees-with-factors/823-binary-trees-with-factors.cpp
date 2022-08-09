class Solution {
private:
    const long long MODULA = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
    
        int ret = 0;
        vector < long long > count = vector<long long>(1000, 1);
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size(); i++) {
            int st = 0, en = i - 1;
            
            while(st <= en) {
                if(arr[st] == arr[i] / arr[en] && arr[i] % arr[en] == 0) {
                    long long tmp = count[st] * count[en];
                    count[i] += (st != en) ? tmp<<1 : tmp;
                    count[i] %= MODULA;
                    
                    st++;
                    en--;
                }
                else if(arr[st] <= arr[i] / arr[en])
                    st++;
                else
                    en--;
            }
            
            ret += count[i];
            ret %= MODULA;
        }
        
        return ret;
    }
};