class Solution {
  public:
  
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v, 0), restack(v, 0);
        
        for(int i=0; i<v; i++)
            if(!vis[i] && util(adj, vis, restack, i))
                return true;
        
        return false;
    }
    
    bool util(vector<int> adj[], vector<int> &vis, vector<int> &restack, int i){
        
        vis[i] = 1;
        restack[i] = 1;
        
        for(int x:adj[i]){
            if(!vis[x]){
                bool flag = util(adj, vis, restack, x);
                if(flag) return true;
            }
            else if(restack[x]) return true;
        }
        
        restack[i] = 0;
        
        return false;
    }
};