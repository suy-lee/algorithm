class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        int maxLen = 1;
        
        // Init #1
        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Init #2
        // Check for sub-string of length 2.
        int start = 0;
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // Check for lengths greater than 2.
        // k is length of substring
        for (int k = 3; k <= n; k++) {
            
            // Fix the starting index
            for (int i = 0; i < n - k + 1; i++) {
                
                // Get the ending index of substring from
                // starting index i and length k
                int j = i + k - 1;
                
                // Checking for sub-string from ith index to
                // jth index if str[i+1] to str[j-1] is a
                // palindrome
                if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    
                    if (k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};