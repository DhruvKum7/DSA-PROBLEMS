class Solution {
public:
    int t[101];
    int solve(int i , int j , vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int take = 0;
        int skip = 0;
        take=nums[i]+solve(i+2,j,nums);
        skip=solve(i+1,j,nums);

         return t[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
       
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
         memset(t,-1,sizeof(t));
        int first_attempt = solve(0,n-2,nums);
         memset(t,-1,sizeof(t));
        int second_attempt = solve(1,n-1,nums);

        return max(first_attempt,second_attempt);
    }
};