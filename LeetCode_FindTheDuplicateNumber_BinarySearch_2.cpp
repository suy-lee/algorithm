class Solution {
public:
    int getEqualOrSmallCount(vector<int>& nums, int cur) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= cur) count++;
        }

        return count;
    }
    int findDuplicate(vector<int>& nums) {
        int low = 1; int high = nums.size();
        int duplicate = -1;

        while (low <= high) {
            int cur = (low + high) / 2;
            if (getEqualOrSmallCount(nums, cur) > cur) {
                duplicate = cur;
                high = cur - 1;
            }
            else
                low = cur + 1;

        }

        return duplicate;
    }
};
