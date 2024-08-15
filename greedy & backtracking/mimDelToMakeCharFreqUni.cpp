class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);

        for(int i=0; i<s.length(); i++)
            freq[s[i] - 'a']++;

        sort(freq.begin(), freq.end(),[](int a, int b){
            return a > b;
        });

        int ans = 0;

        for(int i=1; i<=25; i++){
            if(!freq[i]) break;

            if(freq[i] >= freq[i-1]){
                int temp = freq[i];

                freq[i] = max(0, freq[i-1]-1);

                ans += (temp - freq[i]);
            }
        }

        return ans;
    }
};