class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1"; // Base case
        }
        
        string prev = "1"; // Initialize with first term
        string curr;

        for (int i = 2; i <= n; ++i) {
            curr = ""; // Reset current term for each iteration
            int cnt = 1; // Count for current digit
            char prevChar = prev[0]; // Store previous character

            // Iterate through previous term (prev)
            for (int j = 1; j < prev.size(); ++j) {
                // Check if current character is same as previous
                if (prev[j] == prevChar) {
                    cnt++; // Increase count if same digit
                } else {
                    // If different digit, append count and character to current term
                    curr += to_string(cnt) + prevChar;
                    cnt = 1; // Reset count for new digit
                    prevChar = prev[j]; // Update previous character
                }
            }
            
            // Append the last digit count and character to current term
            curr += to_string(cnt) + prevChar;
            prev = curr; // Update previous term for next iteration
        }
        
        return prev; // Return the nth term
    }
};