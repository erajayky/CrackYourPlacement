class Solution {
public:
    int solve(int i,int j,int k,vector<string>& strs,vector<int>& nz,vector<vector<vector<int>>>& dp){
        if(i==strs.size()){
             if(j>=0 && k>=0) return 0;
             else return -1e9;
        }
        
        if(j<0 || k<0) return -1e9;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        int nt = solve(i+1,j,k,strs,nz,dp);
        int t = 0;
        if(nz[i]<=j && (strs[i].length()-nz[i])<=k){
            t = 1 + solve(i+1,j-nz[i],k-strs[i].length()+nz[i],strs,nz,dp);
        }
        return dp[i][j][k] = max(t,nt);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k=strs.size();
        vector<int> nz(k);
        for(int i=0;i<k;i++){
            string temp = strs[i];
            int count = 0;
            for(int j=0;j<temp.length();j++){
                if(temp[j]=='0') count++;
            }
            nz[i] = count;
        }

        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0,m,n,strs,nz,dp);
    }
};