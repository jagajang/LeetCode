class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        size_t cut = words[0].size();
        size_t lenCheck = words.size() * cut;
        
        map < string, int > wordNeed;
        
        vector < int > ret;
            
        for(auto w : words)
            wordNeed[w]++;
        
        for(size_t st = 0; st < cut; st++) {
            int curWordNum = 0;
            map < string, int > wordCount;
            
            for(size_t i = st; i + cut <= s.size(); i += cut) {
                cout << i << " index\n";
                
                string tmp = s.substr(i, cut);
                cout << tmp << "+\n";

                if(wordNeed.count(tmp) > 0 && ++wordCount[tmp] == wordNeed[tmp])
                    curWordNum++;
                cout << wordCount[tmp] << "\n";

                if(i >= lenCheck) {
                    string prev = s.substr(i - lenCheck, cut);
                    cout << prev << "-\n";

                    if(wordNeed.count(prev) > 0 && --wordCount[prev] == wordNeed[prev] - 1)
                        curWordNum--;
                    cout << wordCount[prev] << "\n";
                }

                if(curWordNum == wordNeed.size())
                    ret.push_back(i + cut - lenCheck);
                
                cout << curWordNum << "\n";
                cout << "---\n";
            }
        }
        
        sort(ret.begin(), ret.end());
        
        return ret;
        
    }
};