class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);

        return util(s, dp, 0, n);
    }

    int util(string s, vector<int> &dp, int i, int n){
        if(i == n) return 1;

        if(dp[i] != -1) return dp[i];
        int ans = 0;

        int o = s[i] - '0';
        if(o == 0) return dp[i] = 0;
        ans += util(s, dp, i+1, n);


        if(i+1 < n){
            int t = (s[i] - '0')*10 + (s[i+1] - '0');
            if(t <= 26) ans+=util(s, dp, i+2, n);
        }     

        return dp[i] = ans;
    }
};