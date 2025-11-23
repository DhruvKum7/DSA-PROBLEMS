class Solution {
public:
    
    int solve(int i,int remainder , vector<int>& nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            if(remainder==0){
                return 0;
            }else{
                return INT_MIN;
            }
        }
        if(dp[i][remainder]!=-1){
            return dp[i][remainder];
        }
        int take = nums[i]+solve(i+1,(remainder+nums[i])%3,nums,dp);
        int skip = solve(i+1,remainder,nums,dp);

        return dp[i][remainder]=max(take,skip);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
};