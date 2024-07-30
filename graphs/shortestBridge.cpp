class Solution {
    queue<pair<int, int>> q;

public:
    int shortestBridge(vector<vector<int>>& grid) {
        bool flag = false;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !flag) {
                    dfs(grid, i, j);
                    q.push({i, j});
                    flag = true;
                    break;
                }
                if (flag)
                    break;
            }
        }

        return bfs(grid);
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0 || grid[i][j] == 2)
            return;

        grid[i][j] = 2;
        q.push({i, j});

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int bfs(vector<vector<int>>& grid) {
        int d = 0;
        int minDist = INT_MAX;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                auto a = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = dir[i][0] + a.first;
                    int y = dir[i][1] + a.second;

                    if (x >= 0 && x < grid.size() && y >= 0 &&
                        y < grid[0].size() && grid[x][y] == 1)
                        return d;

                    if (x >= 0 && x < grid.size() && y >= 0 &&
                        y < grid[0].size() && grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            d++;
        }
        return minDist;
    }
};