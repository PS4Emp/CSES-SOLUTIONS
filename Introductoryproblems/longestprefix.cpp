
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        // Iterate through characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            // Check corresponding characters in other strings
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    // If characters don't match or reached end of any string
                    return strs[0].substr(0, i);
                }
            }
        }
        // If loop completes, the prefix is the first string itself
        return strs[0];
    }
};