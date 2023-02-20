class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l[n], r[n];
        vector<int> res(n);

        l[0] = nums[0];
        r[n-1] = nums[n-1];

        // accumulate multiplication from left
        for (int i = 1; i < n; i++) {
            l[i] = l[i-1] * nums[i];
        }

        // accumulate multiplication from right
        for (int i = n-2; i >= 0; i--) {
            r[i] = r[i+1] * nums[i];
        }

        // calculate array
        res[0] = r[1];
        res[n-1] = l[n-2];
        for (int i = 1; i < n-1; i++) {
            res[i] = l[i-1] * r[i+1];
        }

        return res;
    }
};
