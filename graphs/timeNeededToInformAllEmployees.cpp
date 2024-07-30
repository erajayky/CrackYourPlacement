class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> time(n, INT_MAX);
        vector<vector<int>> g(n);
        queue<int> q;
        q.push(headID);
        time[headID] = 0;

        for(int i=0; i<n; i++)
            if(manager[i] != -1)
                g[manager[i]].push_back(i);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();

                for(int i:g[curr]){
                    if(time[i] > time[curr] + informTime[curr]){
                        time[i] = time[curr] + informTime[curr];
                        q.push(i);
                    }
                }

            }
        }

        int ans = *max_element(time.begin(), time.end());
        return ans;
    }
};class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> time(n, INT_MAX);
        vector<vector<int>> g(n);
        queue<int> q;
        q.push(headID);
        time[headID] = 0;

        for(int i=0; i<n; i++)
            if(manager[i] != -1)
                g[manager[i]].push_back(i);
        
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int curr = q.front();
                q.pop();

                for(int i:g[curr]){
                    if(time[i] > time[curr] + informTime[curr]){
                        time[i] = time[curr] + informTime[curr];
                        q.push(i);
                    }
                }

            }
        }

        int ans = *max_element(time.begin(), time.end());
        return ans;
    }
};