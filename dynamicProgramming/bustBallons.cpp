class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return util(1, n, nums, dp);
    }

    int util(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int n = nums.size();
        int ans = INT_MIN;

        for(int ind = i; ind<=j; ind++){
            int cost = nums[i-1]*nums[ind]*nums[j+1] + util(i, ind-1, nums, dp) + util(ind+1, j, nums, dp);
            ans = max(ans, cost);
        }

        return dp[i][j] = ans;
    }
};