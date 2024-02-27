class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int numRows = mat.size();
        int numCols = mat[0].size();
        
        for(int i = 0; i< numRows; i++){
            for(int k = 0; k< numCols; k++){
                if(i == k || i+k == numCols - 1){
                    sum += mat[i][k];
                }
            }
        }
        return sum;
    }
};