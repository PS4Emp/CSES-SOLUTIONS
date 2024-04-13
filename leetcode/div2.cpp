class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend > std::numeric_limits<int>::min()) {
                return -dividend;
            } else {
                return std::numeric_limits<int>::max();
            }
        }

        
        bool negative_result = (dividend < 0) != (divisor < 0);

        
        long long abs_dividend = std::labs(static_cast<long long>(dividend));
        long long abs_divisor = std::labs(static_cast<long long>(divisor));

        
        long long quotient = 0;

       
        while (abs_dividend >= abs_divisor) {
            long long temp = abs_divisor;
            long long multiple = 1;
            while ((temp << 1) <= abs_dividend) {
                temp <<= 1;
                multiple <<= 1;
            }
            abs_dividend -= temp;
            quotient += multiple;
        }

        
        if (negative_result) {
            quotient = -quotient;
        }

       
        if (quotient < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        } else if (quotient > std::numeric_limits<int>::max()) {
            return std::numeric_limits<int>::max();
        } else {
            return static_cast<int>(quotient);
        }
    }
};