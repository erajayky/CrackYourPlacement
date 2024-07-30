class Solution 
{
public:
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N) {
	    int X[] = {1, 2, 1, 2, -1, -2, -1, -2};
	    int Y[] = {2, 1, -2, -1, 2, 1, -2, -1};
	    
	    int dp[N + 1][N + 1];
	    memset(dp, -1, sizeof dp);
	    
	    queue<pair<int, int>> que;
	    que.push({KnightPos[0], KnightPos[1]});
	    dp[KnightPos[0]][KnightPos[1]] = 0;
	    
	    while(!que.empty()) {
	        auto it = que.front(); que.pop();
	        int x = it.first, y = it.second;
	        
	        for(int i = 0; i < 8; i++) {
	            int nx = x + X[i];
	            int ny = y + Y[i];
	            
	            if(nx < 1 || nx > N || ny < 1 || ny > N || dp[nx][ny] != -1)
	                continue;
	               
	           dp[nx][ny] = 1 + dp[x][y];
	           que.push({nx, ny});
	           if(nx == TargetPos[0] && ny == TargetPos[1]) return dp[nx][ny];
	        }
	    }
	    
	    return dp[TargetPos[0]][TargetPos[1]];
	}
};