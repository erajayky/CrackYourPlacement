 int count=0;
        vector<int>mp(26,0);
        for(int i=0;i<p.size();i++){
          if(mp[p[i]-'a']==0){
            
              count++;
          }
            mp[p[i]-'a']++;
        }
        
        int i=0,j=0;
        int mini=INT_MAX,start=0,end=0;
        while(j<s.size()){
            mp[s[j]-'a']--;
            if(mp[s[j]-'a']==0) count--;
            while(count==0){
                if(j-i+1<mini){
                      mini=min(j-i+1,mini);
                    start=i;
                    end=j;
                }
              

                    mp[s[i]-'a']++;
                     if(mp[s[i]-'a']==1) count++;
               
              i++;
            }
            j++;
        }
        if(mini!=INT_MAX){
            return s.substr(start,mini);
        }
        else {
            return "-1";
        }