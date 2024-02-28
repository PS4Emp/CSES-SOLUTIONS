class Solution {
public:
    bool isPalindrome(string str) {
        int left = 0;
        int right = str.length() - 1;

        while(left < right) {
            while ( left < right && !isalnum(str[left])){
                left++;
            }
            while ( left < right && !isalnum(str[right])){
                right--; // Decrement right instead of incrementing
            }

            if(tolower(str[left]) != tolower(str[right])){
                return false;
            }
            left++;
            right--; // Decrement right after comparing characters
        }

        return true;
    }
};
