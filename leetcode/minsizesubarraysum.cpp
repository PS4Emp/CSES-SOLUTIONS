class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int right = 0, left = 0, sum = 0, minLength = INT_MAX;

        while(right < n){
            sum += nums[right];

            while(sum >= target){
                minLength = std::min(minLength, right-left+1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }

};