class Solution{
public:
    bool solve(int index, int target, vector<vector<int>> &dp, int arr[]){
         if(target == 0){
             return 1;
         }
         if(target < 0 || index < 0){
             return 0;
         }
         if(dp[index][target] != -1){
             return dp[index][target];
         }
         
         bool nontake = solve(index-1, target, dp, arr);
         bool take = solve(index-1, target-arr[index], dp, arr);
         
         return dp[index][target] = take | nontake;
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0; i<N; i++){
            sum = sum + arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        
        int target = sum/2;
        vector<vector<int>> dp(N, vector<int>(target+1, -1));
        return solve(N-1, target, dp, arr);
    }
};