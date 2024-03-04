#include <vector>
using namespace std;

class Solution {
    public: 
    bool searchMatrix(vector<vector<int>>& matrix, int key){
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n -1;

        while(high >= low){
            int mid = low + (high - low) / 2;
            int midVal = matrix[mid / n][mid %2];

            if(midVal == key){
                return true;
            } else if (midVal > key){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
}; 