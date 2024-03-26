class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0; // Empty needle case
        
        
        for (int i = 0; i <= n - m; ++i) {
            int j;
            for (j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == m) return i; // Found the needle
        }
        
        return -1; // Needle not found
    }
};
