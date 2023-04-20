class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0, index = 0;
        vector<int> res;

        for ( ; i < nums.size(); i++) {
            index = abs(nums[i])-1;
            if (nums[index] > 0) nums[index] *= -1;
            else res.push_back(abs(nums[i]));
        }

        return res;
    }
};
