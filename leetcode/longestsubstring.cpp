class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        int max_length = 0;
        int start = 0;
        unordered_map<char, int> char_index;

        for (int i = 0; i < s.length(); ++i) {
            if (char_index.find(s[i]) != char_index.end() && char_index[s[i]] >= start) {
                start = char_index[s[i]] + 1;
            } else {
                max_length = max(max_length, i - start + 1);
            }
            char_index[s[i]] = i;
        }

        return max_length;
    }
};