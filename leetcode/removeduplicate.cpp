class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        
        // Initialize a pointer to keep track of the position to insert the next unique element
        int insert_pos = 1;
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous one
            if (nums[i] != nums[i - 1]) {
                // Move the unique element to its correct position
                nums[insert_pos++] = nums[i];
            }
        }
        
        return insert_pos;
    }
};