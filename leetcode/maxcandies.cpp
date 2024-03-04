#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // Find the maximum number of candies
        int max_candies = *max_element(candies.begin(), candies.end());
        
        // Initialize the result vector
        vector<bool> result;
        
        // Iterate through each kid's candies and check if they can have the most candies
        for (int kid_candies : candies) {
            if (kid_candies + extraCandies >= max_candies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        
        // Return the result vector
        return result;
    }
};
