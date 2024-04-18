class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size(), n = num2.size();
        string result(m + n, '0');

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int total = mul + (result[i + j + 1] - '0');

                result[i + j] += total / 10;
                result[i + j + 1] = (total % 10) + '0';
            }
        }

        
        size_t pos = result.find_first_not_of('0');
        if (pos != string::npos)
            return result.substr(pos);
        else
            return "0";
    }
};