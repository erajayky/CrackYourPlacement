class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long maxP = nums[0],minP = nums[0],result = nums[0];
        
        for(int i=1;i<nums.size();i++) {
            int temp = max({(long)nums[i],maxP*nums[i],minP*nums[i]});
            minP = min({(long)nums[i],maxP*nums[i],minP*nums[i]});
           
            if(minP<INT_MIN)
                minP=nums[i];
           
            maxP = temp;
            result = max(result,maxP);
        }
        
        return result;
    }
};