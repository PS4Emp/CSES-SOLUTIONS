class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sorted_nums1(nums1.begin(), nums1.end());
        sort(sorted_nums1.begin(), sorted_nums1.end());
        
        int max_diff = 0;
        long long sum_diff = 0;
        
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            sum_diff += diff;
            sum_diff %= MOD;
            
            int j = lower_bound(sorted_nums1.begin(), sorted_nums1.end(), nums2[i]) - sorted_nums1.begin();
            if (j < n) {
                max_diff = max(max_diff, diff - (sorted_nums1[j] - nums2[i]));
            }
            if (j > 0) {
                max_diff = max(max_diff, diff - (nums2[i] - sorted_nums1[j - 1]));
            }
        }