class Solution {
public:
    vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};
    
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<int>>& visited) {
        auto check = [&](int l, int m) {
            return l >= 0 && l < (int)heights.size() && m >= 0 && m < (int)heights[0].size() && !visited[l][m];
        };
        visited[i][j] = 1;
        for (auto &dir : directions) {
            int u = i + dir[0];
            int v = j + dir[1];
            if (check(u, v) && heights[u][v] >= heights[i][j]) {
                dfs(u, v, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> visited1(n, vector<int>(m, 0));
        vector<vector<int>> visited2(n, vector<int>(m, 0));
        vector<vector<int>> result;

        
        for (int j = 0; j < m; ++j) {
            dfs(0, j, heights, visited1);
            dfs(n - 1, j, heights, visited2);
        }
        
        for (int i = 0; i < n; ++i) {
            dfs(i, 0, heights, visited1);
            dfs(i, m - 1, heights, visited2);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited1[i][j] && visited2[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
