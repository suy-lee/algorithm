class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int currentNum = -10^9 -1;
        
        for (int num: nums) {
            if (num != currentNum) {
                currentNum = num;
            } else return true; 
        }

        return false;
    }
};
