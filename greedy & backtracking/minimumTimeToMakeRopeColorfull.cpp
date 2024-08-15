class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors.push_back('1');
        int n = colors.length();
        int prev = 0, ans = 0;

        for(int i=1; i<n; i++){
            if(colors[i] != colors[i-1]){
                if(prev != i-1){
                    int maxi = INT_MIN;
                    for(int j=prev; j<i; j++){
                        ans += neededTime[j];
                        maxi = max(maxi,  neededTime[j]);
                    }
                    ans -= maxi;
                }
                prev = i;
            }
        }

        return ans;
    }
};