class Solution {
public:
    const int m = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        long long result = 0;
        for(auto &num : nums){
            if(num%2==0){
                result = (result+mp2[num/2])%m;
            }
            mp2[num] = (mp2[num]+(mp1[num*2]))%m;
            mp1[num]++;
        }
        return result;
    }
};