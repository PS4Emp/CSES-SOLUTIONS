class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 2;
        while (k >= 0 && nums[k] >= nums[k + 1]) {
            k--;
        }
        
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int l = nums.size() - 1;
        while (nums[k] >= nums[l]) {
            l--;
        }
        
        swap(nums[k], nums[l]);
        
        reverse(nums.begin() + k + 1, nums.end());
    }
};