class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int hash = nums.size() + 1;
        int idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || hash <= nums[i]) nums[i] = 0; // initialize to 0 since negative and 0 are meaningless
        }

        // 1st process
        for (int i = 0; i < nums.size(); i++) {
            idx = nums[i] % hash;
            if (0 < idx) nums[idx - 1] += hash; 
        }

        // 2nd process
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] / hash == 0) return i+1;
        }
        
        // exception
        return hash;
    }
};
