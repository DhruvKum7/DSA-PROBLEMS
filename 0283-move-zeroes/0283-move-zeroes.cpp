class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        long long shift = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                int temp = nums[(int)shift];
                nums[(int)shift] = nums[i];
                nums[i]=temp;

                shift++;
            }
        }
    }
};