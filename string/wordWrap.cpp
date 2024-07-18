class Solution {
public:
    int dp[501][2001];
   
    int helper(int ind,int curr,vector <int> &nums,int k)
    {
        if(ind == nums.size())
            return 0;
        
        if(dp[ind][curr] != -1)
            return dp[ind][curr];
        
        int pick = INT_MAX;
        
        if(nums[ind] <= curr)
            pick = helper(ind+1,curr-nums[ind]-1,nums,k);
        
        int notPick = (curr+1)*(curr+1)+ helper(ind+1,k-nums[ind]-1,nums,k);
        return dp[ ind][curr] = min(pick,notPick);
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return helper(0,k,nums,k);
    } 
};