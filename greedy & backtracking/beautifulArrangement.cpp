class Solution {
public:
    int countArrangement(int n) {
        int ans = 0;
        vector<int> pos(n, 0);
        util(n, pos, 1, ans);
        return ans;
    }

    void util(int n, vector<int> &pos, int ind, int &ans){
        if(ind>n){
            ans++;
            return;
        }
        for(int i=0; i<n; i++){
            if(!pos[i] && ((i+1)%ind == 0 || ind%(i+1) == 0)){
                pos[i] = 1;
                util(n, pos, ind+1, ans);
                pos[i] = 0;
            }
        }
    }
};