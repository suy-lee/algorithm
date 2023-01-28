class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> sol;
        int newIndex = -1;

        for (int i = 0; i < nums.size(); i++) {
            newIndex = abs(nums[i])-1;
            if (nums[newIndex] < 0) sol.push_back(abs(nums[i]));    // if element is negative, push it to solution array
            nums[newIndex] *= -1;                                   // just flip it to negative
        }

        return sol;
    }
};
