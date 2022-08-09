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
                if((long long)arr[st] * arr[en] == arr[i]) {
                    count[i] += count[st] * count[en];
                    count[i] %= MODULA;
                    if(st != en) {
                        count[i] += count[st] * count[en];
                        count[i] %= MODULA;
                    }
                    
                    st++;
                    en--;
                }
                else if((long long)arr[st] * arr[en] < arr[i])
                    st++;
                else if((long long)arr[st] * arr[en] > arr[i])
                    en--;
            }
            
            ret += count[i];
            ret %= MODULA;
        }
        
        return ret;
    }
};