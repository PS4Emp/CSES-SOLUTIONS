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
1  2  3
4  5  6
7  8  9

for (int i = 0; i < mat[0].size(); i++) {
    if (i != ((mat.size() - 1) - i)){
        sum = sum + mat[i][i] + mat[i][((mat.size() - 1) - i)];
    } else {
        sum = sum + mat[i][i];
    }
}