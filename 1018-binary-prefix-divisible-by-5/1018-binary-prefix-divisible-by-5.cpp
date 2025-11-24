
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        vector<bool> result;
        
        for(int i = 0; i < n; i++) {
            cur = (cur * 2 + nums[i]) % 5; 
            result.push_back(cur == 0);
        }
        return result;
    }
};
