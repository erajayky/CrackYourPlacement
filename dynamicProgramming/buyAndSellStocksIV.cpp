class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>>(2, vector<int>(k,-1)));
        return util(k, prices, dp);
    }

    int util(int k, vector<int>& prices, vector<vector<vector<int>>> &dp, int i=0, int b=1, int m=0){
        if(i==prices.size() || m==k) return 0;
        if(dp[i][b][m] != -1) return dp[i][b][m];
        
        if(b==1)
            return dp[i][b][m] = max(util(k, prices, dp, i+1, 0, m)-prices[i], util(k, prices, dp, i+1, 1, m));
        else
            return dp[i][b][m] = max(util(k, prices, dp, i+1, 1, m+1)+prices[i], util(k, prices, dp, i+1, 0, m));
    }
};