class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return util(s, n, dp, 0, n-1);
    }

    int util(string &s, int &n, vector<vector<int>> &dp, int i, int j){
        if(i>=j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = util(s, n, dp, i+1, j-1);
        return dp[i][j] = min(util(s, n, dp, i+1, j), util(s, n, dp, i, j-1)) + 1;
    }
};