class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int k = target-nums[i];
            if(umap.count(k)){
                if(i==umap[k]) continue;
                v.push_back(i);
                v.push_back(umap[k]);
                break;
            }
        }
        
        return v;
    }
};