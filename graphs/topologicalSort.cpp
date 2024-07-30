{
	public:
	void dfs(stack<int> &st, vector<int> adj[], vector<bool> &vis,int i){
	   
	        vis[i] = true;
	        
	        for(auto j: adj[i]){
	            if(!vis[j])
	               dfs(st,adj,vis,j);
	        }
	        
	        st.push(i);
	}
	
	void reverse(vector<int> &ans, stack<int> st){
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{  
	   stack<int> st;
	   vector<bool> vis(V,false);
	   vector<int> ans;
	  
	   for(int i = 0;i<V;i++)
	        if(!vis[i])
	           dfs(st,adj,vis,i);
	   
	   
	   reverse(ans,st);
	   
	   return ans;
	}
};