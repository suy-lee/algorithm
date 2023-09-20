class Solution {
public:
    // Approach 4. Search Space Reduction
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // starts from left-bottom
        int row = m - 1;
        int col = 0;
        
        while (row >= 0 && col <= n - 1) {
            if (matrix[row][col] == target)
                return true;
            
            if (matrix[row][col] > target)
                row--;
            else
                col++;
        }
        
        return false;
    }
};