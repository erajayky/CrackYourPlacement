class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(int i=0; i<tasks.size(); i++)
            freq[tasks[i] - 'A']++;
        
        int maxFreq = 0, cnt = 0;

        for(int i:freq){
            if(maxFreq<i){
                maxFreq = i;
                cnt=1;
            }else if(maxFreq == i) cnt++;
        }

        for(int i:freq) cout << i << " ";cout<<endl;

        int a = ((maxFreq-1)*(n+1))+cnt, b=tasks.size();
        return max(a, b);
    }
};