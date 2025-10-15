class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int curr = 1;
        int prev = 0;
        int K = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }
            else{
                prev = curr;
                curr = 1;
            }
            K = max(K,curr/2);
            K = max(K,min(curr,prev));
        }
        return K;
    }
};