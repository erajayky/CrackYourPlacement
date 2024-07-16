class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios_base::sync_with_stdio(false), std::cin.tie(NULL);
        int ans = 0, n = prices.size();

        for(int i=1; i<n; i++){
            if(prices[i-1] < prices[i])
                ans += (prices[i] - prices[i-1]);
        }

        return ans;
    }
};