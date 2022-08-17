class Solution {
private:
    const string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    string wordToMorse(string word) {
        string ret = "";
        
        for(size_t i = 0; i < word.size(); i++)
            ret += morse[word[i] - 'a'];
        
        return ret;
    }
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set <string > morse;
        
        for(size_t i = 0; i < words.size(); i++)
            morse.insert(wordToMorse(words[i]));
        
        return morse.size();
    }
};