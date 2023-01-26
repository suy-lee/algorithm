class Solution {
public:
    int getSmallOrEqual(int cur, vector<int> &nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= cur) count++;
        }
        return count;
    }

    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size();
        int duplicate = -1;

        while (low <= high) {
            int cur = (low + high) / 2;

            if (getSmallOrEqual(cur, nums) > cur) {
                duplicate = cur;
                high = cur - 1;
            }
            else {
                low = cur + 1;
            }
        }

        return duplicate;
    }
};
