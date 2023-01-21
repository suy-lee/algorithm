class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<int>::iterator itr;

        // traverse
        for (itr = nums.begin(); itr != nums.end(); itr++) {
            // check whether um contains nums[i]
            // if not, insert the element
            if (!um.count(*itr)) 
                um.insert(make_pair(*itr, 0));
            // else, DELETE the element
            else 
                um.erase(*itr);
        }

        // check the size
        //printf("um size: %d\n", um.size());

        // get left element
        unordered_map<int, int>::iterator it = um.begin();  // first element is missing element
        return it->first;   // first means key, second means value
    }
};
