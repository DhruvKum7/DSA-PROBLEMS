class Solution {
public:
    int solve(vector<vector<int>>& triangle , int i , int j,vector<vector<int>>&dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int take = 0;
        take=triangle[i][j]+solve(triangle,i+1,j,dp);
        int not_take = 0;
        not_take=triangle[i][j]+solve(triangle,i+1,j+1,dp);

        return dp[i][j]=min(take,not_take);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,INT_MAX));
        return solve(triangle , 0 , 0,dp);
    }
};