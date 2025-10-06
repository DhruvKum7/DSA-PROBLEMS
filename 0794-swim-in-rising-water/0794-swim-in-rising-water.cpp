class Solution {
public:
vector<vector<int>> directions{{0,1},{1,0},{-1,0},{0,-1}};

bool possible(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int mid){
    int n = grid.size();
    // out of bounds OR already visited OR cell value > mid → cannot proceed
    if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid){
        return false;
    }
    // reached destination
    if(i == n-1 && j == n-1) return true;

    visited[i][j] = true;

    for(auto &dir : directions){
        int u = i + dir[0];
        int v = j + dir[1];
        if(possible(grid, u, v, visited, mid)){
            return true;
        }
    }
    return false;
}

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int l = max(grid[0][0], grid[n-1][n-1]);
    int r = n*n - 1;
    int result = r;

    while(l <= r){
        int mid = l + (r - l) / 2;
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // reset per mid

        if(possible(grid, 0, 0, visited, mid)){
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}


};