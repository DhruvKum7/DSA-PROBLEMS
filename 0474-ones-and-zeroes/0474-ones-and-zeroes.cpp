class Solution {
public:
    int t[101][101][601];  // include index 'i' for proper memoization

    int solve(vector<pair<int,int>>& result, int m, int n, int i) {
        if (i >= result.size() || m < 0 || n < 0) {
            return 0;
        }

        if (t[m][n][i] != -1) return t[m][n][i];

        int take = 0;
        int fir = result[i].first;
        int sec = result[i].second;

        // take
        if (fir <= m && sec <= n) {
            take = 1 + solve(result, m - fir, n - sec, i + 1);
        }

        // skip
        int skip = solve(result, m, n, i + 1);

        return t[m][n][i] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t, -1, sizeof(t));
        vector<pair<int,int>> result;

        for (auto &i : strs) {
            int onescount = 0, zerocounts = 0;
            for (auto &j : i) {
                if (j == '0') zerocounts++;
                else if (j == '1') onescount++;
            }
            result.push_back({zerocounts, onescount});
        }

        return solve(result, m, n, 0);
    }
};
