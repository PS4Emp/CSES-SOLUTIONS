class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int max_length = 1;

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (length == 2 && s[i] == s[j]) {
                    dp[i][j] = true;
                    start = i;
                    max_length = length;
                } else if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    max_length = length;
                }
            }
        }

        return s.substr(start, max_length);
    }
};