class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n==0 || m==0){
            return 0;
        }

        vector<vector<int>> t(n+1, vector<int>(m+1, 0));

        // Build DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // Reconstruct LCS string
        string result = "";
        int i = n, j = m;

        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                result.push_back(text1[i-1]);
                i--;
                j--;
            }
            else {
                if(t[i-1][j] > t[i][j-1])
                    i--;
                else
                    j--;
            }
        }

        reverse(result.begin(), result.end());

        // You want to return length of LCS
        return result.length();
    }
};
