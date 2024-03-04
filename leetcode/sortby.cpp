#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T, typename F>
vector<T> sortBy(const vector<T>& arr, F fn) {
    // Custom comparator function
    auto customComparator = [&](const T& a, const T& b) {
        return fn(a) < fn(b);
    };
    
    // Copy the original array
    vector<T> sortedArr = arr;
    
    // Sort the array using the custom comparator function
    sort(sortedArr.begin(), sortedArr.end(), customComparator);
    
    return sortedArr;
}

int main() {
    // Example usage:
    vector<int> arr = {5, 4, 1, 2, 3};
    auto fn = [](int x) { return x; }; // Identity function
    
    vector<int> sortedArr = sortBy(arr, fn);
    
    // Print the sorted array
    cout << "Sorted Array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
