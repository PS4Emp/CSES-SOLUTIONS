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
