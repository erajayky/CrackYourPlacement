class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ps[i + 1][j + 1] = (matrix[i][j] - '0') + ps[i + 1][j];
            }
        }
        
        int res = 0;
        
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i < j; i++) {
                int x = 0;
                for (int y = 1; y <= m; y++) {
                    int s = ps[y][j] - ps[y][i];
                    if (s == j - i) {
                        res = max(res, (y - x) * (j - i));
                    } else {
                        x = y;
                    }
                }
            }
        }
        
        return res;
    }
};
