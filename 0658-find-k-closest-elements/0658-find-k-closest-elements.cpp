class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        vector<int> dist;
        int sum = 0, prev_sum = 0;
        int min_i = 0;
        
        // get dist
        for (int i = 0; i < n; i++)
            dist.push_back(abs(x-arr[i]));

        for (int i = 0; i < k; i++)
            sum += dist[i];
        
        for (int i = 1; i <= n-k; i++) {
            prev_sum = sum;
            sum += dist[i+k-1];
            sum -= dist[i-1];
            if (sum < prev_sum)
                min_i = i;
        }
        
        // make ans
        for (int i = min_i; i < min_i + k; i++)
            ans.push_back(arr[i]);
        
        return ans;
    }
};