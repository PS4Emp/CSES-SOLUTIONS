class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);
        return result;
    }
    
private:
    void generateParenthesisHelper(vector<string>& result, string current, int openCount, int closeCount, int n) {
        // Base case: when both open and close counts reach n
        if (openCount == n && closeCount == n) {
            result.push_back(current);
            return;
        }

        // If the number of open parentheses is less than n, add an open parenthesis
        if (openCount < n) {
            generateParenthesisHelper(result, current + '(', openCount + 1, closeCount, n);
        }

        // If the number of close parentheses is less than the number of open parentheses, add a close parenthesis
        if (closeCount < openCount) {
            generateParenthesisHelper(result, current + ')', openCount, closeCount + 1, n);
        }
    }
};