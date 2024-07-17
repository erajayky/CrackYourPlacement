class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        map<int,int>mp;
        mp[0]++;
        vector<int> sum(n+1, 0);
        
        for(int i=1; i<=n; i++){
            sum[i] = nums[i-1] + sum[i-1];
            int diff = sum[i] - k;
            if(mp.find(diff) != mp.end()){
                ans += mp[diff];
            }
            mp[sum[i]]++;
        }

        return ans;        
    }
};