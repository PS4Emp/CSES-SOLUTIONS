#include <iostream>
using namespace std;

bool areIdentical(int arr[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != arr2[i]) {
            return false; // If any elements differ, arrays are not identical
        }
    }
    return true; // All elements are identical
}

int main() {
    int arr[] = {1, 2, 3};
    int arr2[] = {1, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (size != sizeof(arr2) / sizeof(arr2[0])) {
        cout << "Arrays are not identical (different sizes)";
        return 0;
    }

    bool result = areIdentical(arr, arr2, size);
    if (result == true) {
        cout << "Arrays are identical";
    } else {
        cout << "Arrays are not identical";
    }
    return 0;
}
