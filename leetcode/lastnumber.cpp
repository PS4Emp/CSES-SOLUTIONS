class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        // Start from the least significant digit
        for (int i = digits.size() - 1; i >= 0; --i) {
            // Increment the digit by 1
            digits[i]++;
            // If the digit becomes 10, set it to 0 and continue to the next digit
            if (digits[i] == 10) {
                digits[i] = 0;
            } else {
                // If the digit is less than 10, no need to carry over, return the digits
                return digits;
            }
        }
        // If all digits are 9, add an additional 1 to the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
