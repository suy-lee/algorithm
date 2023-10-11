class Solution {
public:
    vector<int> dp;
    vector<string> wordDict;
    string s;
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = vector<int>(s.size(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return find(s.size()-1);
    }
    
    bool find(int i) {
        if (i < 0) return true; // boundary check
        
        if (dp[i] != -1) // has memoization value
            return dp[i] == 1? true: false;
        
        for (string word: wordDict) {
            // get length of current word from wordDict
            int currSize = word.size();
            // boundary check
            if (i - currSize + 1 < 0) 
                continue; // do not check this word
            
            // if word matches && recursively call i - currSize
            if (s.substr(i - currSize + 1, currSize) == word && find(i - currSize)) {
                dp[i] = 1;
                return true;
            }
        }
        
        dp[i] = 0;
        return false;
    }
};