class Solution {
public:
    vector<int> dp;
    int f(vector<int>& v, int i){
        if(i >= v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i] = max(i*v[i]+f(v,i+2), f(v,i+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> help(10001,0);
        dp.resize(10001,-1);
        for(int i = 0;i<nums.size();i++){
            help[nums[i]]++;
        }
        return f(help,0);
    }
};