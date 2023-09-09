class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(candidates, target, 0, curr, ans);
        return ans;
    }
    
    void helper(vector<int> &candidates, int target, int start, vector<int> &curr, vector<vector<int>> &ans) {
        if (target == 0) {  // reached target value
            ans.push_back(curr);
            return;
        }
        
        if (target < 0) {
            return; // does not consider this case anymore
        }
        
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            helper(candidates, target-candidates[i], i, curr, ans);
            curr.pop_back();
        }
    }
};