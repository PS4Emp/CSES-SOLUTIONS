class Solution {
    public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        
        if(nums.empty() || k <=0) return result;
        if(k == 1) return nums;

        int n = nums.size();

        for(int i = 0; i<= n -k; ++i){
            int windowMax = nums[i];
            for(int j = i; j < i+k; ++j){
                windowMax = max(windowMax, nums[j]);
            }
            result.push_back(windowMax);
        }
        return result;
    }
}

////////////////////////////////////////////////////////////////////////////////////2nd solution more efficient

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> deq;

    if (nums.empty() || k <= 0) return result;
    if (k == 1) return nums;

    for (int i = 0; i < nums.size(); ++i) {
        
        if (!deq.empty() && deq.front() == i - k) {
            deq.pop_front();
        }

        
        while (!deq.empty() && nums[deq.back()] < nums[i]) {
            deq.pop_back();
        }

        
        deq.push_back(i);

       
        if (i >= k - 1) {
            result.push_back(nums[deq.front()]);
        }
    }

    return result;
}