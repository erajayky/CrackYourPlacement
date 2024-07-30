class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), rst(n, 0), ans;
        vector<vector<int>> g(n);

        for(int i=0; i<n; i++)
            for(int j: graph[i])
                g[i].push_back(j);
            
        for(int i=0; i<n; i++)
            if(vis[i] == 0){
                int r = util(g, vis, rst, i);
                if(r == 2) vis[i] = 2;
            }
        
        for(int i=0; i<n; i++)
            if(vis[i] != 2)
                ans.push_back(i);
        
        return ans;
    }

    int util(vector<vector<int>>& g, vector<int> &vis, vector<int> &rst, int i){
        vis[i] = 1;
        rst[i] = 1;

        for(int x:g[i]){
                if(rst[x]){
                    vis[i] = 2;
                    return 2;
                }
                
                if(vis[x] == 0){
                    int r = util(g, vis, rst, x);
                    if(r == 2){
                        vis[x] = 2;
                        return 2;
                    } 
                }
            }
        
        rst[i] = 0;
        return 0;
    }
};