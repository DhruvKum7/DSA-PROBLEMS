class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        for(auto &i : nums){
            total+=i;
        }
        vector<int>vec(nums.size());
        int result = 0;
        vec[0]=nums[0];
        // if(nums.size()==0){
        //     return 0;
        // }
        for(int i=1;i<nums.size();i++){
            vec[i]=vec[i-1]+nums[i];
            int left = total-vec[i];
            if(abs(left-vec[i])%2==0){
                result++;
            }
        }
        return result;
    }
};