class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), ans;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i=0; i<min(m, k); i++){
            pq.push({matrix[i][0], i, 0});
        }

        for(int i=0; i<k; i++){
            vector<int> top = pq.top();
            pq.pop();
            ans = top[0];
            int r = top[1], c = top[2];

            if(c+1 < n) pq.push({matrix[r][c+1], r, c+1});
        }

        return ans;
    }
};