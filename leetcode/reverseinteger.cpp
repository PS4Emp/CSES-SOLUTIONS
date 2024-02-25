#include <limits>

class Solution {
public:
    int reverse(int x) {
        // Constants for 32-bit signed integer range
        const int MAX_INT = std::numeric_limits<int>::max();
        const int MIN_INT = std::numeric_limits<int>::min();
        
        // Check if x is negative
        bool is_negative = x < 0;
        
        // Take the absolute value of x
        x = abs(x);
        
        // Reverse the digits
        long reversed_x = 0; // Use long to handle potential overflow
        while (x != 0) {
            int digit = x % 10;
            reversed_x = reversed_x * 10 + digit;
            x /= 10;
        }
        
        // Make the reversed integer negative if the original was negative
        if (is_negative) {
            reversed_x = -reversed_x;
        }
        
        // Check if the reversed integer is within the 32-bit range
        if (reversed_x < MIN_INT || reversed_x > MAX_INT) {
            return 0;
        }
        
        return reversed_x;
    }
};
