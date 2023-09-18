class Solution {
public:
    int find(vector<int>& nums, int l, int r) {
        int mid = (l + r) / 2;

        while (l < r) {        
            if (nums[mid] < nums[mid + 1])
                return find(nums, mid + 1, r);
            else
                return find(nums, l, mid);
        }
        
        return mid;
    }
    
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;    
        return find(nums, l, r);
    }
};