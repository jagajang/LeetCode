const int DEPTH_MAX = 1000;

struct WordInfo {
    int depth = DEPTH_MAX;
    set<int> parent;
};

class Solution {
private:
    int wordSize;
    vector < WordInfo > wordInfos;
    
    bool canMake(string a, string b);
    void getRoute(int now, vector<string> &route, vector<string>& wordList, vector<vector<string>> &ret);

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        wordList.push_back(beginWord);
        
        wordSize = wordList.size();
        wordInfos = vector<WordInfo>(wordSize);
        wordInfos.back().depth = 0;
        
        queue < int > bfs;
        bfs.push(wordSize-1);
        
        while(!bfs.empty()) {
            int now = bfs.front();
            bfs.pop();

            int nowDepth = wordInfos[now].depth;
            string nowWord = wordList[now];
            
            for(int nex = 0; nex < wordSize; nex++) {             
                if(now == nex || !canMake(nowWord, wordList[nex]) || wordInfos[nex].depth < nowDepth + 1)
                    continue;
                
                if(wordInfos[nex].depth == nowDepth + 1) {
                    wordInfos[nex].parent.insert(now);
                    continue;
                }
                
                wordInfos[nex].depth = nowDepth + 1;
                wordInfos[nex].parent.insert(now);
                bfs.push(nex);
            }
        }
                              
        bool foundFlag = false;
        int endIndex;
        for(endIndex = 0; endIndex < wordSize; endIndex++)
            if(!endWord.compare(wordList[endIndex])) {
                foundFlag = true;
                break;
            }
        if(!foundFlag) {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> ret;
        vector<string> route = vector<string>(wordInfos[endIndex].depth + 1);
        
        route.back() = endWord;

        getRoute(endIndex, route, wordList, ret);
                
        return ret;
    }
};


bool Solution::canMake(string a, string b) {
    bool diffOne = false;
    for(size_t i = 0; i < a.size(); i++) {
        if(a[i] == b[i])
            continue;

        if(diffOne)
            return false;
        diffOne = true;
    }

    return true;
}

void Solution::getRoute(int now, vector<string> &route, vector<string>& wordList, vector<vector<string>> &ret) {
    if(now == wordSize - 1) {
        ret.push_back(route);
        return;
    }

    int parentDepth = wordInfos[now].depth - 1;
    set<int> parent = wordInfos[now].parent;

    for(int nex : parent) {
        route[parentDepth] = wordList[nex];
        getRoute(nex, route, wordList, ret);
    }
}