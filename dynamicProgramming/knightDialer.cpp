class Solution {
    const int mod = 1e9 + 7; // Use const for fixed values
    int moves[8][2] = {{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}};
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

public:
    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int>(n + 1, -1)); // Adjust dp size to 10 (0-9)
        
        long ans = 0;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 3; j++) {
                if(grid[i][j] != -1) {
                    ans = (ans + util(n, dp, i, j)) % mod;
                }
            }
        }
        
        return (int) ans;
    }

    int util(int n, vector<vector<int>> &dp, int i, int j) {
        if(n == 1) return 1;

        if(dp[grid[i][j]][n] != -1) return dp[grid[i][j]][n];

        long ans = 0;
        for(int m = 0; m < 8; m++) {
            int x = i + moves[m][0], y = j + moves[m][1];
            if(x >= 0 && y >= 0 && x < 4 && y < 3 && grid[x][y] != -1) {
                ans = (ans + util(n - 1, dp, x, y)) % mod;
            }
        }
        
        return dp[grid[i][j]][n] = (int) ans;
    }
};
