class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // add to unordered_set
        set<int> s;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }

        int longestStreak = 0;

        for (int num : s) {
            if (s.find(num-1) == s.end()) { // if not found
                int currentNum = num;
                int currentStreak = 1;

                while (s.find(currentNum+1) != s.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
