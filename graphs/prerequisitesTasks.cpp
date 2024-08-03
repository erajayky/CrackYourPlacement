class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> g(n);
        
        for(auto i: prerequisites)
            g[i.second].push_back(i.first);
        
        vector<bool> vis(n, false), restack(n, false);
        
        for(int i=0; i<n; i++)
            if(!vis[i] && isCycle(g, vis, restack, i))
               return false;
        
        return true;
	}
	
	bool isCycle(vector<vector<int>> &g, vector<bool> &vis, vector<bool> &restack, int i){
	    vis[i] = 1;
        restack[i] = 1;
        
        for(int x:g[i]){
            if(!vis[x] && isCycle(g, vis, restack, x)) return true;
            else if(restack[x]) return true;
        }
        
        restack[i] = 0;
        return false;
	}
};