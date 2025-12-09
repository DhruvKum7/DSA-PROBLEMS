class Solution {
public:
    const int m = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto &i : nums){
            mp2[i]++;
        }
        long long count = 0;
    for(int i = 0;i<nums.size();i++){
        int new_i = 2*nums[i];
        mp2[nums[i]]--;
        if((mp1.find(new_i)!=mp1.end()) && (mp2.find(new_i)!=mp2.end())){
            count=(count+((1LL)*mp1[new_i]*mp2[new_i])%m)%m;
        }
        mp1[nums[i]]++;
    }
    return count;

    }
};