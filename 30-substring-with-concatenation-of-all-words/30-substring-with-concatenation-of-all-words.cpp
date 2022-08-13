class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        size_t cut = words[0].size();
        size_t lenCheck = words.size() * cut;
        
        vector < int > ret;
        
        map < string, int > wordNeed;    
        for(auto w : words)
            wordNeed[w]++;
        
        for(size_t st = 0; st < cut; st++) {
            int curWordNum = 0;
            map < string, int > wordCount;
            
            for(size_t i = st; i + cut <= s.size(); i += cut) {
                string tmp = s.substr(i, cut);

                if(wordNeed.count(tmp) > 0 && ++wordCount[tmp] == wordNeed[tmp])
                    curWordNum++;

                if(i >= lenCheck) {
                    string prev = s.substr(i - lenCheck, cut);

                    if(wordNeed.count(prev) > 0 && --wordCount[prev] == wordNeed[prev] - 1)
                        curWordNum--;
                }

                if(curWordNum == wordNeed.size())
                    ret.push_back(i + cut - lenCheck);
            }
        }
        
        sort(ret.begin(), ret.end());
        
        return ret;
        
    }
};