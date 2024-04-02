class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int maxArea = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            
            int currentArea = std::min(height[left], height[right]) * (right - left);
            
            maxArea = std::max(maxArea, currentArea);

            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};