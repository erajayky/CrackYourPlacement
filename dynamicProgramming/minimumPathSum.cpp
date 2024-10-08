class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));

        for(int i=1; i<m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int i=1; i<n; i++) dp[0][i] = dp[0][i-1] + grid[0][i];

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];

        for(auto i:dp){
            for(int j:i) cout << j << " ";
            cout <<endl;
        }
        
        return dp[m-1][n-1];        
    }
};