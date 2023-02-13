class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int hash = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || hash <= nums[i]) nums[i] = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            int idx = nums[i] % hash;
            if (idx > 0) nums[idx - 1] += hash;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] / hash == 0) return i+1;
        }

        return hash;
    }
};
