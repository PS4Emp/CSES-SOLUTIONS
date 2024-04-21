class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end()); // Sort the candidates to handle duplicates
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        backtrack(result, temp, candidates, target, 0);
        return result;
    }
    
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& temp, std::vector<int>& candidates, int remain, int start) {
        if (remain == 0) {
            result.push_back(temp); // Append a copy of the current combination
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            if (candidates[i] > remain) {
                break; // No need to continue if the current candidate is larger than the remaining target
            }
            temp.push_back(candidates[i]);
            backtrack(result, temp, candidates, remain - candidates[i], i + 1);
            temp.pop_back();
        }
    }
};