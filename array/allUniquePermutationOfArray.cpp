class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> A ,int n) {
        set<vector<int>> s;
        vector<vector<int>> res;
        helper(A,0,n,s);
        for(auto itr: s){
            res.push_back(itr);
        }
        return res;
    }
    
    void helper(vector<int> &a, int curr, int n, set<vector<int>> &s){
        if(curr == n){
            s.insert(a);
            return;
        }
        
        for(int i=curr; i<n; i++){
            swap(a[curr], a[i]);
            helper(a, curr+1, n, s);
            swap(a[curr], a[i]);
        }
    }
    
};