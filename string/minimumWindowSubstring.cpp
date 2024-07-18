class Solution {
public:
    string minWindow(string s, string p) {
        int count=0;
        vector<int>mp(128,0);
        for(int i=0;i<p.size();i++){
          if(mp[p[i]]==0){
            
              count++;
          }
            mp[p[i]]++;
        }
        
        int i=0,j=0;
        int mini=INT_MAX,start=0,end=0;
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0) count--;
            while(count==0){
                if(j-i+1<mini){
                      mini=min(j-i+1,mini);
                    start=i;
                    end=j;
                }
              

                    mp[s[i]]++;
                     if(mp[s[i]]==1) count++;
               
              i++;
            }
            j++;
        }
        if(mini!=INT_MAX){
            return s.substr(start,mini);
        }
        else {
            return "";
        }
    }
};