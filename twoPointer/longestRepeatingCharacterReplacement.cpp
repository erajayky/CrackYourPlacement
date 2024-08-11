class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxFreq = 0, ans = 0, j = 0, n = s.length();
       vector<int> freq(26, 0);

       for(int i=0; i<n; i++){
            freq[s[i]-'A']++;
            maxFreq=max(maxFreq, freq[s[i]-'A']);

            if(i-j+1-maxFreq>k && j<i){
                freq[s[j]-'A']--;
                j++;
            }

            if(i-j+1-maxFreq<=k) ans=max(ans,i-j+1);
       }

       return ans;
    }
};