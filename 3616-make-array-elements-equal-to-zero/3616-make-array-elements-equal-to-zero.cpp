class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int currsum = 0;
        int sum = 0;
        int result = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0){
                currsum+=nums[i];
            }
            else{
                int left = currsum;
                int right = sum-currsum;

                if(left==right){
                    result+=2;
                }
                else if(abs(left-right)==1){
                    result+=1;
                }
            }
        }
        return result;
    }
};