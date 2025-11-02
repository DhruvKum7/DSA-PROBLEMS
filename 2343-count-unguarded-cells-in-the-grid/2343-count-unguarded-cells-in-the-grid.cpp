 class Solution {
public:
    void solve(int row, int col, vector<vector<int>>& visited) {
        int m = visited.size();
        int n = visited[0].size();

        // up
        for (int i = row - 1; i >= 0; --i) {
            if (visited[i][col] == 3 || visited[i][col] == 2) break; // wall or guard blocks
            visited[i][col] = 1; // guarded
        }
        // down
        for (int i = row + 1; i < m; ++i) {
            if (visited[i][col] == 3 || visited[i][col] == 2) break;
            visited[i][col] = 1;
        }
        // left
        for (int j = col - 1; j >= 0; --j) {
            if (visited[row][j] == 3 || visited[row][j] == 2) break;
            visited[row][j] = 1;
        }
        // right
        for (int j = col + 1; j < n; ++j) {
            if (visited[row][j] == 3 || visited[row][j] == 2) break;
            visited[row][j] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0)); // 0 empty, 1 guarded, 2 guard, 3 wall

        for (auto &g : guards) {
            visited[g[0]][g[1]] = 2;
        }
        for (auto &w : walls) {
            visited[w[0]][w[1]] = 3;
        }

      
        for (auto &g : guards) {
            solve(g[0], g[1], visited);
        }

        long long count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == 0) ++count;
            }
        }
        return (int)count;
    }
 };
