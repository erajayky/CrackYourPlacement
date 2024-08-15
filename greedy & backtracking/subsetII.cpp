class Solution {
    vector<vector<int>> ans;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>elem;
        util(n,k,elem,1);
        return ans;
    }

    void util(int n, int k, vector<int> &elem, int i){
        if(k==0){
            ans.push_back(elem);
            return;
        } 

        if(i>n) return;

        for(int j=i; j<=n; j++){
            elem.push_back(j);
            util(n, k-1, elem, j+1);
            elem.pop_back();
        }

    }
};