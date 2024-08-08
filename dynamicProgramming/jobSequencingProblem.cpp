class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [&](const Job a, const Job b){ 
            if(a.profit == b.profit) return a.dead > b.dead;
            return a.profit > b.profit; 
        });
        
        vector<bool> vis(n,false);
        int jobcnt=0,maxprofit=0;
        
        for (int i=0; i< n; i++){
            for (int j=arr[i].dead-1; j>= 0; j--){
                if (vis[j]) continue;
                 
                else{
                 vis[j]= true;
                 maxprofit+= arr[i].profit;
                 jobcnt++;
                 break;
                }
            }
        }
        
        return {jobcnt,maxprofit};
    } 
};