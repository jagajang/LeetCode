class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ret = 0;
        map<int,int> numCount;
        multiset<int> countSort;
        
        for(size_t i = 0; i < arr.size(); i++)
            numCount[arr[i]]++;
        
        for(map<int,int>::iterator iter = numCount.begin(); iter != numCount.end(); iter++)
            countSort.insert(-(iter->second));
        
        int need = 0;
        int sum = 0;
        for(multiset<int>::iterator iter = countSort.begin(); iter != countSort.end(); iter++) {
            need++;
            sum -= *iter;
            
            if(sum + sum >= arr.size())
                return need;
        }
        
        return -1;
    }
};