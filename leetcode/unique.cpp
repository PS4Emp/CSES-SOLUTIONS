class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count_map;

        // Count occurrences of each value
        for (int num : arr) {
            count_map[num]++;
        }

        unordered_set<int> occurrences_set;

        // Check if the count of occurrences is unique
        for (const auto& pair : count_map) {
            int count = pair.second;
            if (occurrences_set.find(count) != occurrences_set.end()) {
                return false;
            }
            occurrences_set.insert(count);
        }

        return true;
    }
};