class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs to store names and heights
        vector<pair<string, int>> people;
        for (int i = 0; i < names.size(); ++i) {
            people.push_back({names[i], heights[i]});
        }
        
        // Custom comparator function to sort people first by height (descending) and then by name (ascending)
        auto customComparator = [&](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second; // Sort by height in descending order
            } else {
                return a.first < b.first; // If heights are the same, sort by name in ascending order
            }
        };
        
        // Sort the people vector using the custom comparator
        sort(people.begin(), people.end(), customComparator);
        
        // Extract sorted names from the sorted people vector
        vector<string> sortedNames;
        for (const auto& person : people) {
            sortedNames.push_back(person.first);
        }
        
        return sortedNames;
    }
};