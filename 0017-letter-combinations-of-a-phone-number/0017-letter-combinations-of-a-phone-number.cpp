class Solution {
private:
    void backtrack(string digits, vector<string> &ans, string &curr, vector<string> &pad, int index) {
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }
        
        string value = pad[digits[index]-'0'];  // number of character size
        
        for (int i = 0; i < value.size(); i++) {
            curr.push_back(value[i]);
            backtrack(digits, ans, curr, pad, index+1);
            curr.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr;
        backtrack(digits, ans, curr, pad, 0);
        return ans;
    }
};