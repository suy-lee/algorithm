class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>::iterator itr; // itrator definition to traverse vector
        int newIndex = 0;

        for (itr = nums.begin(); itr != nums.end(); itr++) {
            newIndex = abs(*itr) - 1;	// i) cautious when define newIndex, it could be negative

            if (nums[newIndex] > 0)     // if nums[newIndex] > 0 (which means, num newIndex+1 is now appeared in array)
                nums[newIndex] *= -1;   // so mark it as appeared (negative)
        }

        // output vector initialize
        vector<int> out;

        int i = 1;
        for (itr = nums.begin(); itr != nums.end(); itr++) {
            if (*itr > 0) out.push_back(i); // do not operate with *itr, it does not relative, just care index
            i++;
        }

        // sort
        sort(out.begin(), out.end()); // 오름차순 정렬

        return out;
    }
};
