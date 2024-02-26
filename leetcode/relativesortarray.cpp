class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a map to store the index of each element in arr2
        unordered_map<int, int> indexMap;
        for (int i = 0; i < arr2.size(); ++i) {
            indexMap[arr2[i]] = i;
        }
        
        // Custom comparator function to sort arr1 according to the order of elements in arr2
        auto customComparator = [&](int a, int b) {
            if (indexMap.count(a) && indexMap.count(b)) {
                return indexMap[a] < indexMap[b]; // Compare indices if both elements are in arr2
            } else if (indexMap.count(a)) {
                return true; // a is in arr2 but b is not, so a should come before b
            } else if (indexMap.count(b)) {
                return false; // b is in arr2 but a is not, so b should come before a
            } else {
                return a < b; // Both a and b are not in arr2, so compare them directly
            }
        };
        
        // Sort arr1 using the custom comparator
        sort(arr1.begin(), arr1.end(), customComparator);
        
        return arr1;
    }
};