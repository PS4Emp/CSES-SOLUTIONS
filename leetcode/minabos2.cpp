#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumOfAbsDifferences(vector<int> arr1, vector<int>& arr2)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int minSum = 0;
    int n = arr1.size();

    for(int i = 0; i < n ; i++){
        minSum += abs(arr1[i] - arr2[i]);
    }
    return minSum;
}

int main() {
    vector<int> arr1 = {1,2,3};
    vector<int> arr2 = {2,3,1};

    cout << "Min. " << minSumOfAbsDifferences(arr1, arr2) << endl;

    return 0;
}