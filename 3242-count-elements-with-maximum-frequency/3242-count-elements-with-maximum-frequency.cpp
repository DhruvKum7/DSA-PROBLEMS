class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mp(101, 0);
        int maxFreq = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] > maxFreq) {
                maxFreq = mp[nums[i]];
                count = maxFreq;
            } else if (mp[nums[i]] == maxFreq) {
                count += maxFreq;
            }
        }
        return count;
    }
};
