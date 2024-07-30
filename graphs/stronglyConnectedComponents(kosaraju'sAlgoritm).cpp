class Solution
{
	public:
	
    void toposort(stack<int> &st, vector<int> &vis, vector<vector<int>>& adj ,int src)
    {
        vis[src]=1;
        for(auto it: adj[src])
            if(!vis[it])
                toposort(st,vis,adj,it);

        st.push(src);
    }
    
    void revDfs(int node, vector<int> &vis,vector<int> transpose[])
    {
        vis[node]=1;
        for(auto it: transpose[node])
            if(!vis[it])
                revDfs(it,vis,transpose);
                
    }

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        int count=0;
        vector<int> transpose[V];
        
        for(int i=0;i<V;i++)
            if(vis[i]==false)
                toposort(st,vis,adj,i);
        
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i])
                transpose[it].push_back(i);
        }
        
        while(st.empty()==false){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                count++;
                revDfs(node,vis,transpose);
            }
            
        }
        return count;
    }
};