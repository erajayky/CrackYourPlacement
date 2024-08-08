class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size(), m = s2.size(), ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
                
        return ans;
    }
};