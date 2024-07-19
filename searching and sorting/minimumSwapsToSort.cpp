class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    vector<int> arr(nums.begin(), nums.end());
	    sort(arr.begin(), arr.end());
	    int ans = 0, n = nums.size();
	    
	    for(int i=0; i<n; i++){
	        if(nums[i] != arr[i]){
	            int cnt = 1;
	            while(nums[i] != arr[i]){
	                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
	                int j = distance(arr.begin(), it);
	                swap(nums[i], nums[j]);
	                cnt++;
	            }
	            ans += (cnt-1);
	        }
	    }
	    return ans;
	}
};