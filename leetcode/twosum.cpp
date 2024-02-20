class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create an unordered_map to store the elements of nums along with their indices
        std::unordered_map<int, int> num_map;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];
            
            // If the complement exists in the map, return its index along with the current index
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            // Otherwise, store the current element and its index in the map
            num_map[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};