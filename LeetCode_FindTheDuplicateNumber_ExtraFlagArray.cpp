class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> visited(n);

        for (i = 0; i < n; i ++) visited[i] = 0;

        for (i = 0; i < n; i++) {
            if (visited[nums[i]] != 1) visited[nums[i]]++;
            else return nums[i];
        }

        return 0; // never reaches here
    }
};
