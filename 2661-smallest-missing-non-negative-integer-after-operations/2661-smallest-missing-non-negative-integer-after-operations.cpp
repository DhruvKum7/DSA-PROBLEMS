class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto &i : nums){
            int ans = ((i%value)+value)%value;
            mp[ans]++;
        }
        int mex = 0;
        while(mp[mex%value]>0){
            mp[mex%value]--;

            mex++;
        }
        return mex;
    }
};