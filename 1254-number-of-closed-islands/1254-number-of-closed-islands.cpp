class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int n, m;

    void bfs(int i, int j, vector<vector<int>>& grid, bool &isClosed) {
        queue<pair<int,int>> que;
        que.push({i, j});
        grid[i][j] = 1;

        while (!que.empty()) {
            auto front = que.front();
            que.pop();

            int x = front.first;
            int y = front.second;

            if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                isClosed = false;
            }

            for (auto &dir : directions) {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == 0) {
                    grid[new_x][new_y] = 1;
                    que.push({new_x, new_y});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    bfs(i, j, grid, isClosed);
                    if (isClosed) count++;
                }
            }
        }
        return count;
    }
};
