class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0;
       int last_index =  -(k+1);
       int n = nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]==1){
                if((i-last_index)>k){
                    last_index = i;
                }else{
                    return false;
                }
        }
       }
       return true;
    }
};