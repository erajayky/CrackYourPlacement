class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        util(dp, 0, n);
        return dp[0];
    }

    int util(vector<int> &dp, int i, int &n){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i] != -1) return dp[i];

        return dp[i] = util(dp, i+1, n) + util(dp, i+2, n);
    }
};