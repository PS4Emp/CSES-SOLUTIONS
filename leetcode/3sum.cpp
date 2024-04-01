class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1, right = n - 1;
            
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total < 0)
                    ++left;
                else if (total > 0)
                    --right;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
            }
        }
        
        return result;
    }
};