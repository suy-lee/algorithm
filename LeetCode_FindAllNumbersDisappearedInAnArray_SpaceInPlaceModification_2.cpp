class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s;

        for (int i = 0; i < n; i++) {
            int newIndex = abs(nums[i])-1;
            if (nums[newIndex] > 0)
                nums[newIndex] *= -1;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                s.push_back(i+1);
        }

        return s;
    }
};
