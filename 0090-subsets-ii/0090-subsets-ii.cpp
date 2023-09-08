class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> current;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(subsets, current, nums, 0);
        return subsets;
    }

private:
    void subsetsWithDupHelper(vector<vector<int>> &subsets, vector<int> &current, vector<int> &nums, int index) {
        subsets.push_back(current);
        
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i-1]) continue; // get rid of duplicate
            
            current.push_back(nums[i]);
            subsetsWithDupHelper(subsets, current, nums, i+1);
            current.pop_back();
        }
    }
};