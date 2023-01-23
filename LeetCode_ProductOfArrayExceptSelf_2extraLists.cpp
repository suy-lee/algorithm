class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int m1[n], m2[n];
        vector<int> s(n);
        int i = 0, sum = 0;

        // initialize m1, accumulated multiplication from index 0 to n-1
        m1[0] = nums[0]; sum = nums[0];
        for (i = 1; i < n; i++) {
            sum *= nums[i];
            m1[i] = sum;
        }

        // initialize m2, reverse-accumulated multiplication from index n-1 to 0
        m2[n-1] = nums[n-1]; sum = nums[n-1];
        for (i = n-2; i >= 0; i--) {
            sum *= nums[i];
            m2[i] = sum;
        }

        // make solution array
        s[0]    = m2[1];
        s[n-1]  = m1[n-2];
        for (i = 1; i < n-1; i++) {
            s[i] = m1[i-1] * m2[i+1];
        }
/*
        // print result for test
        printf("m1: ");
        for (i = 0; i < n; i++) {
            printf("%d ", m1[i]);
        }
        printf("\n");

        printf("m2: ");
        for (i = 0; i < n; i++) {
            printf("%d ", m2[i]);
        }
        printf("\n");

        printf("s: ");
        for (i = 0; i < n; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
*/
        return s;
    }
};
