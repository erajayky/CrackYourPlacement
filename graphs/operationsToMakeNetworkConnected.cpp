class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        int ans = 0;
        vector<vector<int>> g(n);
        vector<int> vis(n, 0);

        for(auto i:connections){
            int a = i[0];
            int b = i[1];

            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(g, vis, i);
            }
        }

        return ans-1;
    }

    void dfs(vector<vector<int>> &g, vector<int> &vis, int i){
        vis[i] = 1;

        for(int x:g[i])
           if(!vis[x])
            dfs(g, vis, x);

    }
};