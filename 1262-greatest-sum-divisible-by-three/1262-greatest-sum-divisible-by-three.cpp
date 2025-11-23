class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,INT_MIN));
        dp[n][0]=0;
        dp[n][1]=INT_MIN;
        dp[n][2]=INT_MIN;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<3;j++){
                int newrem = (j+nums[i])%3;
                int take = nums[i]+dp[i+1][newrem];
                int skip = dp[i+1][j];

                dp[i][j]=max(take,skip);
            }
        }
        return dp[0][0];
    }
};