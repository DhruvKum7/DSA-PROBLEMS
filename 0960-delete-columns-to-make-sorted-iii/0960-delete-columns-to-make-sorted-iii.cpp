class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = (int)strs.size();
        int m = (int)strs[0].size();

        vector<int> dp(m, 1);
        int best = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int r = 0; r < n; r++) {
                    if (strs[r][j] > strs[r][i]) { ok = false; break; }
                }
                if (ok) dp[i] = max(dp[i], dp[j] + 1);
            }
            best = max(best, dp[i]);
        }

        return m - best;
    }
};
