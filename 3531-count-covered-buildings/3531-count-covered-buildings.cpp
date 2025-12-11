class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row, col;

        // Group by row (x) and column (y)
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }

        // Sort coordinates in each row
        for (auto &it : row) {
            auto &v = it.second;
            sort(v.begin(), v.end());
        }

        // Sort coordinates in each column
        for (auto &it : col) {
            auto &v = it.second;
            sort(v.begin(), v.end());
        }

        int count = 0;

        // Check coverage for each building
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            auto &ys = row[x]; // all y in this row
            auto &xs = col[y]; // all x in this column

            if (xs.front() < x && x < xs.back() &&
                ys.front() < y && y < ys.back()) {
                count++;
            }
        }

        return count;
    }
};
