#include<iostream>
using namespace std;


void printSpiral(int matrix[3][3], int numRows, int numCols){
    int startRow = 0;
    int startCol = 0;
    int endRow = numRows - 1;
    int endCol = numCols - 1;

    while(startRow <= endRow &&  startCol <= endCol){
        //top 
        for(int j = startCol; j <=endCol; j++){
            cout << matrix[startRow][j] << " ";
        }
        //right
        for( int i = startRow + 1; i <=endRow; i++ ){
            cout << matrix[i][endCol] << " ";
        }
        //bottom
        for(int k = endCol -1; k>=startCol; k--){
            cout << matrix[endRow][k] << " ";
        } 
        //left
        for(int z = endRow - 1; z>= startRow + 1; z--){
            cout << matrix[z][startCol] << " ";
        }
        startCol++;
        startRow++;
        endCol--;
        endRow--;
    }
    cout << endl;
}

int main(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int numRows = sizeof(matrix) / sizeof(matrix[0]);
    int numCols = sizeof(matrix[0]) / sizeof(matrix[0][0]); 
    printSpiral(matrix, numRows, numCols);
}