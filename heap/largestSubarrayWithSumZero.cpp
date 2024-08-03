class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        map<int,int> mp; int ans = 0;
        for(int i=1; i<a.size(); i++){
            a[i]+=a[i-1];
        }
        for(int i=0; i<a.size(); i++){
            if(a[i] == 0) ans = i+1;
            else if(mp.find(a[i])!=mp.end()){
                ans = max(ans, i-mp[a[i]]);
            }
            else mp[a[i]] = i;
        }
        return ans;
    }
};