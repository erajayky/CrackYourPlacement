class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(nums, ans, temp, 0, nums.size());
        return ans;
    }

    void util(vector<int> &nums, vector<vector<int>> &ans, vector<int> temp, int ind, int n){
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        util(nums, ans, temp, ind+1, n);
        temp.pop_back();
        util(nums, ans, temp, ind+1, n);
    }
};
