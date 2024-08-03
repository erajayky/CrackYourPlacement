class Solution {
public:

    int util(vector<vector<pair<int,int>>> &g, vector<vector<int>> &dp, int src, int &dst, int k){
        if(src == dst) return 0;
        if(k < 0) return INT_MAX;
        if(dp[src][k] != -1) return dp[src][k];

        int ans = INT_MAX;

        for(auto i: g[src]){
            int temp = util(g, dp, i.first, dst, k-1);
            if(temp != INT_MAX) ans = min( i.second + temp, ans);
        }

        return dp[src][k] = ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> g(n);
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));        

        for(auto i:flights){
            g[i[0]].push_back({i[1],i[2]});
        }

        int temp = util(g, dp, src, dst, k);
        return temp == INT_MAX? -1:temp;
    }
};