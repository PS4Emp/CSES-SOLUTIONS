class Solution {
public:
    std::string intToRoman(int num) {
        
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        std::string roman_numeral = "";
        int i = 0;

        while (num > 0) {
            while (num >= values[i]) {
                roman_numeral += symbols[i];
                num -= values[i];
            }
            i++;
        }

        return roman_numeral;
    }
};