class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        map<int, int>::iterator it1, it2;
        int cur_len = 1, max_len = 0;
        int cur = 0, next = 0;

        if (nums.size() == 0) return 0;

        for (int i = 0; i < nums.size(); i++) {
            m.insert(make_pair(nums[i], 0));
        } // O(n)

        for (it1 = m.begin(); it1 != m.end(); it1++) {
            it2 = std::next(it1, 1);
            if (it2 == m.end()) break;
            cur = it1->first;
            next = it2->first;

            if (next != cur + 1) { // sequence ends
                // handling routine
                if (cur_len > max_len) max_len = cur_len;
                cur_len = 1;
            }
            //else if (next == cur) // care duplicated case
                //; // do nothing // no need since map overwrites duplicated key
            else cur_len++;
        }

        if (cur_len > max_len) max_len = cur_len;

        return max_len;
    }
};
