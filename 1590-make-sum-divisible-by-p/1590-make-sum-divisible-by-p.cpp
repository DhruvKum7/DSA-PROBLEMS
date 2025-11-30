class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for(auto &i : nums){
            sum = ((sum+i)%p);
        }
        int target = sum%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int>mp;
        mp[0]=-1;
        
        int result = nums.size();
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count = (count+(nums[i]%p))%p;
            int left = (count-target+p)%p;
            if(mp.find(left)!=mp.end()){
                result=min(result,abs(i-mp[left]));
            }
            mp[count]=i;
        }
        return result==nums.size()?-1:result;
    }
};