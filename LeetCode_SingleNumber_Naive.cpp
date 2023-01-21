class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator itr;
        int i;
        int res = 0;
        bool flag = false;

        sort(nums.begin(), nums.end());

        for (i = 1; i < nums.size(); i += 2) {
            if (nums[i] != nums[i-1]) {
                res = nums[i-1];
                flag = true;
                break; // break the loop to avoid first element missing and verifying next element
            }
        }

        if (!flag) res = nums[i-1];

        return res;
    }
};
