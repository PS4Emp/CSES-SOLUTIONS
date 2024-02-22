#include <iostream>
using namespace std;

int trappedRainwater(int height[], int size){
    int leftMax[size];
    leftMax[0] = height[0];
    for(int i = 1; i < size; i++){
        leftMax[i] = max(height[i], leftMax[i-1]);
    }

    int rightMax[size];
    rightMax[size-1] = height[size-1];
    for(int i = size-2; i>=0; i--){
        rightMax[i] = max(height[i], rightMax[i+1]);
    }

    int trapWater = 0;
    for(int i = 0; i<size; i++){
        int waterLevel = min(leftMax[i], rightMax[i]);
        trapWater += waterLevel - height[i];
    }
    return trapWater;
}

int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int size = sizeof(height)/sizeof(height[0]);
    int result = (height, size);
    cout << result;
}