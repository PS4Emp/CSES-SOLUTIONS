<<<<<<< HEAD
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i++)
        cin >> grid[i];
    vector< vector<ll> > numberOfPaths(n, vector<ll>(n, 0));
    numberOfPaths[0][0] = (grid[0][0] == '.' ? 1 : 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != '*'){
                if(i - 1 >= 0 && grid[i - 1][j] != '*')
                    numberOfPaths[i][j] = (numberOfPaths[i][j] + numberOfPaths[i - 1][j]) % mod;
                if(j - 1 >= 0 && grid[i][j - 1] != '*')
                    numberOfPaths[i][j] = (numberOfPaths[i][j] + numberOfPaths[i][j - 1]) % mod;
            }
        }
    }
    cout << numberOfPaths[n - 1][n - 1] << endl; // Output the result
    return 0;
}
=======
def count_paths(description):
    # Initialize a 2D array to store the number of paths
    dp = [[0] * 7 for _ in range(7)]
    dp[0][0] = 1  # Starting point

    for char in description:
        new_dp = [[0] * 7 for _ in range(7)]

        for i in range(7):
            for j in range(7):
                if char == 'R' or char == '?':
                    if j + 1 < 7:
                        new_dp[i][j + 1] += dp[i][j]
                if char == 'L' or char == '?':
                    if j - 1 >= 0:
                        new_dp[i][j - 1] += dp[i][j]
                if char == 'D' or char == '?':
                    if i + 1 < 7:
                        new_dp[i + 1][j] += dp[i][j]
                if char == 'U' or char == '?':
                    if i - 1 >= 0:
                        new_dp[i - 1][j] += dp[i][j]
                        
        dp = new_dp  # Update dp array for next character
    
    return dp[6][0]  # Return the number of paths reaching the lower-left square

# Input
description = input()

# Output
print(count_paths(description))
>>>>>>> 5210b73df17d1a3cbfee3cfc67b95496b8fdf054
