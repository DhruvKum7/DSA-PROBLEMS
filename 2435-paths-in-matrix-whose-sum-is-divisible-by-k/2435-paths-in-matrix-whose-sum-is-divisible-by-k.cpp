class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<vector<int>>> t;

    int solve(int x, int y, vector<vector<int>>& grid, int k, int sum) {
        int m = grid.size();
        int n = grid[0].size();

        int rem = sum % k;

        if (x == m-1 && y == n-1) {
            int finalSum = (sum + grid[x][y]) % k;
            return (finalSum == 0) ? 1 : 0;
        }

        if (t[x][y][rem] != -1)
            return t[x][y][rem];

        int ways = 0;

        if (x + 1 < m)
            ways = (ways + solve(x+1, y, grid, k, (sum + grid[x][y]) % k)) % mod;

        if (y + 1 < n)
            ways = (ways + solve(x, y+1, grid, k, (sum + grid[x][y]) % k)) % mod;

        return t[x][y][rem] = ways;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        t.assign(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0, 0, grid, k, 0);
    }
};
