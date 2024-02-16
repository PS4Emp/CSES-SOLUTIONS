class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        // Sort the array
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        // Sum the minimum of each pair
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};